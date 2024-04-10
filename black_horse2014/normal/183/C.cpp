#include <bits/stdc++.h>
using namespace std;

const int MAXN = 111111;

typedef pair<int, int> PII;

vector<PII> adj[MAXN];
int vis[MAXN], dp[MAXN];
int ans;

void dfs(int u, int d) {
	dp[u] = d, vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (vis[v]) {
			if (w + d != dp[v]) ans = __gcd(ans, abs(w + d - dp[v]));
		} else {
			dfs(v, d + w);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(PII(v, 1));
		adj[v].push_back(PII(u, -1));
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
	if (!ans) ans = n;
	cout << ans << endl;
	return 0;
}