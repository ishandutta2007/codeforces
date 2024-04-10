/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int n;
	string s, t[2];
	cin >> n >> s;
	forn(i, 2) {
		t[i] = s;
		int x = i;
		forn(j, n) {
			if (s[j] != '?')
				x = s[j] == 'R';
			t[i][j] = "BR"[x], x ^= 1;
		}
	}
	auto f = [&](string &s) {
		int cnt = 0;
		forn(i, n - 1)
			cnt += (s[i] == s[i + 1]);
		return cnt;
	};
	cout << (f(t[0]) < f(t[1]) ? t[0] : t[1]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) 
		solve();
}