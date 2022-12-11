#include <bits/stdc++.h>
const int MaxN = 1e6 + 5;
const int L = 1e6;
const int Mod = 1e9 + 7;
const int Inv2 = (Mod + 1) / 2;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = 1LL * a * a % Mod)
	if(b & 1) res = 1LL * res * a % Mod;
	return res;
}

int z[MaxN], Fac[MaxN], FInv[MaxN];
int C(int n, int m) { return 1LL * Fac[n] * FInv[m] % Mod * FInv[n - m] % Mod; }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	for(int i = Fac[0] = 1; i <= L; ++i) Fac[i] = 1LL * Fac[i - 1] * i % Mod;
	FInv[L] = pow_mod(Fac[L], Mod - 2);
	for(int i = L; i >= 1; --i) FInv[i - 1] = 1LL * FInv[i] * i % Mod;
	
	for(int i = 1; i <= L; ++i) z[i] = pow_mod(2, i - 1, i);
	
	int T; std::cin >> T;
	while(T--)
	{
		int n, m, k; std::cin >> n >> m >> k;
		int ans = 0;
		if(n == m) std::cout << 1LL * n * k % Mod << "\n";
		else
		{
			for(int t = 1; t <= m; ++t) ans = (ans + 1LL * C(n - t - 1, m - t) * z[t]) % Mod;
			std::cout << 1LL * pow_mod(Inv2, n - 1, ans) * k % Mod << "\n";
		}
	} 
	return 0;
}