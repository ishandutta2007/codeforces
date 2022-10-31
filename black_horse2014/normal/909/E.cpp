#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int q[N], qn, deg[N], vis[N], e[N], dp[N];
vector<int> adj[N], radj[N];
void dfs(int u) {
	vis[u] = 1;
	q[qn++] = u;
	for (int v : adj[u]) if (!(--deg[v]) && !vis[v]) dfs(v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> e[i];
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[v].push_back(u);
		radj[u].push_back(v);
		deg[u]++;
	}
 	for (int i = 0; i < n; i++) if (!deg[i] && !vis[i]) dfs(i);
	int dap = 0;
 	for (int i = 0; i < qn; i++) {
 		int u = q[i];
		dp[u] = e[u];
		for (int v : radj[u]) dp[u] = max(dp[u], dp[v] + (e[v] < e[u]));
		dap = max(dap, dp[u]);
	}
	cout << dap << endl;
	return 0;
}