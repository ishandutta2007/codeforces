#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}

	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		std::vector<int> num;
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
			num.pop_back();
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;

const int N = 1100005;

int h, g, n;
int a[N], son[N], dep[N], ds[N];

void erase(int u) {
	if (!son[u]) {
		a[u] = 0;
		return;
	}
	a[u] = a[son[u]], erase(son[u]);
	if (a[u << 1] > a[u << 1 | 1]) {
		son[u] = u << 1;
	} else {
		son[u] = u << 1 | 1;
	}
	if (!a[son[u]]) {
		son[u] = 0, ds[u] = dep[u];
	} else {
		ds[u] = ds[son[u]];
	}
}

void solve() {
	read(h), read(g), n = (1 << h) - 1;
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		son[i] = 0;
	}
	dep[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dep[i] = dep[i >> 1] + 1;
	}
	for (register int i = 1; i <= (n >> 1); ++i) {
		if (a[i << 1] > a[i << 1 | 1]) {
			son[i] = i << 1;
		} else {
			son[i] = i << 1 | 1;
		}
	}
	for (register int i = n; i; --i) {
		if (!son[i]) {
			ds[i] = dep[i];
		} else {
			ds[i] = ds[son[i]];
		}
	}
	std::vector<int> p;
	for (int i = 1, u = 1; i <= n; ++i) {
		while (u <= n && (!a[u] || ds[u] <= g)) ++u;
		if (u <= n) {
			erase(u);
			p.push_back(u);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += a[i];
	}
	print(ans);
	for (int v : p) {
		print(v, ' ');
	}
	putchar('\n');
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}