/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10;
int dp[(1 << N)][(1 << N)];
bool g[N][N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u][v] = true;
		g[v][u] = true;
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (i == 0) {
				dp[i][j] = (j == 0);
				continue;
			}
			if (j == 0 || ((i & j) != j)) {
				dp[i][j] = 0;
				continue;
			}
			int f = N, l = 0;
			for (int k = 0; k < n; k++) {
				if ((i >> k) & 1) {
					l = max(l, k);
					f = min(f, k);
				}
			}
			if (__builtin_popcount(i) == 2) {
				dp[i][j] = (__builtin_popcount(j) == 2 && g[f][l]);
			}
			int in = __builtin_ctz(j);
			for (int k = 0; k < n; k++) {
				if (g[k][in] && ((i >> k) & 1) && (((j >> k) & 1) == 0)) {
					dp[i][j] += dp[i - (1 << in)][j - (1 << in)];
					dp[i][j] += dp[i - (1 << in)][j - (1 << in) + (1 << k)];
				}
			}
			if (__builtin_popcount(i) == n && __builtin_popcount(j) == k)
				ans += dp[i][j];
		}
	}
	cout << ans;
}