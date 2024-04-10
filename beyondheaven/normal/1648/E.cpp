#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, m, size[MaxN], bel[MaxN], dep[MaxN], fa[MaxN][20], val[MaxN][20], ans[MaxN];
std::vector<std::array<int, 2>> G[MaxN];
std::vector<std::pair<std::list<int>, std::list<int>>> V[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> m;
		for(int i = 1; i <= n; ++i) G[i].clear(), V[i].clear();
		
		std::vector<std::array<int, 4>> E;
		std::set<std::pair<int, int>> S;
		for(int i = 1, a, b, c; i <= m; ++i)
		{
			std::cin >> a >> b >> c;
			E.push_back({c, a, b, i});
			S.emplace(a, b); S.emplace(b, a);
		}
		
		for(int i = 1; i <= n; ++i)
		{
			size[i] = 1;
			bel[i] = i;
			V[i].push_back({{i}, {}});
		}
		
		auto concat = [&](auto &a, auto &b) { a.splice(a.end(), b); };
		
		std::sort(E.begin(), E.end());
		for(auto e : E)
		{
			int u = bel[e[1]], v = bel[e[2]], w = e[0];
			if(u == v) continue;
			if(size[u] > size[v]) std::swap(u, v);
			
			size[v] += size[u];
			for(auto &p : V[u]) { auto &cur = p.first; for(int x : cur) bel[x] = v; }
			
			std::set<int> update_list;
			std::vector<std::list<int>> bad;
			
			auto &C = V[v];
			for(auto &p : V[u])
			{
				auto &cur = p.first;
				
				std::vector<int> cand;
				for(int i = 0; i < int(C.size()); ++i)
				{
					auto &other = C[i].first;
					
					for(int x : cur)
					for(int y : other)
					if(!S.count({x, y}))
					{
						G[x].push_back({y, w});
						G[y].push_back({x, w});
						cand.push_back(i);
						goto success;
					}
					
					success: ;
				}
				
				if(cand.size())
				{
					int i = cand[0];
					for(int j : cand) if(j != i)
					{	
						concat(C[i].first, C[j].first);
						concat(C[i].second, C[j].second);
					}
					
					concat(C[i].second, cur);
					update_list.insert(i);
					
					auto erase = [&](int j)
					{
						if(update_list.count(j)) update_list.erase(j);
												
						if(update_list.count(C.size() - 1))
						{
							update_list.erase(C.size() - 1);
							update_list.insert(j);
						}
						
						std::swap(C[j], C[C.size() - 1]);
						C.pop_back();
					};
					
					for(int t = cand.size() - 1; t > 0; --t) erase(cand[t]);
				}
				else bad.emplace_back(std::move(cur));
			}
			
			for(int i : update_list) concat(C[i].first, C[i].second);
			for(auto &cur : bad) C.emplace_back(std::move(cur), std::list<int>());
		}
		
		auto dfs = [&](auto &&self, int u, int f) -> void
		{
			for(auto e : G[u])
			{
				int v = e[0], w = e[1];
				if(v == f) continue;
				
				dep[v] = dep[u] + 1;
				fa[v][0] = u; val[v][0] = w;
				for(int i = 1; i < 20; ++i)
				{
					fa[v][i] = fa[fa[v][i - 1]][i - 1];
					val[v][i] = std::max(val[v][i - 1], val[fa[v][i - 1]][i - 1]);
				}
				
				self(self, v, u);
			}
		};
		
		dep[1] = 1; dfs(dfs, 1, 0);
		
		auto lca = [&](int u, int v)
		{
			if(dep[u] < dep[v]) std::swap(u, v);
			for(int i = 20; i--; ) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
			if(u == v) return u;
			for(int i = 20; i--; ) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
			return fa[u][0];
		};
		
		auto kfa = [&](int u, int k)
		{
			for(int i = 20; i--; ) if((k >> i) & 1) u = fa[u][i];
			return u;
		};
		
		auto path_max = [&](int u, int v)
		{
			if(u == v) return 0;
			int t = std::__lg(dep[v] - dep[u]);
			return std::max(val[v][t], val[kfa(v, dep[v] - dep[u] - (1 << t))][t]);
		};
		
		for(auto e : E)
		{
			int u = e[1], v = e[2], r = lca(u, v);
			ans[e[3]] = std::max(path_max(r, u), path_max(r, v));
		}
		
		for(int i = 1; i <= m; ++i) std::cout << ans[i] << " \n"[i == m];
	}
	return 0;
}