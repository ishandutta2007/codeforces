#include <bits/stdc++.h>
using ll = long long;
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		ll n; std::cin >> n;
		if(n <= 10)
		{
			int ans = -1;
			for(int k = 2; k <= 10; ++k)
			{
				int x = k * (k - 1) / 2;
				if(n > x && (n - x) % k == 0) ans = k;
			}
			std::cout << ans << "\n";
			continue;
		}
		
		ll u = n, v = 1;
		while(u % 2 == 0) u /= 2, v *= 2;
		
		if(u == 1) { std::cout << -1 << "\n"; continue; }
		if(v > (u - 1) / 2) std::cout << u << "\n";
		else std::cout << 2 * v << "\n";
	}
	return 0;
}