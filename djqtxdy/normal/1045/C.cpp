#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const int M = 500005;
int head[N], to[M * 2], nxt[M * 2], eid;
void init_edge() {
	memset(head, -1, sizeof(head));
	eid = 0;
}
void add_edge(int u, int v) {
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}
int n, m;
int dfs_time, dfn[N], low[N], fa[N + M];
int stk[N], tp;
void tarjan(int u, int root) {
	dfn[u] = low[u] = ++dfs_time;
	stk[++tp] = u;
	if (u == root && !(~head[u])) {
		fa[++n] = u;
		return;
	}
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (!dfn[v]) {
			tarjan(v, root);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				int z;
				fa[++n] = u;
				do {
					z = stk[tp--];
					fa[z] = n;
				} while (z != v);
			}
		} else
			low[u] = min(low[u], dfn[v]);
	}
}
vector<int> G[N + M];
int pa[20][N + M], depth[N + M];
void dfs(int u, int D) {
	pa[0][u] = fa[u];
	depth[u] = D;
	for (int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		dfs(v, D + 1);
	}
}
int LCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = 0; i < 20; i++)
		if ((depth[u] - depth[v]) & (1 << i))
			u = pa[i][u];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (pa[i][u] != pa[i][v]) {
			u = pa[i][u];
			v = pa[i][v];
		}
	return pa[0][u];
}
int main() {
	int T;
	scanf("%d%d%d", &n, &m, &T);
	init_edge();
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		add_edge(b, a);
	}
	for (int i = 1, _ = n; i <= _; i++)
		if (!dfn[i])
			tarjan(i, i);
	for (int i = 1; i <= n; i++)
		if (fa[i] != 0)
			G[fa[i]].push_back(i);
	for (int i = 1; i <= n; i++)
		if (fa[i] == 0)
			dfs(i, 0);
	for (int i = 1; i < 20; i++)
		for (int u = 1; u <= n; u++)
			pa[i][u] = pa[i - 1][pa[i - 1][u]];
	while (T--) {
		int u, v;
		scanf("%d%d", &u, &v);
		int lca = LCA(u, v);
		printf("%d\n", (depth[u] - depth[lca] + depth[v] - depth[lca]) >> 1);
	}
	return 0;
}