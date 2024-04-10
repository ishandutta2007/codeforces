#include <bits/stdc++.h>
int main()
{
	const int inf = 1e9;
	
	int n, m, a, b; std::cin >> n >> m >> a >> b;
	if(a > b) std::swap(a, b);
	if(a == b) ++b;
	
	std::vector<int> repr(n), size(n, 1);
	std::iota(repr.begin(), repr.end(), 0);
	
	auto find = [&](int x)
	{
		while(x != repr[x]) x = repr[x] = repr[repr[x]];
		return x;
	};
	
	std::vector<std::vector<int>> G(n), H(n);
	for(int i = 0, u, v, w; i < m; ++i)
	{
		std::cin >> u >> v >> w; --u; --v;
		if(w == a)
		{
			int x = find(u), y = find(v);
			if(x != y) repr[x] = y, size[y] += size[x];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		else
		{
			H[u].push_back(v);
			H[v].push_back(u);
		}
	}
	
	int k = 0, _k = 0;
	std::vector<int> col(n);
	for(int i = 0; i < n; ++i) if(find(i) == i)
	{
		int c = (size[i] >= 4 ? k++ : --_k);
		for(int j = 0; j < n; ++j) if(find(j) == i) col[j] = c;
	}
	
	std::vector<std::vector<int>> dis(n, std::vector<int>((1 << k), inf));
	std::priority_queue<std::tuple<int, int, int>,
		std::vector<std::tuple<int, int, int>>, std::greater<>> Q;
	
	auto push = [&](int u, int mask, int d) { dis[u][mask] = d; Q.emplace(d, u, mask); };
	push(0, (col[0] < 0 ? 0 : (1 << col[0])), 0);
	
	while(Q.size())
	{
		auto [d, u, mask] = Q.top(); Q.pop();
		for(int v : G[u]) if(dis[v][mask] > d + a) push(v, mask, d + a);
		for(int v : H[u])
		{
			if(col[v] < 0 && col[v] != col[u] && dis[v][mask] > d + b) push(v, mask, d + b);
			if(col[v] >= 0 && !((mask >> col[v]) & 1)
				&& dis[v][mask | (1 << col[v])] > d + b) push(v, (mask | (1 << col[v])), d + b);
		}
	}
	
	for(int i = 0; i < n; ++i) std::cout << *std::min_element(dis[i].begin(), dis[i].end()) << " ";
	return 0;
}