#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;

int n, k, a[MaxN], c[MaxN];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> k;
		for(int i = 1; i <= n; ++i) c[i] = 0;
		for(int i = 1; i <= n; ++i) std::cin >> a[i], ++c[a[i]];
		
		auto check = [&](int lim)
		{
			for(int i = 1, s = 0; i <= n; ++i)
			{
				s += c[i];
				if(i - lim >= 1) s -= c[i - lim];
				if(s - (n - s) >= k) return i;
			}
			return 0;
		};
		
		int l = 1, r = n, ans = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		
		int y = check(ans), x = y - ans + 1;
		
		std::vector<std::array<int, 2>> V;
		
		if(k > 1)
		for(int i = 1, c = 0; i <= n; ++i)
		{
			if(x <= a[i] && a[i] <= y)
			{
				++c;
				if(c == 1)
				{
					V.push_back({(V.size() ? V.back()[1] + 1 : 1), i});
					if(int(V.size()) == k - 1) break;
					c = 0; 
				}
			}
			else --c;
		}
		
		V.push_back({(V.size() ? V.back()[1] + 1 : 1), n});
		
		std::cout << x << " " << y << "\n";
		for(auto p : V) std::cout << p[0] << " " << p[1] << "\n";
	}
	return 0;
}