#include <bits/stdc++.h>
const int MaxN = 5e5 + 5;
using ll = long long;

int n, a[MaxN], c[MaxN], d[MaxN];
void add(int x, int v) { for(; x <= n; x += (x & -x)) c[x] += v; }
int sum(int x, int v = 0) { for(; x; x -= (x & -x)) v += c[x]; return v; }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		ll inv = 0;
		for(int i = 1; i <= n; ++i)
		{
			std::cin >> a[i];
			inv += sum(n) - sum(a[i]);
			add(a[i], 1);
		}
		
		for(int i = 1; i <= n; ++i) d[i] = i - 2 * a[i] + 1;
		std::sort(d + 1, d + n + 1, std::greater<>());
		
		std::cout << inv << " ";
		for(int i = 1; i <= n; ++i)
		{
			inv -= d[i];
			std::cout << inv - 1LL * i * (i - 1) / 2 << " \n"[i == n];
			add(a[i], -1);
		}
	}
	return 0;
}