#include <bits/stdc++.h>
using namespace std;

const int N = 660000;
const int C = 20;

vector<int> con[N], adj[N];
int dp[N], low[N], cn, b[N], bn, T, art[N], c[N], anc[N][C], x[N], y[N], vis[N];

int get_anc(int u, int d) {
	for (int i = 0; i < C; i++) if (d>>i&1) u = anc[u][i];
	return u;
}

void dfs(int u, int pe) {
	vis[u] = low[u] = ++T;
	for (int e : adj[u]) {
		if (e == pe) continue;
		int v = x[e] ^ y[e] ^ u;
		if (!vis[v]) {
			b[bn++] = e;
			dfs(v, e);
			if (low[v] >= vis[u]) {
				cn++, art[u]++;
				while (bn > 0) {
					int g = b[--bn];
					c[g] = cn;
					if (g == e) break;
				}
			} else {
				low[u] = min(low[u], low[v]);
			}
		} else {
			if (vis[v] < vis[u]) low[u] = min(low[u], vis[v]), b[bn++] = e;
		}
	}
	if (!pe) art[u]--;
}

void dfs1(int u, int p) {
	anc[u][0] = p, dp[u] = dp[p] + 1;
	vis[u] = 1;
	for (int i = 1; i < 20; i++) anc[u][i] = anc[anc[u][i-1]][i-1];
	for (int v : con[u]) {
		if (v == p) continue;
		dfs1(v, u);
 	}
}

int lca(int u, int v) {
	if (dp[u] > dp[v]) swap(u, v);
	int d = dp[v] - dp[u];
	for (int i = 0; i < C; i++) if (d>>i&1) v = anc[v][i];
	if (u == v) return u;
	for (int i = C - 1; i >=0; i--) if (anc[v][i] != anc[u][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n, m, q; cin>>n>>m>>q;
	for (int i = 1; i <= m; i++) {
		cin>>x[i]>>y[i];
		adj[x[i]].push_back(i);
		adj[y[i]].push_back(i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), [&](int u, int v) {
			return c[u] < c[v];
		});
		int last = -1;
		for (int t : adj[i]) {
			if (last != -1 && last == c[t]) continue;
			last = c[t];
			con[i].push_back(n + c[t]);
			con[n+c[t]].push_back(i);
		}
	}
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= cn+n; i++) if (!vis[i]) dfs1(i, 0);
	while (q--) {
		int u, v; cin >> u >> v;
		cout << (dp[u] + dp[v] - 2 * dp[lca(u, v)]) / 2 << endl;
	}
	return 0;
}