#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<ll> a(n);
		for(ll &x : a) std::cin >> x;
		
		ll ans = 1e18;
		for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
		for(int k = j + 1; k < n; ++k)
		{
			ll x = a[i], y = a[j], z = a[k];
			ll mid = x + y + z - std::min({ x, y, z }) - std::max({ x, y, z });
			ans = std::min(ans, std::abs(x - mid) + std::abs(y - mid) + std::abs(z - mid));
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}