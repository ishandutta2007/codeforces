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

const int MaxN = 1e5 + 5; 

int n; 
char a[MaxN], b[MaxN]; 

void work() {
	scanf("%d%s%s", &n, a + 1, b + 1); 
	for (int i = 1; i <= n; ++i) {
		if (a[i] > b[i]) {
			puts("-1"); 
			return; 
		}
	}

	int res = 0; 
	for (int c = 'a'; c <= 't'; ++c) {
		int minC = 't' + 1, flg = 0; 
		for (int i = 1; i <= n; ++i)
			if (a[i] == c && a[i] < b[i]) {
				tense(minC, (int)b[i]); 
				flg = 1; 
			}
		
		res += flg; 
		for (int i = 1; i <= n; ++i)
			if (a[i] == c && a[i] < b[i]) {
				a[i] = minC; 
			}
	}

	printf("%d\n", res); 
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