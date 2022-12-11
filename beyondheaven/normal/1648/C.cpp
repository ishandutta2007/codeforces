#include <bits/stdc++.h>
const int MaxN = 2e5 + 5;
const int L = 2e5;
const int Mod = 998244353;
using ll = long long;

int n, m, s[MaxN], t[MaxN], Fac[MaxN], Inv[MaxN], FInv[MaxN], a[MaxN], c[MaxN];

void add(int x, int v) { for(; x <= L; x += (x & -x)) c[x] += v; }
int sum(int x, int v = 0) { for(; x; x -= (x & -x)) v += c[x]; return v; }

int main()
{
	Fac[0] = FInv[0] = Fac[1] = Inv[1] = FInv[1] = 1;
	for(int i = 2; i <= L; ++i)
	{
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		Inv[i] = 1LL * (Mod - Mod / i) * Inv[Mod % i] % Mod;
		FInv[i] = 1LL * FInv[i - 1] * Inv[i] % Mod;
	}
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) std::cin >> s[i], ++a[s[i]];
	for(int i = 1; i <= m; ++i) std::cin >> t[i];
	
	int coef = 1;
	for(int i = 1; i <= L; ++i)
	{
		coef = 1LL * coef * FInv[a[i]] % Mod;
		add(i, a[i]);
	}
	
	int ans = 0;
	for(int i = 1; i <= std::min(n, m); ++i)
	{
		ans = (ans + 1LL * sum(t[i] - 1) * coef % Mod * Fac[n - i]) % Mod;
		if(a[t[i]] == 0) break;
		coef = 1LL * coef * a[t[i]] % Mod;
		--a[t[i]];
		add(t[i], -1);
	}
	
	if(m > n)
	{
		std::sort(s + 1, s + n + 1);
		std::sort(t + 1, t + n + 1);
		ans = (ans + std::equal(s + 1, s + n + 1, t + 1)) % Mod;
	}
	
	std::cout << ans << "\n";
	return 0;
}