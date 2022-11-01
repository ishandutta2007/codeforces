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

typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 2e3 + 5; 

int n; 
int a[MaxN << 1]; 
bool f[MaxN][MaxN][2]; 

void work() {
	read(n); 

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i][j][0] = f[i][j][1] = false; 
		}
	}

	for (int i = 1; i <= (n << 1); ++i) {
		read(a[i]); 
	}

	f[1][0][0] = f[0][1][1] = 1; 
	for (int i = 2, cur = a[1]; i <= (n << 1); ++i) {
		for (int s0 = 0; s0 <= i; ++s0) {
			int s1 = i - s0; 
			if (s0 > n || s1 > n) continue; 
			for (int opt = 0; opt <= 1; ++opt) {
			    if (!s0 && !opt) continue; 
			    if (!s1 && !opt) continue; 
			    
				f[s0][s1][opt] |= f[s0 - (opt == 0)][s1 - (opt == 1)][opt]; 
				if (a[i] > cur) {
				    f[s0][s1][opt] |= f[s0 - (opt == 0)][s1 - (opt == 1)][opt ^ 1]; 
				}
			}
		}

		relax(cur, a[i]); 
	}

	puts((f[n][n][0] || f[n][n][1]) ? "YES" : "NO"); 
}

int main() {
#ifdef orzczk
	freopen("a.in", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--) work(); 

	return 0; 
}