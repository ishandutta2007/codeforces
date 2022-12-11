#include <bits/stdc++.h>
const int MaxN = 100 + 5;
const int L = 100;

int f[MaxN][MaxN][2], g[MaxN][MaxN][2];
int main()
{
	f[0][0][0] = g[0][0][0] = 1;
	for(int i = 1; i <= L; ++i)
	{
		for(int t : { 0, 1 })
		{
			f[i][0][t] = g[i - 1][0][t];
			g[i][0][t] = f[i - 1][0][t];
		}
		
		for(int t : { 0, 1 })
		{
			f[0][i][t] = g[0][i - 1][t ^ 1];
			g[0][i][t] = f[0][i - 1][t];
		}
	}
	
	for(int i = 1; i <= L; ++i)
	for(int j = 1; j <= L; ++j)
	{
		for(int t : { 0, 1 })
		{
			f[i][j][t] = std::max(g[i - 1][j][t], g[i][j - 1][t ^ 1]);
			g[i][j][t] = std::min(f[i - 1][j][t], f[i][j - 1][t]);
		}
	}
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, cnt[2] = { 0, 0 }; std::cin >> n;
		for(int i = 0, x; i < n; ++i) std::cin >> x, cnt[std::abs(x) % 2] += 1;
		std::cout << (f[cnt[0]][cnt[1]][0] ? "Alice" : "Bob") << "\n";
	}
	return 0;
}