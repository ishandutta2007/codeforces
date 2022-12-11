#include <bits/stdc++.h>
const int Mod = 998244353;
const int N = 1048576;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = 1LL * a * a % Mod)
	if(b & 1) res = 1LL * res * a % Mod;
	return res;
}

namespace detail
{
	using ull = unsigned long long;
	ull w[N], c[N];
	void init()
	{
		int t = pow_mod(3, (Mod - 1) / N);
		w[N >> 1] = 1;
		for(int i = (N >> 1) + 1; i < N; ++i) w[i] = w[i - 1] * t % Mod;
		for(int i = (N >> 1) - 1; i; --i) w[i] = w[i << 1];
	}
	
	int tr[N];
	void DFT(int f[], int n)
	{
		for(int i = 0; i < n; ++i) tr[i] = ((tr[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0));
		for(int i = 0; i < n; ++i) c[tr[i]] = f[i];
		
		for(int i = 1; i < n; i <<= 1)
		for(int j = 0; j < n; j += (i << 1))
		for(int k = 0; k < i; ++k)
		{
			ull t = c[i + j + k] * w[i + k] % Mod;
			c[i + j + k] = c[j + k] + Mod - t;
			c[j + k] += t;
		}
		
		for(int i = 0; i < n; ++i) f[i] = c[i] % Mod;
	}
	
	void IDFT(int f[], int n)
	{
		DFT(f, n);
		std::reverse(f + 1, f + n);
		int inv = pow_mod(n, Mod - 2);
		for(int i = 0; i < n; ++i) f[i] = 1LL * f[i] * inv % Mod;
	}
}

std::vector<int> mul(std::vector<int> a, std::vector<int> b)
{
	int m = a.size() + b.size() - 1, n = 1;
	while(n < m) n <<= 1;
	a.resize(n); b.resize(n);
	detail::DFT(a.data(), n);
	detail::DFT(b.data(), n);
	for(int i = 0; i < n; ++i) a[i] = 1LL * a[i] * b[i] % Mod;
	detail::IDFT(a.data(), n);
	a.resize(m); return a;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	detail::init();
	
	int T; std::cin >> T;
	while(T--)
	{
		int n; std::cin >> n;
		std::vector<int> Fac(n + 1), FInv(n + 1);
		for(int i = Fac[0] = 1; i <= n; ++i) Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		FInv[n] = pow_mod(Fac[n], Mod - 2);
		for(int i = n; i; --i) FInv[i - 1] = 1LL * FInv[i] * i % Mod;
		
		auto C = [&](int n, int m) -> int
		{
			if(m < 0 || m > n) return 0;
			return 1LL * Fac[n] * FInv[m] % Mod * FInv[n - m] % Mod;
		};
		
		std::vector<int> P(n + 1), Q(n + 1);
		for(int i = 0; i <= n; ++i) P[i] = FInv[i];
		for(int i = 0; 2 * i <= n; ++i) Q[2 * i] = 1LL * pow_mod(FInv[2], i) * FInv[i] % Mod;
		auto F = mul(P, Q);
		for(int i = 0; i <= n; ++i) F[i] = 1LL * F[i] * Fac[i] % Mod;
		
		int ans = 0;
		for(int t = 0; 2 * t <= n; t += 2)
		{
			int z = 1LL * C(n - t, t) * Fac[t] % Mod * FInv[t / 2] % Mod;
			ans = (ans + 1LL * z * F[n - 2 * t]) % Mod;
		}
		
		std::cout << ans << "\n";
	}
	return 0;
}