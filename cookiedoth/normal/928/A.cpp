#include <bits/stdc++.h>

using namespace std;

char lower(char &c) {
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
}

char make(char &c) {
	lower(c);
	if (c == '1' || c == 'i')
		c = 'l';
	if (c == '0')
		c = 'o';
}

bool similar(char a, char b) {
	//cout << "similar " << a << " " << b << endl;
	make(a);
	make(b);
	//cout << "maked " << a << " " << b << endl;
	if (a == b)
		return 1;
	else
		return 0;
}

bool similar(string a, string b) {
	//cout << a << " " << b << endl;
	if (a.size() != b.size())
		return 0;
	for (int i = 0; i < a.size(); ++i) {
		if (!similar(a[i], b[i]))
			return 0;
	}
	return 1;
}

int n;
vector<string> s;
string cur;

void input() {
	cin >> cur;
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
}

bool solve() {
	for (int i = 0; i < n; ++i) {
		if (similar(s[i], cur))
			return 1;
	}
	return 0;
}

int main() {
	input();
	if (solve())
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}