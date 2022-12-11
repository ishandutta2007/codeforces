#include <bits/stdc++.h>
const int MaxN = 5e5 + 5;

int n, a[MaxN], rk[MaxN], dp[MaxN];
int64_t sum[MaxN], V[MaxN];

int c1[MaxN], c2[MaxN];

void modify(int c[], int x, int v)
{
	for(; x <= n + 1; x += (x & -x)) c[x] = std::max(c[x], v);
}

int query(int c[], int x, int res = INT_MIN / 2)
{
	for(; x; x -= (x & -x)) res = std::max(res, c[x]);
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		
		sum[0] = V[0] = 0;
		for(int i = 1; i <= n; ++i)
		{
			std::cin >> a[i];
			sum[i] = V[i] = sum[i - 1] + a[i];
		}
		
		std::fill(c1 + 1, c1 + n + 2, INT_MIN / 2);
		std::fill(c2 + 1, c2 + n + 2, INT_MIN / 2);
		
		std::sort(V, V + n + 1);
		for(int i = 0; i <= n; ++i) rk[i] = std::lower_bound(V, V + n + 1, sum[i]) - V + 1;
		
		std::map<int64_t, int> mp;
		auto ins = [&](int64_t a, int b)
		{
			if(mp.count(a)) mp[a] = std::max(mp[a], b);
			else mp[a] = b;
		};
		
		dp[0] = 0; ins(0, 0);
		modify(c1, rk[0], 0);
		modify(c2, n + 1 - rk[0] + 1, 0);
		
		for(int i = 1; i <= n; ++i)
		{
			dp[i] = INT_MIN / 2;
			
			dp[i] = std::max(dp[i], query(c1, rk[i] - 1) + i);
			if(mp.count(sum[i])) dp[i] = std::max(dp[i], mp[sum[i]]);
			dp[i] = std::max(dp[i], query(c2, n + 1 - rk[i]) - i);
			
			modify(c1, rk[i], dp[i] - i);
			modify(c2, n + 1 - rk[i] + 1, dp[i] + i);
			ins(sum[i], dp[i]);
		}
		
		std::cout << dp[n] << "\n";
	}
	return 0;
}