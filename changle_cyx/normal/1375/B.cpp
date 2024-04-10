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

const int MaxN = 1e3 + 5; 
const int dx[] = {-1, 1, 0, 0}; 
const int dy[] = {0, 0, -1, 1}; 

int n, m, a[MaxN][MaxN], b[MaxN][MaxN]; 

void work() {
	read(n), read(m); 

	bool flag = true; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			read(a[i][j]); 

			int cnt = 0; 
			for (int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir], y = j + dy[dir]; 
				cnt += (x >= 1 && y >= 1 && x <= n && y <= m); 
			}

			if (a[i][j] > cnt) { 
				if (flag) puts("NO"); 
				flag = false; 
			}
			b[i][j] = cnt; 
		}
	}

	if (flag) {
		puts("YES"); 
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				putint(b[i][j]); 
				putchar(" \n"[j == m]); 
			}
		}
	}
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