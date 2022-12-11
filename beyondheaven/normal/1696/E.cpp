#include <bits/stdc++.h>
const int MaxN = 5e5 + 5;
const int Mod = 1e9 + 7;

int n, m, a[MaxN], Fac[MaxN], Inv[MaxN], FInv[MaxN];
int C(int n, int m)
{
	if(m < 0 || m > n) return 0;
	return 1LL * Fac[n] * FInv[m] % Mod * FInv[n - m] % Mod;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	
	Fac[0] = FInv[0] = Fac[1] = Inv[1] = FInv[1] = 1;
	for(int i = 2; i <= n + m + 5; ++i)
	{
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		Inv[i] = 1LL * (Mod - Mod / i) * Inv[Mod % i] % Mod;
		FInv[i] = 1LL * FInv[i - 1] * Inv[i] % Mod;
	}
	
	int ans = m;
	for(int i = 1; i <= n; ++i)
	{
		ans = (ans + 1LL * C(i + a[i] - 1, i) * a[i]) % Mod;
		ans = (ans - 1LL * C(i + a[i] - 1, i + 1) * i) % Mod;
	}
	
	std::cout << (ans + Mod) % Mod << "\n";
	return 0;
}