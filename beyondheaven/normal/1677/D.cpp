#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;
const int Mod = 998244353;

int n, k, a[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> k;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		
		int ans = 1;
		for(int i = 1; i <= k; ++i) ans = 1LL * ans * i % Mod;
		
		for(int i = 1; i <= n - k; ++i)
		{
			if(a[i] == -1) ans = 1LL * ans * (i + k) % Mod;
			else if(a[i] == 0) ans = 1LL * ans * (k + 1) % Mod;
		}
		
		for(int i = n - k + 1; i <= n; ++i) if(a[i] != 0 && a[i] != -1) ans = 0;
		std::cout << ans << "\n";
	}
	return 0;
}