/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int N = 201;

int dp[N][N][N];

void solve() {
	string s, t;
	int n, k;
	cin >> n >> k >> s >> t;
	if (t[0] == t[1]) {
		int cnt = 0;
		forn(i, n)
			if (s[i] == t[0])
				cnt++;
			else if (k > 0)
				cnt++, k--;
		cout << cnt * (cnt - 1) / 2 << "\n";
	} else {
		memset(dp, -1, sizeof(dp));
		dp[0][0][0] = 0;
		int ans = 0;
		forn(i, n + 1)
			forn(j, min(i, k) + 1)
				forn(a, i + 1) {
					int D = dp[i][j][a];
					if (D == -1) continue;
					// printf("dp[%d,%d,%d] = %d\n", i, j, a, D);
					auto relax = [](int &x, int y) { x = max(x, y); };
					if (i == n) {
						relax(ans, D);
						continue;
					}
					relax(dp[i + 1][j][a + (s[i] == t[0])], D + a * (s[i] == t[1]));
					relax(dp[i + 1][j + 1][a + 1], D);
					relax(dp[i + 1][j + 1][a], D + a);
				}
		cout << ans << "\n";
	}
}

int main() {
	int tn = 1;
	// cin >> tn;
	while (tn--)
		solve();
}