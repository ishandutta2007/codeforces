#include <bits/stdc++.h>

using std::cerr; 

const int mod = 1e9 + 7; 

inline void add(int &x, const int &y) {
	if (x += y, x >= mod) x -= mod; 
}

inline void dec(int &x, const int &y) {
	if (x -= y, x < 0) x += mod; 
}

inline int qpow(int x, int y) {
	int res = 1; 
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1) res = 1LL * res * x % mod; 
	return res; 
}

const int MaxK = 1e6 + 5; 

struct lagrange {
	int n, a[MaxK]; // 1 ~ n
	int fac[MaxK], facInv[MaxK]; 
	
	void init(int *y, int m) {
		n = m, fac[0] = 1; 
		for (int i = 1; i <= n; ++i) {
			a[i] = y[i]; 
			fac[i] = 1LL * fac[i - 1] * i % mod; 
		}
		facInv[n] = qpow(fac[n], mod - 2); 
		for (int i = n - 1; i >= 0; --i) {
			facInv[i] = 1LL * facInv[i + 1] * (i + 1) % mod; 
		}
	}
	
	inline int f(int x) { // sum 0^k ~ (x-1)^k
		if (x <= n) return a[x]; 
		
		static int pre[MaxK], suf[MaxK]; 
		pre[1] = x - 1, suf[n] = x - n, suf[n + 1] = pre[0] = 1; 
		for (int i = 2; i <= n; ++i) {
			pre[i] = 1LL * pre[i - 1] * (x - i) % mod; 
		}
		for (int i = n - 1; i >= 1; --i) {
			suf[i] = 1LL * suf[i + 1] * (x - i) % mod; 
		}
		
		int res = 0; 
		for (int i = 1; i <= n; ++i) {
			int d1 = 1LL * pre[i - 1] * suf[i + 1] % mod; 
			int d2 = 1LL * facInv[i - 1] * facInv[n - i] % mod; 
			((n - i) & 1 ? dec : add)(res, 1LL * a[i] * d1 % mod * d2 % mod); 
		}
		return res; 
	}
}S; 

int n, K, pw[MaxK]; 

void sieve(int n) {
	static int sie[MaxK], pri[MaxK], nP; 
	
	pw[0] = K ? 0 : 1, pw[1] = 1; 
	for (int i = 2; i <= n; ++i) {
		if (!sie[i]) {
			pri[++nP] = i; 
			pw[i] = qpow(i, K); 
		}
		for (int j = 1; j <= nP && i * pri[j] <= n; ++j) {
			int x = i * pri[j]; 
			sie[x] = true; 
			pw[x] = 1LL * pw[i] * pw[pri[j]] % mod; 
			if (x % pri[j] == 0) break; 
		}
	}
	for (int i = 1; i <= n; ++i) add(pw[i], pw[i - 1]); 
	for (int i = n + 1; i >= 1; --i) pw[i] = pw[i - 1]; 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	std::cin >> n >> K; 
	
	sieve(K + 1); 
	S.init(pw, K + 2); 
	std::cout << S.f(n + 1) - (!K) << std::endl; 
	
	return 0; 
}