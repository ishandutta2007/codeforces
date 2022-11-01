#include <bits/stdc++.h>
using namespace std; 

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

template <class T>
inline void putint(T x) {
	static char buf[25], *tail = buf; 
	if (!x) putchar('0'); 
	else {
		if (x < 0) x = ~x + 1, putchar('-'); 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void tense(T &x, const T &y) {
	if (x > y) x = y; 
}

const int MaxN = 1e5 + 5; 
const int INF = 0x3f3f3f3f; 

int n, p, k; 
int a[MaxN], s[MaxN]; 

void work() {
	int ans = INF; 

	read(n), read(p), read(k); 
	for (int i = 1; i <= n; ++i) {
		scanf("%1d", a + i); 
	}
	
	int x, y; 
	read(x), read(y); 
	
	for (int i = n; i >= 1; --i) {
		s[i] = (i + k <= n ? s[i + k] : 0) + (a[i] ? 0 : x); 
	}
	
	for (int i = p; i <= n; ++i) {
		tense(ans, (i - p) * y + s[i]); 
	}
	
	putint(ans), putchar('\n'); 
}

int main() {
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--) {
		work(); 
	}
	
	return 0; 
}