#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
using ll = long long;

int n, m; ll c1[MaxN], c2[MaxN];
std::vector<std::array<int, 2>> V[MaxN];

void add(ll c[], int x, ll v) { for(; x <= m; x += (x & -x)) c[x] += v; }
ll sum(ll c[], int x, ll v = 0) { for(; x; x -= (x & -x)) v += c[x]; return v; }

int main()
{
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	for(int j = 1, x; j <= m; ++j) std::cin >> x, V[x].push_back({i, j});
	
	ll ans = 0;
	for(int t = 1; t <= 100000; ++t)
	{
		ll cnt = 0, tot = 0;
		
		for(auto p : V[t])
		{
			int x = p[0], y = p[1];
			ans += cnt * x - tot;
			ans += sum(c1, y) * y - sum(c2, y);
			ans += (sum(c2, m) - sum(c2, y)) - (sum(c1, m) - sum(c1, y)) * y;
			
			++cnt; tot += x;
			add(c1, y, 1);
			add(c2, y, y);
		}
		
		for(auto p : V[t])
		{
			int x = p[0], y = p[1];
			add(c1, y, -1);
			add(c2, y, -y);
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}