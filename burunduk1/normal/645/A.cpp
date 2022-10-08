/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

string read() {
	string s[2];
	cin >> s[0] >> s[1];
	string res = "", tmp = res + s[0][0] + s[0][1] + s[1][1] + s[1][0];
	for (char c : tmp)
		if (c != 'X')
			res += c;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string a = read(), b = read();
	//cout << a << " " << b << endl;
	forn(i, 4) {
		if (a == b) {
			puts("YES");
			return 0;
		}
		a = a.substr(1) + a[0];
	}
	puts("NO");
}