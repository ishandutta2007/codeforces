#include <bits/stdc++.h>
const int MaxN = 5e3 + 5;
using ll = long long;

int n, p[MaxN], sum[MaxN], f[MaxN][MaxN];
int main()
{
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n;
		for(int i = 1; i <= n; ++i) std::cin >> p[i];
		
		for(int d = n; d >= 1; --d)
		{
			std::fill(sum + 1, sum + n + 1, 0);
			for(int i = d; i <= n; ++i) ++sum[p[i]];
			for(int i = 1; i <= n; ++i) sum[i] += sum[i - 1];	
			for(int b = 1; b < d; ++b) f[b][d] = f[b - 1][d] + sum[p[b]];
		}
		
		ll ans = 0;
		for(int a = 1; a < n; ++a)
		for(int c = a + 1; c < n; ++c)
		if(p[a] < p[c]) ans += f[c - 1][c + 1] - f[a][c + 1];
		std::cout << ans << "\n";
	}
	return 0; 
}