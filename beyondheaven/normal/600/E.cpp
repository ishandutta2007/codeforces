#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;

int n, mx, a[MaxN], size[MaxN], son[MaxN], cnt[MaxN];
int64_t sum, ans[MaxN];
std::vector<int> G[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1, u, v; i < n; ++i)
	{
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	std::function<void(int, int)> dfs = [&](int u, int f)
	{
		size[u] = 1;
		for(int v : G[u]) if(v != f)
		{
			dfs(v, u);
			size[u] += size[v];
			if(size[v] > size[son[u]]) son[u] = v;
		}
	};
	
	dfs(1, 0);
	
	auto inc = [&](int x)
	{
		++cnt[x];
		if(cnt[x] > mx) mx = cnt[x], sum = x;
		else if(cnt[x] == mx) sum += x;
	};
	
	auto del = [&](int x) {--cnt[x];};
	
	std::function<void(std::function<void(int)>, int, int)> apply =
		[&](auto func, int u, int f)
	{
		func(a[u]);
		for(int v : G[u]) if(v != f) apply(func, v, u);
	};
	
	std::function<void(int, int)> solve = [&](int u, int f)
	{
		for(int v : G[u]) if(v != f && v != son[u]) solve(v, u), apply(del, v, u);
		mx = sum = 0;
		
		if(son[u]) solve(son[u], u);
		for(int v : G[u]) if(v != f && v != son[u]) apply(inc, v, u);
		inc(a[u]);
		ans[u] = sum;
	};
	
	solve(1, 0);
	for(int i = 1; i <= n; ++i) std::cout << ans[i] << " ";
	return 0;
}