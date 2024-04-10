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
	const int mod = 1e9 + 7;

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

	const int ModLen = 3e5 + 5; 
	
	int ind[ModLen]; 
	int fac[ModLen], facInv[ModLen]; 
	
	inline void facInit(int n) {
		fac[0] = facInv[0] = 1; 
		for (int i = 1; i <= n; ++i) {
			ind[i] = i == 1 ? 1 : 1LL * ind[mod % i] * (mod - mod / i) % mod; 
			fac[i] = 1LL * fac[i - 1] * i % mod; 
			facInv[i] = 1LL * facInv[i - 1] * ind[i] % mod; 
		}
	}
	inline int C(int n, int m) {
		// cerr << n << ' ' << m << '\n'; 
		if (n < 0 || m < 0 || n < m)
			return 0; 
		return 1LL * fac[n] * facInv[m] % mod * facInv[n - m] % mod; 
	}

	struct czk{czk(){facInit(ModLen - 1);}}czkhuge; 
}
using namespace ModuloCalculator;

int n, K; 

inline int solve(int p) {
	if (n - 1LL * (K - 2) * (p - 1) - p + 1 >= 0)
		return C(n - (K - 2) * (p - 1) - p + 1, p); 
	else
		return 0; 
}

void work() {
	read(n), read(K); 

	int ans = 1; 
	for (int i = 1; i <= n; ++i) {
		add(ans, 1LL * solve(i) * qpow(C(n, i), mod - 2) % mod); 
	}

	printf("%d\n", ans); 
}

int main() {
#ifdef orzczk
	freopen("/mnt/c/cyx/project/a.in", "r", stdin); 
//	freopen("/mnt/c/cyx/project/a.out", "w", stdout);  
#endif

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}