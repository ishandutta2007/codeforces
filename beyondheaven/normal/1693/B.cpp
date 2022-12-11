#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n; ll l[MaxN], r[MaxN];
std::vector<int> G[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 2, f; i <= n; ++i) std::cin >> f, G[f].push_back(i);
		
		for(int i = 1; i <= n; ++i) std::cin >> l[i] >> r[i];
		
		int ans = 0;
		auto dfs = [&](auto &&self, int u) -> std::pair<ll, ll>
		{
			ll x = 0, y = 0;
			for(int v : G[u])
			{
				auto t = self(self, v);
				x += t.first; y += t.second; 
			}
			
			if(std::max(x, l[u]) <= std::min(y, r[u]))
			return { 0, std::min(y, r[u]) };
			else { ++ans; return { 0, r[u] }; }
		};
		
		dfs(dfs, 1);
		std::cout << ans << "\n";
	}
	return 0;
}