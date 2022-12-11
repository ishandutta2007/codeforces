#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;

int n, dep[MaxN];
std::vector<int> G[MaxN];

int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 1, u, v; i < n; ++i)
		{
			std::cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		auto dfs = [&](auto &&self, int u, int f) -> void
		{
			dep[u] = dep[f] + 1;
			for(int v : G[u]) if(v != f) self(self, v, u);
		};
		
		dfs(dfs, 1, 0);
		for(int i = 1; i <= n; ++i)
		std::cout << (dep[i] % 2 ? 1 : -1) * int(G[i].size()) << " \n"[i == n];
	}
	return 0;
}