#include <bits/stdc++.h>
const int L = 2e6;

struct Edge
{
	int v, w, f, rev;
	Edge(int _v = 0, int _w = 0, int _f = 0):
		v(_v), w(_w), f(_f), rev(0) {}
};
std::vector<std::vector<Edge>> G;
std::vector<int> dis, h;
std::vector<Edge*> pre;

int Dijkstra(int s, int t)
{
	std::fill(dis.begin(), dis.end(), INT_MAX);
	dis[s] = 0;
	
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
		std::greater<std::pair<int, int>>> q;
	q.emplace(0, s);
	
	while(!q.empty())
	{
		int u, d; std::tie(d, u) = q.top(); q.pop();
		if(d != dis[u]) continue;
		for(auto &e : G[u]) if(e.w && dis[e.v] > d + h[u] + e.f - h[e.v])
		dis[e.v] = d + h[u] + e.f - h[e.v], pre[e.v] = &e, 
			q.emplace(dis[e.v], e.v);
	}
	return (dis[t] != INT_MAX);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k; std::cin >> n >> k;
	std::vector<int> a(1 << n);
	for(int i = 0; i < (1 << n); ++i) std::cin >> a[i];
	
	std::vector<std::tuple<int, int, int>> E;
	for(int i = 0; i < (1 << n); ++i) if(__builtin_popcount(i) & 1)
	{
		for(int j = 0; j < n; ++j)
		E.emplace_back(a[i] + a[i ^ (1 << j)], i, (i ^ (1 << j)));
	}
	
	int m = std::min(2 * n * k, (1 << (n - 1)) * n);
	std::nth_element(E.begin(), E.begin() + m - 1, E.end(),
		std::greater<std::tuple<int, int, int>>());
	
	int s = (1 << n), t = (1 << n) + 1;
	G.resize((1 << n) + 2);
	pre.resize((1 << n) + 2);
	dis.resize((1 << n) + 2);
	h.resize((1 << n) + 2);
	
	auto add_edge = [&](int u, int v, int w, int f)
	{
		G[u].emplace_back(v, w, f);
		G[v].emplace_back(u, 0, -f);
		G[u].back().rev = G[v].size() - 1;
		G[v].back().rev = G[u].size() - 1;
	};
	
	std::vector<int> vis(1 << n);
	for(int i = 0, u, v, w; i < m; ++i)
	{
		std::tie(w, u, v) = E[i];
		add_edge(u, v, 1, L - w);
		vis[u] = vis[v] = 1;
	}
	
	for(int i = 0; i < (1 << n); ++i) if(vis[i])
	{
		if(__builtin_popcount(i) & 1) add_edge(s, i, 1, 0);
		else add_edge(i, t, 1, 0);
	}
	
	int ans = 0;
	while(k-- && Dijkstra(s, t))
	{
		for(int i = t; i != s; i = G[i][pre[i] -> rev].v)
		--pre[i] -> w, ++G[i][pre[i] -> rev].w;
		for(int i = 0; i < (1 << n) + 2; ++i) h[i] += dis[i];
		ans += L - h[t];
	}
	
	printf("%d\n", ans);
	return 0;
}