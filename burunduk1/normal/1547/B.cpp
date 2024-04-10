/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

bool solve() {
	string s;
	cin >> s;
	int n = s.size(), l = 0, r = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[r] == 'a' + i) 
			r--;
		else if (s[l] == 'a' + i)
			l++;
		else
			return 0;
	}
	return 1;
}
int main() {
	int tn;
	cin >> tn;
	while (tn--) cout << (solve() ? "YES\n" : "NO\n");
}