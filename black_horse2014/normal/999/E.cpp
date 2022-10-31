#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
vector<int> adj[maxn], radj[maxn];
int qh, qt, q[maxn];
bool vis[maxn];
void dfs1(int u)
{
	vis[u] = 1;
	for (int v : adj[u]) if (!vis[v]) dfs1(v);
	q[qt++] = u;
}
int g[maxn], gn;
set<int> gadj[maxn];
void dfs2(int u)
{
	vis[u] = 1;
	g[u] = gn;
	for (int v : radj[u]) if (!vis[v]) dfs2(v);
}
int main()
{
//	freopen("data/1.in", "r", stdin);
//	freopen("data/1.out", "w", stdout);
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s), --s;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i);
	memset(vis, 0, sizeof(vis));
	for (int i = n - 1; i >= 0; --i) if (!vis[q[i]]) dfs2(q[i]), ++gn;
	for (int u = 0; u < n; ++u) for (int v : adj[u]) if (g[u] != g[v])
		gadj[g[v]].insert(g[u]);
	int ans = 0;
	for (int i = 0; i < gn; ++i) if (gadj[i].empty()) ++ans;
	if (gadj[g[s]].empty()) --ans;
	printf("%d\n", ans);
	return 0;
}