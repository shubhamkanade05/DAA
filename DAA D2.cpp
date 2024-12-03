#include <bits/stdc++.h>

using namespace std;

string add_more_char(string str, int need)
{
	int pos = 0;

	string low_case = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < need; i++) {
		pos = rand() % str.length();
		str.insert(pos, 1, low_case[rand() % 26]);
	}
	return str;
}

string suggester(int l, int u, int d, int s, string str)
{

	string num = "0123456789";

	string low_case = "abcdefghijklmnopqrstuvwxyz";
	string up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string spl_char = "@#$_()!";

	int pos = 0;

	if (l == 0) {
		pos = rand() % str.length();

		str.insert(pos, 1, low_case[rand() % 26]);
	}

	if (u == 0) {
		pos = rand() % str.length();
		str.insert(pos, 1, up_case[rand() % 26]);
	}

	if (d == 0) {
		pos = rand() % str.length();
		str.insert(pos, 1, num[rand() % 10]);
	}

	if (s == 0) {
		pos = rand() % str.length();
		str.insert(pos, 1, spl_char[rand() % 7]);
	}

	return str;
}

void generate_password(int n, string p)
{
	int l = 0, u = 0, d = 0, s = 0, need = 0;


	string suggest;

	for (int i = 0; i < n; i++) {
		if (p[i] >= 97 && p[i] <= 122)
			l = 1;
		else if (p[i] >= 65 && p[i] <= 90)
			u = 1;
		else if (p[i] >= 48 && p[i] <= 57)
			d = 1;
		else
			s = 1;
	}

	if ((l + u + d + s) == 4) {
		cout << "Your Password is Strong" << endl;
		return;
	}
	else
		cout << "Suggested password " << endl;

	for (int i = 0; i < 10; i++) {
		suggest = suggester(l, u, d, s, p);
		need = 8 - suggest.length();
		if (need > 0)
			suggest = add_more_char(suggest, need);
		cout << suggest << endl;
	}
}

int main()
{
	string input_string = "geek@2018";
	srand(time(NULL));

	generate_password(input_string.length(), input_string);
	return 0;
}
