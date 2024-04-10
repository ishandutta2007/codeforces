#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;
using ll = long long;

ll dp(const std::vector<int> &V)
{
	ll f[2] = { 0, ll(-1e18) };
	for(int x : V)
	{
		ll g[2];
		g[0] = std::max(f[0] + x, f[1] - x);
		g[1] = std::max(f[1] + x, f[0] - x);
		f[0] = g[0]; f[1] = g[1];
	}
	return f[0];
}

int n, m, B, a[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> m;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		int B = 0;
		for(int i = 1, x; i <= m; ++i) std::cin >> x, B = std::__gcd(B, x);
		
		ll ans1 = 0;
		for(int i = 1; i <= B; ++i)
		{
			std::vector<int> V;
			for(int j = i; j <= n; j += B) V.push_back(a[j]);
			ans1 += dp(V);
		}
		
		std::transform(a + 1, a + B + 1, a + 1, std::negate<int>());
		
		ll ans2 = 0;
		for(int i = 1; i <= B; ++i)
		{
			std::vector<int> V;
			for(int j = i; j <= n; j += B) V.push_back(a[j]);
			ans2 += dp(V);
		}
		
		std::cout << std::max(ans1, ans2) << "\n";
	}
	return 0;
}