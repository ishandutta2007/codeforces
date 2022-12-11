#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		std::vector<std::vector<int>> G(n);
		for(int i = 1, p; i < n; ++i)
		{
			std::cin >> p; --p;
			G[p].push_back(i);
		}
		
		std::vector<ll> s(n), f(n), g(n);
		for(ll &x : s) std::cin >> x;
		
		auto dfs = [&](auto self, int u, int l, int r) -> void
		{
			// fprintf(stderr, "dfs %d, l = %d, r = %d\n", u, l, r);
			f[u] = s[u] * l; g[u] = s[u] * r;
			if(!G[u].size()) return;
			
			int t = G[u].size();
			std::vector<ll> delta;
			for(int v : G[u])
			{
				self(self, v, l / t, (r + t - 1) / t);
				f[u] += f[v]; g[u] += f[v];
				delta.push_back(g[v] - f[v]);
			}
			
			std::sort(delta.begin(), delta.end(), std::greater<>());
			std::vector<ll> ps(t + 1);
			std::partial_sum(delta.begin(), delta.end(), ps.begin() + 1);
			f[u] += ps[l % t];
			g[u] += ps[l % t + 1];
		};
		
		dfs(dfs, 0, k, k);
		std::cout << f[0] << "\n";
	}
	return 0;
}