#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
const int N = 262144;
const int Mod = 998244353;
using ll = long long;
using ull = unsigned long long;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = 1LL * a * a % Mod)
	if(b & 1) res = 1LL * res * a % Mod;
	return res;
}

namespace NTT
{
	ull w[N], c[N];
	__attribute__((__constructor__)) void init()
	{
		ull t = pow_mod(3, (Mod - 1) / N);
		w[N >> 1] = 1;
		for(int i = (N >> 1) + 1; i < N; ++i) w[i] = w[i - 1] * t % Mod;
		for(int i = (N >> 1) - 1; i >= 1; --i) w[i] = w[i << 1];
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
			c[i + j + k] = c[j + k] - t + Mod;
			c[j + k] += t;
		}
		
		for(int i = 0; i < n; ++i) f[i] = c[i] % Mod;
	}
	
	void IDFT(int f[], int n)
	{
		DFT(f, n);
		std::reverse(f + 1, f + n);
		int t = pow_mod(n, Mod - 2);
		for(int i = 0; i < n; ++i) f[i] = 1LL * f[i] * t % Mod;
	}
}

using NTT::DFT;
using NTT::IDFT;

using poly = std::vector<int>;

poly operator * (poly a, poly b)
{
	int n = a.size() - 1, m = b.size() - 1, len = 1;
	while(len <= n + m) len <<= 1;
	
	a.resize(len); b.resize(len);
	DFT(a.data(), len); DFT(b.data(), len);
	for(int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % Mod;
	IDFT(a.data(), len);
	
	a.resize(n + m + 1);
	return a;
}

poly inv(poly g)
{
	int n = g.size() - 1, len = 1;
	while(len <= n) len <<= 1;
	
	poly f(len); f[0] = pow_mod(g[0], Mod - 2);
	g.resize(len);
	
	for(int t = 1; t < len; t <<= 1)
	{
		poly nf(f.begin(), f.begin() + t), ng(g.begin(), g.begin() + (t << 1));
		nf.resize(t << 2); ng.resize(t << 2);
		DFT(nf.data(), (t << 2)); DFT(ng.data(), (t << 2));
		for(int i = 0; i < (t << 2); ++i)
		nf[i] = (2LL * nf[i] - 1LL * nf[i] * nf[i] % Mod * ng[i] % Mod + Mod) % Mod;
		IDFT(nf.data(), (t << 2));
		std::copy(nf.begin() + t, nf.begin() + (t << 1), f.begin() + t);
	}
	
	f.resize(n + 1);
	return f;
}

std::vector<int> multipleEvaluate(poly f, std::vector<int> x)
{
	auto TpMul = [&](poly a, poly b)
	{
		int n = a.size() - 1, m = b.size() - 1, len = 1;
		while(len <= n) len <<= 1;
		
		a.resize(len); b.resize(len);
		std::reverse(b.begin() + 1, b.end());
		DFT(a.data(), len); DFT(b.data(), len);
		for(int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % Mod;
		IDFT(a.data(), len);
		
		a.resize(n - m + 1);
		return a;
	};
	
	int m = x.size(), n = std::max(f.size(), x.size()), cnt = 0;
	x.resize(n);
	
	std::vector<int> ls(2 * n - 1), rs(2 * n - 1), pos(n);
	
	auto build = [&](auto &&self, int l, int r)
	{
		if(l == r) return (pos[l] = cnt++);
		int k = cnt++, mid = (l + r) / 2;
		ls[k] = self(self, l, mid);
		rs[k] = self(self, mid + 1, r);
		return k;
	};
	
	build(build, 0, n - 1);
	
	std::vector<poly> p(2 * n - 1), q(2 * n - 1);
	for(int i = 0; i < n; ++i) q[pos[i]] = {1, (Mod - x[i]) % Mod};
	
	for(int i = cnt - 1; i >= 0; --i) if(ls[i]) q[i] = q[ls[i]] * q[rs[i]];
	
	f.resize(2 * n);
	p[0] = TpMul(f, inv(q[0]));
	
	for(int i = 0; i < cnt; ++i) if(ls[i])
	p[ls[i]] = TpMul(p[i], q[rs[i]]), p[rs[i]] = TpMul(p[i], q[ls[i]]);
	
	std::vector<int> res(m);
	for(int i = 0; i < m; ++i) res[i] = p[pos[i]][0];
	return res;
}

using Matrix = std::array<std::array<int, 4>, 4>;
const Matrix I = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
const Matrix O = {{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};

Matrix operator + (const Matrix &a, const Matrix &b)
{
	Matrix c = O;
	for(int i = 0; i < 4; ++i)
	for(int j = 0; j < 4; ++j)
	c[i][j] = (a[i][j] + b[i][j]) % Mod;
	return c;
}

Matrix operator * (const Matrix &a, const Matrix &b)
{
	Matrix c = O;
	for(int i = 0; i < 4; ++i)
	for(int j = 0; j < 4; ++j)
	for(int k = 0; k < 4; ++k)
	c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % Mod;
	return c;
}

int n, k, p, a[MaxN], Fac[MaxN], Inv[MaxN], FInv[MaxN];
Matrix M[MaxN];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> k >> p;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	
	Fac[0] = FInv[0] = Fac[1] = Inv[1] = FInv[1] = 1;
	for(int i = 2; i <= std::max(n, k); ++i)
	{
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		Inv[i] = 1LL * (Mod - Mod / i) * Inv[Mod % i] % Mod;
		FInv[i] = 1LL * FInv[i - 1] * Inv[i] % Mod;
	}
	
	poly f(k + 1); f[0] = p - 1;
	for(int i = 1; i <= k; ++i) f[i] = 1LL * FInv[i] * p % Mod;
	f = inv(f);
	
	for(int i = 0; i <= k; ++i) f[i] = 1LL * f[i] * Fac[k] % Mod;
	
	std::reverse(f.begin(), f.end());
	for(int i = 0; i <= k; ++i) f[i] = 1LL * f[i] * FInv[i] % Mod;
	
	std::vector<int> x(n + 1);
	for(int i = 1; i <= n; ++i) x[i] = a[i] + 1;
	std::vector<int> res = multipleEvaluate(f, x);
	
	for(int i = 1; i <= n; ++i)
	{
		int t = (1LL * pow_mod(p, x[i]) * res[i] + Mod - res[0]) % Mod;
		M[i] = {{
			{a[i] + 1, a[i], t, t},
			{0, a[i] + 1, 0, t},
		    {0, 0, a[i] + 1, a[i]},
		    {0, 0, 0, a[i] + 1}
				}};
	}
	
	Matrix sum = O, mul = O;
	for(int i = 1; i <= n; ++i)
	{
		mul = M[i] * (mul + I);
		sum = sum + mul;
	}
	std::cout << sum[0][3] << "\n";
	return 0;
}