#include <bits/stdc++.h>
const int N = 524288;
const int Mod = 998244353;
const int Inv2 = (Mod + 1) / 2;
using ull = unsigned long long;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = 1LL * a * a % Mod)
	if(b & 1) res = 1LL * res * a % Mod;
	return res; 
}

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

int n, m, a[N], sum[N], f[N], g[N], h[N];
int main()
{
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1, x; i <= m; ++i) std::cin >> x, ++sum[x];
	for(int i = 1; i <= 2 * n; ++i) sum[i] += sum[i - 1];
	
	for(int i = 0; i <= 2 * n; ++i)
	{
		f[i] = pow_mod(Inv2, sum[i]);
		g[i] = pow_mod(2, sum[i]);
	}
	
	auto solve = [&](auto &&self, int l, int r)
	{
		if(l + 1 == r) return;
		int mid = (l + r) / 2;
		if(l + mid >= 2 * n) return;
		self(self, l, mid); self(self, mid, r);
		
		std::vector<int> a(f + mid, f + r), b(g + l, g + mid);
		
		int m = a.size() + b.size() - 1, n = 1;
		while(n < m) n <<= 1;
		a.resize(n); b.resize(n);
		
		DFT(a.data(), n); DFT(b.data(), n);
		for(int i = 0; i < n; ++i) a[i] = 1LL * a[i] * b[i] % Mod;
		IDFT(a.data(), n);
		
		for(int i = 0; i < n; ++i) h[l + mid + i] = (h[l + mid + i] + a[i]) % Mod;
	};
	
	solve(solve, 0, 2 * n);
	
	int ans = 0;
	for(int i = 1; i <= n; ++i) ans = (ans + 1LL * a[i] * h[2 * i - 1]) % Mod;
	
	for(int i = 1; i <= 2 * n; ++i) f[i] = (f[i] + f[i - 1]) % Mod;
	for(int i = 1; i <= n; ++i) ans = (ans + 1LL * a[i] * (f[i + n - 1] - f[2 * i - 1] + Mod)) % Mod;
	
	ans = 1LL * ans * pow_mod(2, m) % Mod;
	for(int i = 1; i <= n; ++i) ans = (ans - 1LL * a[i] * n % Mod + Mod) % Mod;
	std::cout << 1LL * ans * pow_mod(pow_mod(2, m) - 1, Mod - 2) % Mod << "\n";
	return 0;
}