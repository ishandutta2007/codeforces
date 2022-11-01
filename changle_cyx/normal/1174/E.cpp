#include <bits/stdc++.h>

const int MaxLog = 21; 
const int mod = 1e9 + 7; 
const int MaxN = 1e6 + 5; 

int n; 
int f[MaxN][MaxLog][2]; 

inline int calc(int x, int y)
{
	if (y)
		return n / 3 / (1 << x); 
	else
		return n / (1 << x); 
}

int main()
{
//	freopen("gcd.in", "r", stdin); 
//	freopen("gcd.out", "w", stdout); 

	int p = 0, l = 1; 

	std::cin >> n; 
	
	while ((l << 1) <= n)
		l <<= 1, ++p; 

	f[1][p][0] = 1; 
	if ((1 << (p - 1)) * 3 <= n)
		f[1][p - 1][1] = 1; 

	for (int i = 2; i <= n; ++i)
		for (int x = 0; x <= p; ++x)
			for (int y = 0; y <= 1; ++y)
			{
				f[i][x][y] = 1LL * f[i - 1][x][y] * (calc(x, y) - (i - 1)) % mod; 
				if (x < p)
					f[i][x][y] = (f[i][x][y] + 1LL * f[i - 1][x + 1][y] * (calc(x, y) - calc(x + 1, y))) % mod; 
				if (y < 1)
					f[i][x][y] = (f[i][x][y] + 1LL * f[i - 1][x][y + 1] * (calc(x, y) - calc(x, y + 1))) % mod; 
			}

	std::cout << f[n][0][0] << std::endl; 

	return 0; 
}