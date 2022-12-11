#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;

int n, m, d[MaxN], repr[MaxN], dep[MaxN], fa[MaxN][20], dfn[MaxN], size[MaxN];
std::vector<int> G[MaxN];
int find(int x) { return (repr[x] == x ? x : (repr[x] = find(repr[x]))); }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	std::iota(repr + 1, repr + n + 1, 1);
	
	std::vector<std::array<int, 2>> Q;
	for(int i = 1, u, v; i <= m; ++i)
	{
		std::cin >> u >> v;
		if(find(u) == find(v)) Q.push_back({ u, v });
		else
		{
			G[u].push_back(v);
			G[v].push_back(u);
			repr[find(u)] = find(v); 
		}
	}
	
	int dfs_clock = 0;
	auto dfs = [&](auto &&self, int u, int f) -> void
	{
		fa[u][0] = f; dep[u] = dep[f] + 1;
		dfn[u] = ++dfs_clock; size[u] = 1;
		for(int i = 1; i < 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for(int v : G[u]) if(v != f) self(self, v, u), size[u] += size[v];
	};
	
	dfs(dfs, 1, 0);
	
	auto lca = [&](int u, int v)
	{
		if(dep[u] < dep[v]) std::swap(u, v);
		for(int i = 20; i--; ) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
		if(u == v) return u;
		for(int i = 20; i--; ) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	};
	
	auto kfa = [&](int u, int k)
	{
		for(int i = 20; i--; ) if((k >> i) & 1) u = fa[u][i];
		return u;
	};
	
	auto add = [&](int l, int r, int v)	{ d[l] += v; d[r + 1] -= v; };
	for(const auto &e : Q)
	{
		int u = e[0], v = e[1], o = lca(u, v);
		
		if(o == u)
		{
			add(1, n, 1);
			int t = kfa(v, dep[v] - dep[u] - 1);
			add(dfn[t], dfn[t] + size[t] - 1, -1);
			add(dfn[v], dfn[v] + size[v] - 1, 1);
		}
		else if(o == v)
		{
			add(1, n, 1);
			int t = kfa(u, dep[u] - dep[v] - 1);
			add(dfn[t], dfn[t] + size[t] - 1, -1);
			add(dfn[u], dfn[u] + size[u] - 1, 1);
		}
		else
		{
			add(dfn[u], dfn[u] + size[u] - 1, 1);
			add(dfn[v], dfn[v] + size[v] - 1, 1);
		}
	}
	
	for(int i = 1; i <= n; ++i) d[i] += d[i - 1];
	for(int i = 1; i <= n; ++i) std::cout << (d[dfn[i]] == int(Q.size()) ? 1 : 0);
	return 0;
}