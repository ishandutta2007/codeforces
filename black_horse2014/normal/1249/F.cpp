#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const int K = 220;

int dp[N][K];
int a[N];
int f[K], g[K];
vector<int> adj[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	m++;
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int v : adj[u]) {
			if (v == p) continue;
			dfs(v, u);
		}
		for (int i = 0; i <= m; i++) {
			f[i] = 0;
		}
		f[0] = a[u];
		for (int v : adj[u]) {
			if (v == p) continue;
			for (int i = 0; i <= m; i++) {
				g[i] = f[i];
				f[i] = 0;
			}
			for (int i = 0; i <= m; i++) {
				for (int j = m - i - 1; j <= m; j++) {
					f[min(i, j + 1)] = max(f[min(i, j + 1)], g[i] + dp[v][j]);
				}
			}
		}
		for (int i = 0; i <= m; i++) {
			dp[u][i] = f[i];
		}
		for (int i = m - 1; i >= 0; i--) {
			dp[u][i] = max(dp[u][i], dp[u][i + 1]);
		}
	};
	dfs(1, 0);
	cout << dp[1][0] << "\n";
	return 0;
}