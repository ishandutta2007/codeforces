#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m; std::cin >> n >> m;
		std::vector<std::tuple<int, int, int>> E(m);
		std::vector<std::vector<int>> G(n);
		for(auto &[u, v, w] : E)
		{
			std::cin >> u >> v >> w; --u; --v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		std::vector<std::vector<int>> d(n, std::vector<int>(n, -1));
		std::queue<std::pair<int, int>> Q;
		
		d[0][n - 1] = 1, Q.emplace(0, n - 1);
		while(Q.size())
		{
			auto [u, v] = Q.front(); Q.pop();
			
			if(u == v)
			for(int t = 0; t < n; ++t)
			{
				if(d[t][v] == -1) d[t][v] = d[u][v] + 1, Q.emplace(t, v);
				if(d[u][t] == -1) d[u][t] = d[u][v] + 1, Q.emplace(u, t);
			}
			
			for(int t : G[u]) if(d[t][v] == -1) d[t][v] = d[u][v] + 1, Q.emplace(t, v);
			for(int t : G[v]) if(d[u][t] == -1) d[u][t] = d[u][v] + 1, Q.emplace(u, t);
		}
		
		ll ans = 1e18;
		for(auto [u, v, w] : E) ans = std::min(ans, ll(std::min(d[u][v], d[v][u])) * w);
		std::cout << ans << "\n";
	}
	return 0;
}