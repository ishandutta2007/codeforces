/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

string solve() {
	int x, k = 9;
	cin >> x;
	string s;
	if (x > 45)
		return "-1";
	while (x > 0)
		s += (char)('0' + min(x, k)), x -= k, k--;
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		cout << solve() << "\n";
}