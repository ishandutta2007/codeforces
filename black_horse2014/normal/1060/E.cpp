#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

vector<int> adj[N];
int sz[N], dp[N];
long long sum[N], ans[N];
int cnt[2];

void dfs(int u, int p) {
	sz[u] = 1;
	dp[u] = dp[p] + 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		ans[u] += ans[v] + sum[u] * sz[v] + 1LL * sz[u] * sz[v] + 1LL * sum[v] * sz[u];
		sum[u] += sum[v] + sz[v];
		sz[u] += sz[v];
	}
}

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) cnt[dp[i]&1]++;
	cout << (ans[1] + cnt[0] * 1LL * cnt[1]) / 2 << endl;
	return 0;
}