#include <bits/stdc++.h>
int main()
{
	using ll = long long;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, k; std::cin >> n >> k;
		std::vector<ll> a(n + 2);
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		a[0] = a[n + 1] = 1e18;
		
		auto get = [&](int k, int v)
		{
			ll sum = 0, mn = 0, id = 0;
			for(int i = k + v; ; i += v)
			{
				sum += a[i];
				mn = std::min(mn, sum);
				id = i;
				if(sum >= 0) return std::array<ll, 3> { sum, mn, id };
			}
		};
		
		auto dfs = [&](auto self, int l, int r, auto fl, auto fr, ll val) -> bool
		{
			if(val >= -fl[1])
			{
				if(fl[2] == 0) return true;
				else return self(self, fl[2], r, get(fl[2], -1), fr, val + fl[0]);
			}
			else if(val >= -fr[1])
			{
				if(fr[2] == n + 1) return true;
				else return self(self, l, fr[2], fl, get(fr[2], 1), val + fr[0]);
			}
			else return false;
		};
		
		std::cout << (dfs(dfs, k, k, get(k, -1), get(k, 1), a[k]) ? "YES" : "NO") << "\n";
	}
	return 0;
}