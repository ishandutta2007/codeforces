/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 2000;

bitset<N> a[N], pref[N + 1], suf[N + 1], all;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int h, w;
	cin >> h >> w;
	string s;
	forn(i, h) {
		cin >> s;
		forn(j, w)
			a[i][j] = (s[j] == '1');
	}
	forn(j, w)
		all[j] = 1;
	forn(i, h)
		pref[i + 1] = pref[i] | a[i];
	for (int i = h - 1; i >= 0; i--)
		suf[i] = suf[i + 1] | a[i];
	forn(i, h) 
		if ((pref[i] | suf[i + 1]) == all) {
			puts("YES");
			return 0;
		}
	puts("NO");
}