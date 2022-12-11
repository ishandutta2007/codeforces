#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, q, c[MaxN * 2], buc[MaxN];
std::vector<int> G[MaxN];
void add(int x, int v) { for(; x <= 2 * n; x += (x & -x)) c[x] += v; }
int sum(int x) { int v = 0; for(; x; x -= (x & -x)) v += c[x]; return v; }

int in[MaxN], out[MaxN], ST[20][MaxN * 2];
int dep[MaxN], fa[MaxN][20];
void dfs(int u, int f)
{
	static int ind = 0;
	ST[0][++ind] = u; in[u] = out[u] = ind;
	fa[u][0] = f;
	for(int i = 1; i < 20; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int v : G[u]) if(v != f)
	{
		dep[v] = dep[u] + 1, dfs(v, u);
		ST[0][++ind] = u; out[u] = ind;
	}
}

int gmin(int u, int v) { return (dep[u] < dep[v] ? u : v); }
int qmin(int l, int r)
{
	int t = std::__lg(r - l + 1);
	return gmin(ST[t][l], ST[t][r - (1 << t) + 1]);
}

int lca(int u, int v)
{
	if(in[u] > in[v]) std::swap(u, v);
	return qmin(in[u], in[v]);
}

int dis(int u, int v)
{
	if(u == 0 || v == 0) return -1;
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

#define mid ((l + r) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

using info = std::tuple<int, int, int>;
info operator + (const info &a, const info &b)
{
	info c = std::max(a, b);
	auto [_a, au, av] = a;
	auto [_b, bu, bv] = b;
	for(int u : { au, av }) for(int v : { bu, bv })
	c = std::max(c, { dis(u, v), u, v });
	return c;
}

info t[MaxN * 2 * 4];
void modify(int p, const info &v, int k = 1, int l = 1, int r = 2 * n)
{
	if(l == r) return t[k] = v, void();
	(p <= mid ? modify(p, v, ls, l, mid) : modify(p, v, rs, mid + 1, r));
	t[k] = t[ls] + t[rs];
}

info query(int ql, int qr, int k = 1, int l = 1, int r = 2 * n)
{
	if(ql <= l && r <= qr) return t[k];
	if(ql <= mid && mid < qr) return query(ql, qr, ls, l, mid) + query(ql, qr, rs, mid + 1, r);
	return (ql <= mid ? query(ql, qr, ls, l, mid) : query(ql, qr, rs, mid + 1, r));
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> q;
	for(int i = 1, u, v; i < n; ++i)
	{
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	
	for(int j = 1; j < 20; ++j)
	for(int i = 1; i + (1 << j) - 1 <= 2 * n; ++i)
	ST[j][i] = gmin(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
	
	auto kfa = [&](int u, int k)
	{
		k = std::min(k, dep[u]);
		for(int i = 20; i--; ) if((k >> i) & 1) u = fa[u][i];
		return u;
	};
	
	auto cmp = [&](int u, int v) { return std::tie(dep[u], u) < std::tie(dep[v], v); };
	std::set<int, decltype(cmp)> S(cmp);
	
	std::fill(t + 1, t + 2 * n * 4 + 1, info { -1, 0, 0 });
	for(int _ = 1, opt, u, v, d, cnt = 0; _ <= q; ++_)
	{
		std::cin >> opt;
		if(opt == 1)
		{
			cnt += 1;
			std::cin >> u >> v;
			int w = lca(u, v);
			if(++buc[w] == 1) S.insert(w), modify(in[w], { 0, w, w });
			add(in[u], 1); add(in[v], 1); add(in[w], -1);
		}
		else if(opt == 2)
		{
			cnt -= 1;
			std::cin >> u >> v;
			int w = lca(u, v);
			if(--buc[w] == 0) S.erase(w), modify(in[w], { -1, 0, 0 });
			add(in[u], -1); add(in[v], -1); add(in[w], 1);
		}
		else
		{
			std::cin >> d;
			u = kfa(*std::prev(S.end()), d); v = kfa(u, d);
			if(sum(out[v]) - sum(in[v] - 1) != cnt) { std::cout << "No" << "\n"; continue; }
			auto [_, x, y] = query(in[v], out[v]);
			std::cout << ((dis(u, x) <= d && dis(u, y) <= d) ? "Yes" : "No") << "\n";
		}
	}
	return 0;
}