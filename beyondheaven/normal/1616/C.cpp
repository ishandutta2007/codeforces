#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n; std::vector<int> a(n);
		for(int i = 0; i < n; ++i) std::cin >> a[i];
		
		auto check = [&](int i, int d, int x)
		{
			int ans = 0;
			for(int t = i, expect = a[i]; t < n; t += d, expect += x) ans += (a[t] == expect);
			return ans;
		};
		
		int ans = n;
		for(int i = 0; i < n; ++i)
		for(int d = 1; d <= n; ++d)
		for(int x = -200; x <= 200; ++x) ans = std::min(ans, n - check(i, d, x));
		std::cout << ans << std::endl;
	}
	return 0;
}