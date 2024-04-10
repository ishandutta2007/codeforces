#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> b(n + 1), cnt(n + 2);
		for(int i = 1; i <= n; ++i) std::cin >> b[i], cnt[b[i]] += 1;
		
		int k = -1, pre = cnt[n + 1];
		for(int i = n; i >= 0; --i)
		{
			if(pre == i) { k = i; break; }
			pre += cnt[i];
		}
		assert(k != -1);
		
		std::vector<std::vector<int>> G(n + 2);
		for(int i = 1; i <= n; ++i) G[b[i]].push_back(i);
		
		auto dfs = [&](auto self, int u) -> void
		{
			if(u != 0 && u != n + 1) std::cout << u << " ";
			std::sort(G[u].begin(), G[u].end(),
				[&](int i, int j) { return G[i].size() < G[j].size(); });
			for(int v : G[u]) self(self, v);
		};
		
		std::cout << k << "\n";
		dfs(dfs, 0); dfs(dfs, n + 1);
		std::cout << "\n";
	}
	return 0;
}