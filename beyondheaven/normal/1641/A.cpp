#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, t; std::cin >> n >> t;
		std::multiset<int> S;
		for(int i = 1, x; i <= n; ++i) std::cin >> x, S.insert(x);
		
		int ans = 0;
		while(S.size())
		{
			auto x = *S.begin(); S.erase(S.begin());
			if(x <= int(1e9) / t && S.count(x * t)) S.erase(S.find(x * t));
			else ++ans;
		}
		std::cout << ans << "\n";
	}
	return 0;
}