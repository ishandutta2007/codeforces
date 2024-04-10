#include <bits/stdc++.h>

const int MAXN = 200010;
const int MAXM = 600010;
typedef long long LL;
int head[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot;
void addedge(int b, int e, int v = 0) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
LL dis[MAXN];
int n, m, S;
typedef std::pair<LL, int> pi;
bool vis[MAXN];
void artskjid() {
	std::priority_queue<pi> q;
	memset(dis, 0x3f, n + 1 << 3); dis[S] = 0;
	memset(vis, 0, n + 1);
	q.emplace(0, S);
	while (!q.empty()) {
		int t = q.top().second; q.pop();
		if (vis[t]) continue; vis[t] = true;
		for (int i = head[t]; i; i = nxt[i])
			if (dis[to[i]] > dis[t] + val[i])
				q.emplace(-(dis[to[i]] = dis[t] + val[i]), to[i]);
	}
}
int fa[19][MAXN], dep[MAXN], *dom = fa[0];
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int t = dep[x] - dep[y]; t; t &= t - 1)
		x = fa[__builtin_ctz(t)][x];
	for (int i = 18; ~i; --i)
		if (fa[i][x] != fa[i][y])
			x = fa[i][x], y = fa[i][y];
	return x == y ? x : fa[0][x];
}
int siz[MAXN], bfn[MAXN], idx, ind[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> S;
	for (int i = 1, u, v, w; i <= m; ++i)
		std::cin >> u >> v >> w, addedge(u, v, w);
	artskjid();
	std::vector<std::pair<int, int> > vs;
	for (int u = 1; u <= n; ++u)
		for (int i = head[u]; i; i = nxt[i])
			if (dis[to[i]] == dis[u] + val[i])
				vs.emplace_back(u, to[i]);
	memset(head, 0, n + 1 << 2); tot = 1;
	for (auto t : vs)
		addedge(t.first, t.second), ++ind[t.second];
	std::queue<int> q; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = nxt[i]) if (i & 1) {
			if (!dom[u]) dom[u] = to[i];
			else dom[u] = LCA(dom[u], to[i]);
		}
		dep[u] = dep[dom[u]] + 1; siz[u] = 1;
		bfn[++idx] = u;
		for (int i = 1; i != 19; ++i)
			fa[i][u] = fa[i - 1][fa[i - 1][u]];
		// std::cout << "dom " << u << ' ' << dom[u] << std::endl;
		for (int i = head[u]; i; i = nxt[i]) if (~i & 1)
			if (!--ind[to[i]]) q.push(to[i]);
	}
	for (int i = idx; i > 1; --i) {
		const int u = bfn[i];
		siz[dom[u]] += siz[u];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) if (i != S) ans = std::max(ans, siz[i]);
	std::cout << ans << std::endl;
	return 0;
}