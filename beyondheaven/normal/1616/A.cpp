#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::map<int, int> cnt;
		for(int i = 1, x; i <= n; ++i) std::cin >> x, ++cnt[std::abs(x)];
		
		int ans = 0;
		for(const auto &p : cnt) ans += std::min(p.second, 1 + !!p.first);
		std::cout << ans << std::endl;
	}
	return 0;
}