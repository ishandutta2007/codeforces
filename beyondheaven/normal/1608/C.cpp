#include <bits/stdc++.h>
int main()
{
	int T, n; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		std::vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		for(int i = 0; i < n; ++i) std::cin >> b[i];
		
		using Tuple = std::array<int, 3>;
		std::vector<Tuple> V;
		for(int i = 0; i < n; ++i) V.push_back({a[i], b[i], i});
		
		std::vector<std::vector<int>> G(n);
		
		std::sort(V.begin(), V.end(),
			[&](const Tuple &a, const Tuple &b)
			{
				return a[0] < b[0];
			});
		
		for(int i = 0; i + 1 < n; ++i) G[V[i][2]].push_back(V[i + 1][2]);
		
		std::sort(V.begin(), V.end(),
			[&](const Tuple &a, const Tuple &b)
			{
				return a[1] < b[1];
			});
			
		for(int i = 0; i + 1 < n; ++i) G[V[i][2]].push_back(V[i + 1][2]);
		
		std::vector<int> vis(n);
		
		auto dfs = [&](auto &&self, int u) -> void
		{
			vis[u] = 1;
			for(int v : G[u]) if(!vis[v]) self(self, v);
		};
		
		int t = (*std::max_element(V.begin(), V.end()))[2];
		dfs(dfs, t);
		
		for(int i = 0; i < n; ++i) std::cout << vis[i];
		std::cout << "\n";
	}
	return 0;
}