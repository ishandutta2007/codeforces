#include <bits/stdc++.h>
using LL = long long;
const int MaxN = 233;

int n, k;
LL X[MaxN], Y[MaxN];
std::pair<int, LL> dp[MaxN][MaxN];

int main()
{
	scanf("%d%d", &n, &k); ++k;
	for(int i = 1; i <= n; ++i) scanf("%lld%lld", X + i, Y + i);
	
	auto cross = [&](int i, int j, int k)
	{
		return (X[j] - X[i]) * (Y[k] - Y[i]) - (X[k] - X[i]) * (Y[j] - Y[i]);
	};
	
	LL L = 0, R = 8e16, Mid = 0, ans = 0;
	while(L <= R)
	{
		Mid = (L + R) / 2;
		for(int len = 3; len <= n; ++len)
		for(int l = 1, r = len; r <= n; ++l, ++r)
		{
			dp[l][r] = {0, 0};
			for(int k = l + 1; k < r; ++k)
			{
				int a = dp[l][k].first + dp[k][r].first;
				LL b = dp[l][k].second + dp[k][r].second + cross(l, k, r);
				if(b >= Mid) dp[l][r] = std::max(dp[l][r], std::make_pair(a + 1, 0LL));
				else dp[l][r] = std::max(dp[l][r], std::make_pair(a, b));
			}
		}
		if(dp[1][n].first >= k) ans = Mid, L = Mid + 1;
		else R = Mid - 1;
	}
	
	printf("%lld\n", ans);
	return 0;
}