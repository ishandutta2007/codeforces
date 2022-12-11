#include <bits/stdc++.h>
const int MaxN = 6e5 + 5;

int n, m, repr[MaxN], fa[MaxN][20], a[MaxN], dfn[MaxN], dep[MaxN];
std::vector<int> G[MaxN];
int find(int x) { return (repr[x] == x ? x : (repr[x] = find(repr[x]))); }

#define Mid ((L + R) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

int gmin(int x, int y)
{
	if(x == 0 || y == 0) return x + y;
	return (dfn[x] < dfn[y] ? x : y);
}

int gmax(int x, int y)
{
	if(x == 0 || y == 0) return x + y;
	return (dfn[x] > dfn[y] ? x : y);
}

int setv[MaxN * 4], f[MaxN * 4], g[MaxN * 4], nf[MaxN * 4], ng[MaxN * 4];
void build(int k, int L, int R)
{
	setv[k] = -1;	
	if(L == R) return f[k] = g[k] = L, void();
	build(ls, L, Mid); build(rs, Mid + 1, R);
	f[k] = gmin(f[ls], f[rs]);
	g[k] = gmax(g[ls], g[rs]);
}

void apply(int k, int v)
{
	setv[k] = v;
	if(v) nf[k] = f[k], ng[k] = g[k];
	else nf[k] = ng[k] = 0;
}

void pushdown(int k)
{
	if(setv[k] != -1)
	{
		apply(ls, setv[k]);
		apply(rs, setv[k]);
		setv[k] = -1;
	}
}

void modify(int l, int r, int v, int k = 1, int L = 1, int R = n)
{
	if(l <= L && R <= r) return apply(k, v);
	pushdown(k);
	if(l <= Mid) modify(l, r, v, ls, L, Mid);
	if(Mid < r) modify(l, r, v, rs, Mid + 1, R);
	nf[k] = gmin(nf[ls], nf[rs]);
	ng[k] = gmax(ng[ls], ng[rs]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	std::iota(repr + 1, repr + n + 1, 1);
	
	std::vector<std::array<int, 3>> E;
	for(int i = 1, u, v, w; i < n; ++i)
	{
		std::cin >> u >> v >> w;
		E.push_back({w, u, v});
	}
	
	std::sort(E.begin(), E.end());
	int t = n;
	std::fill(a + 1, a + n + 1, -1);
	
	for(const auto &e : E)
	{
		int x = find(e[1]), y = find(e[2]), z = ++t;
		G[z].push_back(x); G[z].push_back(y);
		a[z] = e[0]; repr[x] = repr[y] = repr[z] = z;
	}
	
	int dfs_clock = 0;
	auto dfs = [&](auto &&self, int u, int f) -> void
	{
		dfn[u] = ++dfs_clock; dep[u] = dep[f] + 1; fa[u][0] = f;
		for(int i = 1; i < 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for(int v : G[u]) self(self, v, u);
	};
	dfs(dfs, t, 0);
	
	auto lca = [&](int u, int v)
	{
		if(dep[u] < dep[v]) std::swap(u, v);
		for(int i = 20; i--; ) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
		if(u == v) return u;
		for(int i = 20; i--; ) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
		return fa[u][0]; 
	};
	
	build(1, 1, n);
	for(int i = 1, opt, x, y; i <= m; ++i)
	{
		std::cin >> opt;
		if(opt == 1) std::cin >> x >> y, modify(x, y, 1);
		if(opt == 2) std::cin >> x >> y, modify(x, y, 0);
		if(opt == 3)
		{
			std::cin >> x;
			std::cout << a[lca(gmin(nf[1], x), gmax(ng[1], x))] << "\n";
		} 
	}
	return 0;
}