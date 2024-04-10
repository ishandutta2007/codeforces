#include <bits/stdc++.h>
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2));
		std::vector<std::vector<int>> V(n + 1);
		
		for(int i = 1; i <= n; ++i) V[a[i]].push_back(i);
		
		for(int len = 2; len <= n; ++len)
		{
			for(int l = 1, r = len; r <= n; ++l, ++r)
			{
				dp[l][r] = std::max(dp[l][r], dp[l + 1][r]);
				for(int k : V[a[l]]) if(l < k && k <= r)
				dp[l][r] = std::max(dp[l][r], 1 + dp[l + 1][k - 1] + dp[k][r]);
			}
		}
		printf("%d\n", n - 1 - dp[1][n]);
	}
	return 0;
}