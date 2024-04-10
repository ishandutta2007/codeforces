#include <bits/stdc++.h>
const int MaxN = 4e5 + 5;
using ll = long long;

int n, T, repr[MaxN];
ll g[MaxN], c[MaxN], a[MaxN], s[MaxN], e[MaxN], dis[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	auto red = [&](ll x) { return (x % T + T) % T; };
	
	std::cin >> n >> T;
	for(int i = 1; i <= n; ++i) std::cin >> g[i] >> c[i];
	for(int i = 2, x; i <= n; ++i) std::cin >> x, a[i] = a[i - 1] + x;
	
	std::set<std::pair<ll, int>> S;	
	for(int i = 1; i <= n; ++i)
	{
		s[i] = red((-c[i]) - a[i]);
		e[i] = red((-c[i]) - a[i] + g[i]);
		repr[i] = i; dis[i] = 0;
		S.emplace(red(e[i] - 1), i);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		int x = n + i;
		repr[x] = x; dis[x] = 0;
		S.emplace(s[i], x);
		
		if(s[i] < e[i])
		{
			while(true)
			{
				auto it = S.lower_bound({ e[i], 0 });
				if(it != S.end())
				{
					int y = it -> second;
					repr[y] = x; dis[y] = s[i] + T - it -> first;
					S.erase(it); 
				}
				else break;
			}
			
			while(true)
			{
				auto it = S.begin();
				if(it -> first < s[i])
				{
					int y = it -> second;
					repr[y] = x; dis[y] = s[i] - it -> first;
					S.erase(it);
				}
				else break;
			}
		}
		else
		{
			while(true)
			{
				auto it = S.lower_bound({ e[i], 0 });
				if(it -> first < s[i])
				{
					int y = it -> second;
					repr[y] = x; dis[y] = s[i] - it -> first;
					S.erase(it); 
				}
				else break;
			}
		}
	}
	
	for(int i = 2 * n; i; --i) if(repr[i] != i) dis[i] += dis[repr[i]];
	std::cout << *std::min_element(dis + 1, dis + n + 1) + a[n] << "\n";
	return 0;
}