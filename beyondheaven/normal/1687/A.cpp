#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n, k;
ll a[MaxN], sum[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> k;
		for(int i = 1; i <= n; ++i)
		{
			std::cin >> a[i];
			sum[i] = sum[i - 1] + a[i] + k;
		}
		
		k = std::min(k, n);
		
		ll ans = 0;
		for(int l = 1, r = k; r <= n; ++l, ++r) ans = std::max(ans, sum[r] - sum[l - 1]);
		std::cout << ans - 1LL * k * (k + 1) / 2 << "\n";
	}
	return 0;
}