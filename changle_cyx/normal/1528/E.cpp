#include <bits/stdc++.h>

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y) {
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

using std::cerr; 
using std::cout; 
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

namespace ModuloCalculator {
	const int mod = 998244353;

	inline void add(int &x, const int &y) {
		x = x + y >= mod ? x + y - mod : x + y;
	}
	inline void dec(int &x, const int &y) {
		x = x - y < 0 ? x - y + mod : x - y;
	}
	inline int plus(int x, const int &y) {
		return add(x, y), x;
	}
	inline int minus(int x, const int &y) {
		return dec(x, y), x;
	}
	inline void addProd(int &x, const int &y, const int &z) {
		x = (1LL * y * z + x) % mod;
	}
	inline void decProd(int &x, const int &y, const int &z) {
		x = (1LL * y * z - x + mod) % mod;
		x = minus(0, x);
	}
	inline int qpow(int x, int y) {
		int res = 1;
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1) res = 1LL * res * x % mod;
		return res;
	}
}
using namespace ModuloCalculator;

const int MaxN = 1e6 + 5; 

int n; 
int f[MaxN], g[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	std::cin >> n; 

	f[0] = 1, g[0] = 1; 
	f[1] = 2, g[1] = 3; 

	int inv2 = (mod + 1) / 2, inv6 = (mod + 1) / 6;
	for (int i = 2; i <= n; ++i) {
		int r1 = f[i - 1]; 
		int r2 = (1LL * g[i - 1] * g[i - 1]
		        - 1LL * g[i - 2] * g[i - 2] % mod + mod
				+ f[i - 1]) % mod; 

		add(g[i] = g[i - 1], f[i] = (r1 + 1LL * r2 * inv2) % mod); 
	}
	
	int r1 = f[n - 1]; 
	int r2 = (1LL * g[n - 1] * g[n - 1]
	        - 1LL * g[n - 2] * g[n - 2] % mod + mod
			+ f[n - 1]) % mod; 
	int r3 = (1LL * g[n - 1] * g[n - 1] % mod * g[n - 1]
		    - 1LL * g[n - 2] * g[n - 2] % mod * g[n - 2] % mod + mod
			+ 3LL * g[n - 1] * g[n - 1]
			- 3LL * g[n - 2] * g[n - 2] % mod + mod
			+ 2LL * f[n - 1]) % mod; 
	
	int ans = (r1 + 1LL * r2 * inv2 + 2LL * r3 * inv6) % mod; 
	for (int i = 1; i <= n; ++i) {
		ans = (ans + 1LL * minus(f[i], f[i - 1]) * (i == n ? 1 : f[n - i - 1])) % mod; 
	}

	std::cout << ans << '\n'; 

	return 0; 
}