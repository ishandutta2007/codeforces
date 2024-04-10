#include <bits/stdc++.h>
const int MaxN = 262144 + 5;
const int Mod = 998244353;

int pow_mod(int a, int b, int res = 1)
{
	for(; b; b >>= 1, a = int64_t(a) * a % Mod)
	if(b & 1) res = int64_t(res) * a % Mod;
	return res;
}

namespace detail
{
	uint64_t w[MaxN], c[MaxN];
	__attribute__((constructor)) void Init()
	{
		const int n = 262144, t = pow_mod(3, (Mod - 1) / n);
		w[n >> 1] = 1;
		for(int i = (n >> 1) + 1; i < n; ++i) w[i] = w[i - 1] * t % Mod;
		for(int i = (n >> 1) - 1; i; --i) w[i] = w[i << 1];
	}
}

void NTT(int *f, int n, int op)
{
	static int r[MaxN];
	using namespace detail;
	
	std::copy(f, f + n, c);
	for(int i = 0; i < n; ++i) r[i] = ((r[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0));
	for(int i = 0; i < n; ++i) if(i < r[i]) std::swap(c[i], c[r[i]]);
	
	for(int i = 1; i < n; i <<= 1)
	for(int j = 0; j < n; j += i * 2)
	for(int k = 0; k < i; ++k)
	{
		uint64_t t = c[i + j + k] * w[i + k] % Mod;
		c[i + j + k] = c[j + k] + Mod - t;
		c[j + k] = c[j + k] + t;
	}
	
	if(op == -1)
	{
		std::reverse(c + 1, c + n);
		for(int i = 0, t = pow_mod(n, Mod - 2); i < n; ++i) c[i] = c[i] % Mod * t;
	}
	for(int i = 0; i < n; ++i) f[i] = c[i] % Mod;
}

struct Poly : std::vector<int>
{
	template<typename... Args>
	Poly(Args... args): std::vector<int>(args...) {}
	void reduce() {while(size() > 1 && back() == 0) pop_back();}
	
	friend Poly operator * (Poly F, Poly G)
	{
		int t = F.size() + G.size() - 1, n = 1;
		while(n < t) n <<= 1;
		F.resize(n); G.resize(n);
		NTT(F.data(), n, 1); NTT(G.data(), n, 1);
		for(int i = 0; i < n; ++i) F[i] = int64_t(F[i]) * G[i] % Mod;
		NTT(F.data(), n, -1);
		F.reduce(); return F;
	}
};

int C(int n, int m)
{
	int64_t a = 1, b = 1;
	for(int i = 1; i <= m; ++i) a = a * (n - i + 1) % Mod, b = b * i % Mod;
	return a * pow_mod(b, Mod - 2) % Mod;
}

int main()
{
	int n, a, b; std::cin >> n >> a >> b;
	if(a + b - 1 > n) {std::cout << 0 << "\n"; return 0;}
	if(n == 1 || a == 0 || b == 0) {std::cout << a * b << std::endl; return 0;}
	
	std::function<Poly(int, int)> solve = [&](int l, int r)
	{
		if(l + 1 == r) return Poly{std::vector<int>{l, 1}};
		int mid = (l + r) / 2;
		return solve(l, mid) * solve(mid, r);
	};
	
	std::cout << int64_t(solve(0, n - 1)[a + b - 2]) * C(a + b - 2, a - 1) % Mod << "\n";
	return 0;
}