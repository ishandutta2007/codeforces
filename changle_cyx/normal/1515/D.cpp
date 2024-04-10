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

const int MaxN = 2e5 + 5; 

int n, nL, nR;
int c[MaxN][2], a[MaxN]; 

void work() {
	read(n), read(nL), read(nR); 

	for (int i = 1; i <= n; ++i)
		c[i][0] = c[i][1] = 0; 
	
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		++c[a[i]][i <= nL ? 0 : 1]; 
	}
	
	int ans = 0, cL = 0, cR = 0; 
	for (int i = 1; i <= n; ++i) {
		while (c[i][0] && c[i][1]) {
			--c[i][0], --c[i][1]; 
		}

		cL += c[i][0]; 
		cR += c[i][1]; 
	}

	for (int i = 1; i <= n; ++i) {
		while (cL > cR && c[i][0] > 1) {
			c[i][0] -= 2, ++ans; 
			cL -= 2; 
		}
		while (cR > cL && c[i][1] > 1) {
			c[i][1] -= 2, ++ans; 
			cR -= 2; 
		}
	}

	// ans += std::min(cL, cR); 
	ans += std::max(cL, cR); //- std::min(cL, cR); 

	printf("%d\n", ans); 
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