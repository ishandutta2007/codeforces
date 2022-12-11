#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m; std::cin >> n >> m;
	ll p, q; std::cin >> p >> q;
	std::vector<std::string> mp(n);
	for(int i = 0; i < n; ++i) std::cin >> mp[i];
	
	std::vector<std::vector<std::pair<int, int>>> G(n * m + 2);
	int S = n * m, T = n * m + 1;
	auto id = [&](int i, int j) { return i * m + j; };
	auto legal = [&](int i, int j) { return (0 <= i && i < n) && (0 <= j && j < m) && mp[i][j] != '#'; };
	
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
	{
		if(mp[i][j] == '.') G[S].emplace_back(id(i, j), 0);
		else if(mp[i][j] == 'L')
		{
			if(legal(i, j + 2)) G[id(i, j + 2)].emplace_back(id(i, j), q);
			for(int z : { i + 1, i - 1 })
			if(legal(z, j + 1)) G[id(z, j + 1)].emplace_back(id(i, j), p);
		}
		else if(mp[i][j] == 'R')
		{
			if(legal(i, j - 2)) G[id(i, j - 2)].emplace_back(id(i, j), q);
			for(int z : { i + 1, i - 1 })
			if(legal(z, j - 1)) G[id(z, j - 1)].emplace_back(id(i, j), p);
		}
		else if(mp[i][j] == 'U')
		{
			if(legal(i + 2, j)) G[id(i + 2, j)].emplace_back(id(i, j), q);
			for(int z : { j + 1, j - 1 })
			if(legal(i + 1, z)) G[id(i + 1, z)].emplace_back(id(i, j), p); 
		}
		else if(mp[i][j] == 'D')
		{
			if(legal(i - 2, j)) G[id(i - 2, j)].emplace_back(id(i, j), q);
			for(int z : { j + 1, j - 1 })
			if(legal(i - 1, z)) G[id(i - 1, z)].emplace_back(id(i, j), p); 
		}
	}
	
	std::vector<ll> dis(n * m + 2, ll(1e18));
	std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> Q;
	Q.emplace((dis[S] = 0), S);
	
	while(Q.size())
	{
		auto [d, u] = Q.top(); Q.pop();
		if(d != dis[u]) continue;
		for(auto [v, w] : G[u]) if(dis[v] > d + w) Q.emplace((dis[v] = d + w), v);
	}
	
	ll ans = 1e18;
	
	for(int i = 0; i < n; ++i)
	for(int j = 0; j + 1 < m; ++j)
	if(mp[i][j] != '#' && mp[i][j + 1] != '#')
	ans = std::min(ans, dis[id(i, j)] + dis[id(i, j + 1)]);
	
	for(int i = 0; i + 1 < n; ++i)
	for(int j = 0; j < m; ++j)
	if(mp[i][j] != '#' && mp[i + 1][j] != '#')
	ans = std::min(ans, dis[id(i, j)] + dis[id(i + 1, j)]);
	
	std::cout << (ans == ll(1e18) ? -1 : ans) << "\n";
	return 0;
}