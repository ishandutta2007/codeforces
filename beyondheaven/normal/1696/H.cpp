#include <bits/stdc++.h>
const int MaxN = 600 + 5;
const int Mod = 1e9 + 7;

int n, k, pw[MaxN];
int m[2], b[2][MaxN], pos[2][MaxN];
int f[2][MaxN], g[2][MaxN][MaxN], dp[MaxN];

int main()
{
	std::cin >> n >> k;
	for(int i = pw[0] = 1; i <= n; ++i) pw[i] = 2 * pw[i - 1] % Mod;
	
	for(int i = 1, x; i <= n; ++i)
	{
		std::cin >> x;
		if(x < 0) b[0][++m[0]] = x;
		else b[1][++m[1]] = x;
	}
	
	std::sort(b[0] + 1, b[0] + m[0] + 1);
	std::sort(b[1] + 1, b[1] + m[1] + 1, std::greater<>());
	
	for(int i = 1; i <= m[0]; ++i)
	{
		int &y = pos[0][i]; y = 1;
		while(y <= m[1] && std::abs(b[1][y]) >= std::abs(b[0][i])) ++y;
	}
	
	for(int j = 1; j <= m[1]; ++j)
	{
		int &x = pos[1][j]; x = 1;
		while(x <= m[0] && std::abs(b[0][x]) > std::abs(b[1][j])) ++x;
	}
	
	for(int t : {0, 1})
	{
		f[t][0] = 1;
		for(int i = 1; i <= m[t]; ++i)
		{
			for(int j = k; j; --j) g[t][i][j] = f[t][j - 1];
			for(int j = k; j; --j) f[t][j] = (f[t][j] + 1LL * b[t][i] * f[t][j - 1]) % Mod;
		}
	}
	
	int ans = 0;
	// p = 0
	for(int j = 1; j <= m[1]; ++j) if(g[1][j][k])
	{
		int v = g[1][j][k];
		ans = (ans + 1LL * v * b[1][j]) % Mod;
		
		for(int x = std::max(1, pos[1][j]); x <= m[0]; ++x)
		{
			int t = 1LL * v * b[1][j] % Mod;
			ans = (ans + 1LL * t * pw[m[0] - x]) % Mod;
		}	
		
		for(int y = j + 1; y <= m[1]; ++y)
		{
			int t = 1LL * v * b[1][j] % Mod;
			ans = (ans + 1LL * t * pw[m[1] - y]) % Mod;
		}
		
		for(int x = std::max(1, pos[1][j]); x <= m[0]; ++x)
		for(int y = j + 1; y <= m[1]; ++y)
		{
			int t = 1LL * v * b[1][j] % Mod;
			ans = (ans + 1LL * t * pw[m[0] - x + m[1] - y]) % Mod;
		}
	}
	
	for(int i = 1; i <= m[0]; ++i)
	{
		for(int j = 1; j <= m[1]; ++j)
		{
			int v0 = 0, v1 = 0;
			for(int p = 1; p < k; ++p)
			if(p % 2 == 1) v1 = (v1 + 1LL * g[0][i][p] * g[1][j][k - p]) % Mod;
			else v0 = (v0 + 1LL * g[0][i][p] * g[1][j][k - p]) % Mod;
			
			ans = (ans + 1LL * (v0 + v1) * b[0][i] % Mod * b[1][j]) % Mod;
			
			for(int x = std::max(i + 1, pos[1][j]); x <= m[0]; ++x)
			{
				int t0 = 1LL * v0 * b[0][i] % Mod * b[1][j] % Mod,
					t1 = 1LL * v1 * b[0][i] % Mod * b[0][x] % Mod;
				ans = (ans + 1LL * (t0 + t1) * pw[m[0] - x]) % Mod;
			}
			
			for(int y = std::max(j + 1, pos[0][i]); y <= m[1]; ++y)
			{
				int t0 = 1LL * v0 * b[0][i] % Mod * b[1][j] % Mod,
					t1 = 1LL * v1 * b[1][j] % Mod * b[1][y] % Mod;
				ans = (ans + 1LL * (t0 + t1) * pw[m[1] - y]) % Mod;
			}
			
			int l = std::max(j + 1, pos[0][i]), r = m[1];
			if(l > r) continue;
			
			for(int x = std::max(i + 1, pos[1][j]); x <= m[0]; ++x)
			{
				int t0 = 1LL * v0 * b[0][i] % Mod * b[1][j] % Mod;
				ans = (ans + 1LL * t0 * pw[m[0] - x] % Mod * (2 * pw[m[1] - l] - 1)) % Mod;
			}
			
			/*
			for(int y = l; y <= r; ++y)
			{
				int t1 = std::max(1LL * b[0][x] * b[0][i], 1LL * b[1][y] * b[1][j]) % Mod * pw[m[1] - y] % Mod;
				ans = (ans + 1LL * t1 * v1 % Mod * pw[m[0] - x] % Mod) % Mod;
			}
			*/
			
			for(int x = std::max(i + 1, pos[1][j]), y = l, t1 = 0; x <= m[0]; ++x)
			{
				while(y <= r && 1LL * b[1][y] * b[1][j] >= 1LL * b[0][x] * b[0][i])
				{
					t1 = (t1 + 1LL * b[1][y] * b[1][j] % Mod * pw[m[1] - y]) % Mod;
					++y;
				}
				ans = (ans + 1LL * t1 * v1 % Mod * pw[m[0] - x] % Mod) % Mod;
			}
			
			for(int x = m[0], y = r, t1 = 0; x >= std::max(i + 1, pos[1][j]); --x)
			{
				while(y >= l && 1LL * b[1][y] * b[1][j] < 1LL * b[0][x] * b[0][i])
				{
					t1 = (t1 + pw[m[1] - y]) % Mod;
					--y;
				}
				ans = (ans + 1LL * t1 * v1 % Mod * b[0][x] % Mod * b[0][i] % Mod * pw[m[0] - x]) % Mod;
			}
		}
	}
	
	// p = k
	for(int i = 1; i <= m[0]; ++i) if(g[0][i][k])
	{
		int v = g[0][i][k];
		ans = (ans + 1LL * v * b[0][i]) % Mod;
		
		for(int x = i + 1; x <= m[0]; ++x)
		{
			int t = 1LL * v * b[0][i] % Mod;
			ans = (ans + 1LL * t * pw[m[0] - x]) % Mod;
		}
		
		for(int y = std::max(1, pos[0][i]); y <= m[1]; ++y)
		{
			int t = v;
			if(k % 2 == 1) t = 1LL * t * b[1][y] % Mod;
			else t = 1LL * t * b[0][i] % Mod;
			ans = (ans + 1LL * t * pw[m[1] - y]) % Mod;
		}
		
		for(int x = i + 1; x <= m[0]; ++x)
		for(int y = std::max(1, pos[0][i]); y <= m[1]; ++y)
		{
			int t = v;
			if(k % 2 == 1) t = 1LL * t * b[1][y] % Mod;
			else t = 1LL * t * b[0][i] % Mod;
			ans = (ans + 1LL * t * pw[m[0] - x + m[1] - y]) % Mod;
		}
	}
	
	if(k % 2)
	{
		dp[0] = 1;
		for(int i = 1; i <= m[0]; ++i)
		{
			ans = (ans - 1LL * b[0][i] * dp[k - 1] % Mod * pw[m[0] - i]) % Mod;
			for(int j = k; j; --j) dp[j] = (dp[j] + 1LL * b[0][i] * dp[j - 1]) % Mod;
		}
		
		std::reverse(b[0] + 1, b[0] + m[0] + 1);
		std::fill(dp, dp + k + 1, 0); dp[0] = 1;
		for(int i = 1; i <= m[0]; ++i)
		{
			ans = (ans + 1LL * b[0][i] * dp[k - 1] % Mod * pw[m[0] - i]) % Mod;
			for(int j = k; j; --j) dp[j] = (dp[j] + 1LL * b[0][i] * dp[j - 1]) % Mod;
		}
	}
	
	std::cout << (ans + Mod) % Mod << "\n";
	return 0;
}