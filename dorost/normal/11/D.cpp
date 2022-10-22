/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 19;
long long dp[1 << N][N];
bool g[N][N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u][v] = true;
		g[v][u] = true;
	}
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			int s = __builtin_ctz(i), e = j;
			if (s == e) {
				if (!(i ^ (1 << s)))
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			} else {
				for (int k = 0; k < n; k++) {
					if (g[k][e] && ((i >> k) & 1)) {
						dp[i][j] += dp[i ^ (1 << e)][k];
					}
				}
			}
			if (g[s][e] && (i >> e & 1)) {
				ans += dp[i][j];
			}
		}
	}
	cout << (ans - m) / 2;
}