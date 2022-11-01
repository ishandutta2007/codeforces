#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt) x = ~x + 1; 
}

const int mod = 998244353; 

inline int qpow(int x, int y) {
	int res = 1; 
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1) res = 1LL * res * x % mod; 
	return res; 
}

const int MaxN = 1e5 + 5; 

int fac[MaxN], ifac[MaxN]; 

inline void facInit(int n) {
	fac[0] = 1; 
	for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % mod; 

	ifac[n] = qpow(fac[n], mod - 2); 
	for (int i = n - 1; i >= 0; --i) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod; 
}

inline int C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0; 
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod; 
}

int n; 
char s[MaxN]; 

void work() {
	scanf("%d%s", &n, s + 1); 
	
	int c = 0, d = n; 
	for (int i = 1; i <= n; ++i)
		if (s[i] == '1') {
			if (i < n && s[i] == s[i + 1]) ++i, ++c; 
			--d; 
		}

	//cerr << c << ' ' << d << '\n'; 

	cout << C(d, c) << '\n'; 
}

int main() {
	facInit(1e5); 

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}