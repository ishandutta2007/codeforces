#include <bits/stdc++.h>
const int MaxN = 5e5 + 500 + 5;

std::vector<std::pair<int, int>> G[MaxN];
int64_t dis[MaxN];

int64_t Dijkstra(int s, int t)
{
	std::fill(dis, dis + t + 2, (int64_t(1) << 60));
	dis[s] = 0;
	
	using T = std::pair<int64_t, int>;
	std::priority_queue<T, std::vector<T>, std::greater<T>> q;
	
	q.emplace(dis[s], s);
	while(!q.empty())
	{
		int u; int64_t d; std::tie(d, u) = q.top(); q.pop();
		if(d != dis[u]) continue;
		
		for(const auto &e : G[u]) if(dis[e.first] > dis[u] + e.second)
		q.emplace((dis[e.first] = dis[u] + e.second), e.first);
	}
	return dis[t];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, cnt = 0; std::cin >> n;
		for(int i = 0; i <= n * n * 8 + 5; ++i) G[i].clear();
		
		auto add_edge = [&](int u, int v, int w) {G[u].emplace_back(v, w);};
		
		int64_t add = 0;
		
		std::vector<std::vector<int>> In(2 * n + 1, std::vector<int>(2 * n + 1)), Out = In;
		for(int i = 1; i <= 2 * n; ++i)
		for(int j = 1, c; j <= 2 * n; ++j)
		{
			std::cin >> c;
			if((i <= n && j <= n) || (i > n && j > n)) add += c, c = 0;
			In[i][j] = ++cnt; Out[i][j] = ++cnt;
			add_edge(In[i][j], Out[i][j], c);
		}
		
		int s = ++cnt, t = ++cnt;
		for(int i = 1; i <= 2 * n; ++i)
		for(int j = 1; j <= 2 * n; ++j)
		{
			if(i <= n && j <= n) add_edge(s, In[i][j], 0);
			if(i > n && j > n) continue;
			add_edge(Out[i][j], In[i % (2 * n) + 1][j], 0);
			add_edge(Out[i][j], In[i][j % (2 * n) + 1], 0);
			add_edge(Out[i][j], In[(i == 1 ? 2 * n : i - 1)][j], 0);
			add_edge(Out[i][j], In[i][(j == 1 ? 2 * n : j - 1)], 0);
		}
		
		for(int x : {n + 1, 2 * n}) for(int y : {n + 1, 2 * n}) add_edge(Out[x][y], t, 0);
		
		std::cout << add + Dijkstra(s, t) << "\n";
	}
	return 0;
}