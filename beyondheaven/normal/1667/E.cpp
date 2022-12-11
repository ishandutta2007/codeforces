#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int Mod = 998244353;

int n, Fac[MaxN], Inv[MaxN], FInv[MaxN];
int f[MaxN], g[MaxN];

int C(int n, int m)
{
	if(m < 0 || m > n) return 0;
	return int64_t(Fac[n]) * FInv[m] % Mod * FInv[n - m] % Mod;
}

int main()
{
	std::cin >> n;
	Fac[0] = FInv[0] = Fac[1] = Inv[1] = FInv[1] = 1;
	for(int i = 2; i <= n; ++i)
	{
		Fac[i] = int64_t(Fac[i - 1]) * i % Mod;
		Inv[i] = int64_t(Mod - Mod / i) * Inv[Mod % i] % Mod;
		FInv[i] = int64_t(FInv[i - 1]) * Inv[i] % Mod;
	}
	
	f[1] = Fac[n - 1];
	for(int i = 2; i <= n / 2 + 1; ++i)
	f[i] = int64_t(Fac[n - i]) * Fac[i - 1] % Mod * C(n / 2, i - 1) % Mod;
	
	for(int i = n / 2 + 1, sum = 0; i; --i)
	{
		g[i] = (f[i] - sum + Mod) % Mod;
		sum = (sum + int64_t(f[i]) * Inv[i - 1]) % Mod;
	}
	
	for(int i = 1; i <= n; ++i) std::cout << g[i] << " ";
	return 0;
}