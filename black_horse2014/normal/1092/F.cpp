#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

long long a[N], sum[N], dp[N], dp1[N];
vector<int> adj[N];

void dfs(int u, int p) {
	sum[u] = a[u];
	dp[u] = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		sum[u] += sum[v];
		dp[u] += dp[v];
		dp[u] += sum[v];
	}
}

void dfs1(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dp1[v] = dp1[u] + dp[u] - dp[v] + (sum[1] - sum[v] - sum[v]);
		dfs1(v, u);
	}
}

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, 0);
	dfs1(1, 0);
	long long dap = 0;
	for (int i = 1; i <= n; i++) dap = max(dap, dp[i] + dp1[i]);
	cout << dap << endl;
	return 0;
}