#include <bits/stdc++.h>
int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<std::vector<int>> G(n + 1);
		
		for(int i = 1, u, v; i < n; ++i)
		{
			std::cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		std::vector<std::array<int, 2>> dp(n + 1);
		std::fill(dp.begin(), dp.end(), std::array<int, 2>{0, 0});
		
		std::function<void(int, int)> Dfs = [&](int u, int f)
		{
			dp[u][0] = 0;
			int a = -1, b = n;
			
			for(int v : G[u]) if(v != f)
			{
				Dfs(v, u);
				dp[u][0] = std::min(dp[u][0] + dp[v][1], n);
				b = std::min(b + std::min(dp[v][0] + 1, dp[v][1]), a + dp[v][0] + 1);
				a = a + dp[v][1];
				a = std::min(a, n);
				b = std::min(b, n);
			}
			
			if(u != 1 && static_cast<int>(G[u].size()) == 1) dp[u][1] = n;
			else dp[u][1] = std::min(b, n);
		};
		
		Dfs(1, 0);
		
		#ifdef Dubug
		for(int i = 1; i <= n; ++i)
		printf("dp[%d][0] = %d dp[%d][1] = %d\n", i, dp[i][0], i, dp[i][1]);
		#endif
		
		printf("%d\n", std::min(dp[1][0], dp[1][1]) + 1); 
	}
	return 0;
}