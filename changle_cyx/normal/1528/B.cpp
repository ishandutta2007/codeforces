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
int f[MaxN], d[MaxN]; 

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	std::cin >> n; 

	f[0] = 1; 

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			++d[j]; 
	
	for (int i = 1, sum = 1; i <= n; ++i) {
		f[i] = sum; 
		add(f[i], d[i] - 1); 
		add(sum, f[i]); 

		// cerr << i << ' ' << f[i] << '\n'; 
	}

	std::cout << f[n] << '\n'; 

	return 0; 
}