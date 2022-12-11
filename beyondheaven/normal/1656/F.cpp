#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n;
ll a[MaxN];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		std::sort(a + 1, a + n + 1);
		
		ll mn = std::accumulate(a + 1, a + n + 1, 0LL) + (n - 2) * a[1],
		   mx = std::accumulate(a + 1, a + n + 1, 0LL) + (n - 2) * a[n];
		
		if((mn < 0 && mx < 0) || (mn > 0 && mx > 0)) { std::cout << "INF" << "\n"; continue; }
		
		ll x = 0, y = 0;
		for(int i = 2; i <= n; ++i)
		{
			x += a[1] * a[i];
			y += a[1] + a[i]; 
		}
		
		ll ans = std::max(x + y * (-a[1]), x + y * (-a[2]));
		for(int i = 2; i < n; ++i)
		{
			x += a[i] * a[n] - a[i] * a[1];
			y += a[i] + a[n] - (a[i] + a[1]);
			ans = std::max(ans, x + y * (-a[i]));
			ans = std::max(ans, x + y * (-a[i + 1]));
		}
		std::cout << ans << "\n";
	}
	return 0;
}