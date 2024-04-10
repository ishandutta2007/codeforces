#include <bits/stdc++.h>
const int MaxN = 5e5 + 5;

int n, a[MaxN], ans[MaxN], size[MaxN], dep[MaxN], son[MaxN], T[1 << 22];
std::vector<int> G[MaxN];

int main()
{
	std::cin >> n;
	for(int i = 2, f; i <= n; ++i)
	{
		char c;
		std::cin >> f >> c;
		G[f].push_back(i);
		a[i] = (1 << int(c - 'a'));
	}
	
	auto dfs = [&](auto &&self, int u) -> void
	{
		size[u] = 1;
		for(int v : G[u])
		{
			a[v] ^= a[u];
			dep[v] = dep[u] + 1;
			self(self, v);
			size[u] += size[v];
			if(size[v] > size[son[u]]) son[u] = v;
		}
	};
	
	dep[1] = 1; dfs(dfs, 1);
	
	auto ins = [&](int u) {T[a[u]] = std::max(T[a[u]], dep[u]);};
	auto del = [&](int u) {T[a[u]] = 0;};
	
	auto apply = [&](auto &&self, auto &&func, int u) -> void
	{
		func(u);
		for(int v : G[u]) self(self, func, v);
	};
	
	auto solve = [&](auto &&self, int u) -> void
	{
		for(int v : G[u]) if(v != son[u]) self(self, v), apply(apply, del, v);
		
		auto chk = [&](int v)
		{
			if(T[a[v]]) ans[u] = std::max(ans[u], dep[v] + T[a[v]] - 2 * dep[u]);
			for(int i = 0; i < 22; ++i)
			if(T[a[v] ^ (1 << i)]) ans[u] = std::max(ans[u], dep[v] + T[a[v] ^ (1 << i)] - 2 * dep[u]);
		};
		
		if(son[u]) self(self, son[u]);
		chk(u); ins(u);
		
		for(int v : G[u]) if(v != son[u]) apply(apply, chk, v), apply(apply, ins, v);
		for(int v : G[u]) ans[u] = std::max(ans[u], ans[v]);
	};
	
	solve(solve, 1);
	for(int i = 1; i <= n; ++i) std::cout << ans[i] << " ";
	return 0;
}