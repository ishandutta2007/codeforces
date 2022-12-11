#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
using ll = long long;

int n;
ll a[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		while(n && a[n] == 0) --n;
		
		if(n == 0) { std::cout << "YES" << "\n"; continue; }
		
		ll sum = std::accumulate(a + 1, a + n + 1, 0LL);
		if(sum != 0) { std::cout << "NO" << "\n"; continue; }
		
		--a[1]; ++a[n];
		
		ll pre = 0;
		bool ans = true;
		for(int i = 1; i <= n; ++i)
		{
			pre += a[i];
			if(pre < 0) ans = false;
		}
		
		std::cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}