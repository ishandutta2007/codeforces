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

int n, a[MaxN], s[MaxN]; 

void work() {
	read(n); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]); 
		s[i] = s[i - 1] ^ a[i]; 
	}
	
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > (a[i + 1] ^ a[i + 2])) {
			puts("1"); 
			return; 
		}
	}
	
	int ans = n + 1; 
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = i; k < j; ++k)
				if ((s[k] ^ s[i - 1]) > (s[j] ^ s[k])) {
					tense(ans, k - i + j - k - 1); 
				}
	
	if (ans == n + 1)
		puts("-1"); 
	else
		printf("%d\n", ans); 
}

int main() {
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	int T = 1; 
//	read(T); 
	while (T--) {
		work(); 
	}
	
	return 0; 
}