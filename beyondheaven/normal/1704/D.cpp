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
		std::vector<std::vector<ll>> c(n);
		std::vector<ll> z(n);
		
		for(auto &v : c)
		{
			v.resize(m);
			for(ll &x : v) std::cin >> x;
			std::partial_sum(v.begin(), v.end(), v.begin());
		}
		
		std::map<ll, int> mp;
		for(int i = 0; i < n; ++i)
		{
			z[i] = std::accumulate(c[i].begin(), c[i].end(), ll(0));
			++mp[z[i]];
		}
		
		assert(mp.size() == 2);
		for(int i = 0; i < n; ++i) if(mp[z[i]] == 1) std::cout << i + 1 << " ";
		std::cout << (std::prev(mp.end()) -> first) - (mp.begin() -> first) << "\n";
	}
	return 0;
}