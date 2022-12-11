#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<std::pair<int, int>> V;
		std::vector<int> a(n);
		for(int i = 0; i < n; ++i)
		{
			std::cin >> a[i];
			if(i) V.emplace_back(std::max(a[i - 1] - a[i], 0), i);
			else V.emplace_back(0, 0);
		}
		
		std::sort(V.begin(), V.end(), std::greater<>());
		std::set<int> S;
		std::vector<int> ans(n);
		for(int i = 1; i <= n; ++i) S.insert(i);
		
		for(auto [x, i] : V)
		{
			auto it = S.lower_bound(x);
			assert(it != S.end());
			ans[*it - 1] = i;
			S.erase(it);
		}
		
		for(int i = 0; i < n; ++i) std::cout << ans[i] + 1 << " \n"[i == n - 1];
	}
	return 0;
}