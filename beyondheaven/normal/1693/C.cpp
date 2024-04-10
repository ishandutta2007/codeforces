#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, m, deg[MaxN], dis[MaxN];
std::vector<int> G[MaxN];

int main()
{
	std::cin >> n >> m;
	for(int i = 1, u, v; i <= m; ++i)
	{
		std::cin >> u >> v;
		++deg[u]; G[v].push_back(u);
	}
	
	std::fill(dis + 1, dis + n + 1, m + 1);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
	q.emplace((dis[n] = 0), n);
	
	while(!q.empty())
	{
		int d, u; std::tie(d, u) = q.top(); q.pop();
		if(d != dis[u]) continue;
		for(int v : G[u])
		{
			int t = dis[u] + (--deg[v]) + 1;
			if(dis[v] > t) q.emplace((dis[v] = t), v); 
		}
	}
	
	std::cout << dis[1] << "\n";
	return 0;
}