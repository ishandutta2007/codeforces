#include <bits/stdc++.h>

const int MAXN = 51;
const int INF = 0x3f3f3f3f;
typedef long long LL;
int n, m, g[MAXN][MAXN], mi[MAXN], ma[MAXN];
bool can[MAXN][3];
LL dp[MAXN][MAXN];
int main() {
	std::cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 1, t1, t2, t3; i <= m; ++i) {
		std::cin >> t1 >> t2 >> t3;
		g[t1][t2] = g[t2][t1] = std::min(g[t1][t2], t3);
	}
	for (int i = 1; i <= n; ++i) g[i][i] = 0;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
	for (int i = 1; i <= n; ++i) {
		mi[i] = INF, ma[i] = -INF;
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				g[i][j] = g[i][j] * 51 + i;
				mi[i] = std::min(mi[i], g[i][j]);
				ma[i] = std::max(ma[i], g[i][j]);
			}
	}
	LL ans = 0;
	int l1, r1, l2, r2;
	std::cin >> l1 >> r1 >> l2 >> r2;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && mi[i] < ma[j]) {
				for (int k = 1; k <= n; ++k) {
					can[k][0] = mi[k] < mi[i];
					can[k][2] = ma[k] > ma[j];
					can[k][1] = false; // ...
					for (int l = 1; l <= n; ++l) if (l != k) {
						can[k][1] |=
							mi[i] < g[k][l] && g[k][l] < ma[j];
					}
				}
				can[i][0] = can[j][2] = true;
				can[i][1] = can[i][2] = can[j][0] = can[j][1] = false;
				memset(dp, 0, sizeof dp);
				dp[0][0] = 1;
				for (int k = 1; k <= n; ++k) {
					for (int l = k; ~l; --l)
						for (int p = k; ~p; --p) {
							if (can[k][0])
								dp[l + 1][p] += dp[l][p];
							if (can[k][1])
								dp[l][p + 1] += dp[l][p];
							dp[l][p] *= can[k][2];
						}
				}
				for (int k = l1; k <= r1; ++k)
					for (int l = l2; l <= r2; ++l)
						ans += dp[k][l];
			}
	std::cout << ans << std::endl;
	return 0;
}