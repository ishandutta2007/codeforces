#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n, h[MaxN];
std::vector<int> G[MaxN];
int main()
{
	std::cin >> n;
	for(int i = 1; i <= n; ++i) std::cin >> h[i];
	for(int i = 1, u, v; i < n; ++i)
	{
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int r = std::max_element(h + 1, h + n + 1) - h;
	ll ans = 0;
	
	auto dfs = [&](auto &&self, int u, int f) -> int
	{
		int mx1 = 0, mx2 = 0;
		for(int v : G[u]) if(v != f)
		{
			int x = self(self, v, u);
			if(x > mx1) std::swap(x, mx1);
			if(x > mx2) std::swap(x, mx2);
		}
		
		if(u == r) ans += std::max(0, h[u] - mx1) + std::max(0, h[u] - mx2);
		else ans += std::max(0, h[u] - mx1);
		return std::max(mx1, h[u]);
	};
	
	dfs(dfs, r, 0);
	std::cout << ans << "\n";
	return 0;
}