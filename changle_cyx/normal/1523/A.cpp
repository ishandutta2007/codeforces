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

const int MaxN = 1000 + 5; 
const int INF = 0x3f3f3f3f; 

int n, m; 
char s[MaxN]; 

int lst[MaxN], nxt[MaxN]; 

int main() {
#ifdef orzczk
	freopen("/mnt/c/cyx/project/a.in", "r", stdin); 
//	freopen("/mnt/c/cyx/project/a.out", "w", stdout);  
#endif

	int T; 
	read(T); 
	while (T--) {
		read(n), read(m); 
		scanf("%s", s + 1); 

		lst[0] = -INF; 
		for (int i = 1; i <= n; ++i) {
			lst[i] = s[i] == '1' ? i : lst[i - 1]; 
		}

		nxt[n + 1] = INF; 
		for (int i = n; i >= 1; --i) {
			nxt[i] = s[i] == '1' ? i : nxt[i + 1]; 
		}

		for (int i = 1; i <= n; ++i)
			putchar(std::min(i - lst[i], nxt[i] - i) <= m
			    && (s[i] == '1' || i - lst[i] != nxt[i] - i) ? '1' : '0'); 
		putchar('\n'); 
	}

	return 0; 
}