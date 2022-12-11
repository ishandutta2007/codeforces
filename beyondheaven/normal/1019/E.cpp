#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;
using data = std::pair<ll, ll>;

data operator + (const data &a, const data &b) { return { a.first + b.first, a.second + b.second }; }
data operator - (const data &a, const data &b) { return { a.first - b.first, a.second - b.second }; }
bool comp(const data &a, const data &b) { return a.second * b.first > b.second * a.first; }

std::vector<data> minkowski(std::vector<data> a, std::vector<data> b)
{
	for(int i = a.size() - 1; i >= 1; --i) a[i] = a[i] - a[i - 1];
	for(int i = b.size() - 1; i >= 1; --i) b[i] = b[i] - b[i - 1];
	
	std::vector<data> c(a.size() + b.size() - 1);
	c[0] = a[0] + b[0];
	
	std::merge(a.begin() + 1, a.end(), b.begin() + 1, b.end(), c.begin() + 1, comp);
	
	for(int i = 1; i < int(c.size()); ++i) c[i] = c[i] + c[i - 1];
	return c;
}

std::vector<data> convex_hull(std::vector<data> a)
{
	std::sort(a.begin(), a.end());
	
	std::vector<data> b;
	for(auto x : a)
	{
		while(!b.empty() && b.back().second <= x.second) b.pop_back();
		b.push_back(x);
	}
	
	std::vector<data> stk;
	for(auto x : b)
	{
		while(stk.size() >= 2 && !comp(stk.end()[-1] - stk.end()[-2], x - stk.end()[-2])) stk.pop_back();
		stk.push_back(x);
	}
	return stk;
}

int n, m, eid, used[MaxN], size[MaxN];
std::vector<std::array<int, 3>> G[MaxN];
std::vector<std::array<int, 4>> H[MaxN];

void add_edge(int u, int v, int a, int b)
{
	++eid;
	H[u].push_back({v, a, b, eid});
	H[v].push_back({u, a, b, eid});
}

void dfs(int u, int f)
{
	std::vector<std::array<int, 3>> son;
	for(auto e : G[u]) if(e[0] != f)
	{
		dfs(e[0], u);
		son.push_back(e);
		if(son.size() >= 3)
		{
			auto x = son.back(); son.pop_back();
			auto y = son.back(); son.pop_back();
			int z = ++n;
			add_edge(z, x[0], x[1], x[2]);
			add_edge(z, y[0], y[1], y[2]);
			son.push_back({z, 0, 0});
		}
	}
	
	for(auto e : son) add_edge(u, e[0], e[1], e[2]);
}

data dep[MaxN];
std::vector<data> all;

void solve(int r, int tot)
{
	if(tot == 1) return;
	
	int z = 0, best = tot, p = 0, q = 0; data len;
	auto dfs1 = [&](auto &&self, int u, int f) -> void
	{
		size[u] = 1;
		for(auto e : H[u]) if(!used[e[3]] && e[0] != f) 
		{
			self(self, e[0], u);
			size[u] += size[e[0]];
			if(std::max(size[e[0]], tot - size[e[0]]) < best)
			{
				best = std::max(size[e[0]], tot - size[e[0]]);
				z = e[3]; p = u; q = e[0];
				len = data{ e[1], e[2] };
			}
		}
	};
	
	dfs1(dfs1, r, 0);
	assert(z != 0);
	
	auto dfs2 = [&](auto &&self, int u, int f, std::vector<data> &V) -> void
	{
		V.push_back(dep[u]);
		for(auto e : H[u]) if(!used[e[3]] && e[0] != f)
		{
			dep[e[0]] = dep[u] + data{ e[1], e[2] };
			self(self, e[0], u, V);
		}
	};
	
	std::vector<data> L, R;
	dep[p] = data{ 0, 0 }; dfs2(dfs2, p, q, L);
	dep[q] = data{ 0, 0 }; dfs2(dfs2, q, p, R);
	
	L = convex_hull(L); R = convex_hull(R);
	for(auto x : minkowski(L, R)) all.push_back(x + len);
	
	used[z] = 1;
	solve(p, tot - size[q]), solve(q, size[q]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 1, u, v, a, b; i < n; ++i)
	{
		std::cin >> u >> v >> a >> b;
		G[u].push_back({v, a, b});
		G[v].push_back({u, a, b});
	}
	
	if(n == 1) { for(int t = 0; t < m; ++t) std::cout << 0 << " "; exit(0); }
	
	dfs(1, 0);
	solve(1, n);
	
	all = convex_hull(all);
	auto ternary_search = [&](int t)
	{
		auto f = [&](data a) { return a.first * t + a.second; };
		int l = -1, r = all.size();
		while(r - l >= 3)
		{
			int nl = (l + l + r) / 3, nr = (l + r + r) / 3;
			if(f(all[nl]) > f(all[nr])) r = nr;
			else l = nl;
		}
		return f(all[(l + r) / 2]);
	};
	
	for(int t = 0; t < m; ++t) std::cout << ternary_search(t) << " ";
	return 0;
}