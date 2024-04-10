#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> a(n);
		std::array<std::vector<int>, 2> cnt;
		for(int z : { 0, 1 }) cnt[z].resize(n + 1);
		for(int i = 0; i < n; ++i)
		{
			std::cin >> a[i];
			for(int z : { 0, 1 })
			cnt[z][i + 1] = cnt[z][i] + (a[i] == z);
		}	
		
		int ans = n;
		for(int i = 0; i <= n; ++i)
		{
			int l = cnt[1][i] - cnt[1][0],
				r = cnt[0][n] - cnt[0][i];
			if(l >= r) ans = std::min(ans, l);
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}