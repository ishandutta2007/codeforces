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
	int mod; 

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

const int MaxN = 400 + 5; 

// int C[MaxN][MaxN]; 
// void CInit(int n) {
// 	C[0][0] = 1; 
// 	for (int i = 1; i <= n; ++i) {
// 		C[i][0] = 1; 
// 		for (int j = 1; j <= n; ++j)
// 			add(C[i][j] = C[i - 1][j], C[i - 1][j - 1]); 
// 	}
// }

int fac[MaxN], ind[MaxN]; 

int n; 
int f[MaxN][2][2][MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	std::cin >> n >> mod; 
	// CInit(n); 

	ind[1] = 1; 
	for (int i = 2; i <= n; ++i)
		ind[i] = 1LL * ind[mod % i] * (mod - mod / i) % mod; 

	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j)
			f[0][i][j][0] = 1; 
	
	f[1][0][0][1] = 1; 
	f[1][1][0][1] = f[1][0][1][1] = f[1][1][1][0] = 1; 

	for (int i = 2; i <= n; ++i)
		for (int j = i >> 1; j <= i; ++j)
			for (int op0 = 0; op0 <= 1; ++op0)
				for (int op1 = 0; op1 <= 1; ++op1) {
					int &cf = f[i][op0][op1][j]; 

					s64 s = 0; 
					static s64 M = 1LL * mod * mod * 4; 

					for (int k = 1; k <= i; ++k) {
						int tL = std::max((k - 1) >> 1, j + k - i - 1); 
						int tR = std::min(std::min(k, j - 1 - (i - k) / 2), j - 1); 
						int *fL = f[k - 1][op0][1], *fR = f[i - k][1][op1]; 
						
						for (int t = tL; t <= tR; ++t) {
							s += 1LL * fL[t] * fR[j - t - 1]; 
							if (s >= M) s -= M; 
						}
					}

					cf = s % mod * ind[j] % mod; 
				}

	int ans = 0; 

	fac[0] = 1; 
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1LL * fac[i - 1] * i % mod; 
		add(ans, 1LL * f[n][0][0][i] * fac[i] % mod); 
	}

	std::cout << ans << '\n'; 

	return 0; 
}