#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
int a[22][11000];
int dp[1 << 16][16][16], d[16][16];

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			d[i][j] = INF;
			for (int k = 0; k < m; k++) d[i][j] = min(d[i][j], abs(a[i][k] - a[j][k]));
		}
	for (int s = 0; s < (1 << n); s++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) {
				if (!(s >> i & 1)) continue;
				if (!(s >> j & 1)) continue;
				if (i == j) {
					if (s == (1 << i)) dp[s][i][j] = INF;
					else continue;
				}
				else {
					dp[s][i][j] = 0;
					for (int k = 0; k < n; k++) {
						if (!(s >> k & 1)) continue;
						if (k == j) continue;
						dp[s][i][j] = max(dp[s][i][j], min(dp[s - (1 << j)][i][k], d[k][j]));
					}
				}
			}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (n > 1 && i == j) continue;
			int cur = dp[(1 << n) - 1][i][j];
			for (int k = 0; k < m - 1; k++) cur = min(cur, abs(a[j][k] - a[i][k + 1]));
			ans = max(ans, cur);
		}
	cout << ans << endl;
	return 0;
}