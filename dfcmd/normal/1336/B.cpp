#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

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

const int N = 100005;

int na, nb, nc;
int a[N], b[N], c[N];

long long calc(int i, int j, int k) {
	long long t1 = a[i] - b[j], t2 = b[j] - c[k], t3 = c[k] - a[i];
	return t1 * t1 + t2 * t2 + t3 * t3;
}

void solve() {
	read(na), read(nb), read(nc);
	for (int i = 1; i <= na; ++i) {
		read(a[i]);
	}
	for (int i = 1; i <= nb; ++i) {
		read(b[i]);
	}
	for (int i = 1; i <= nc; ++i) {
		read(c[i]);
	}
	std::sort(a + 1, a + 1 + na);
	std::sort(b + 1, b + 1 + nb);
	std::sort(c + 1, c + 1 + nc);
	long long ans = 4e18;
	for (int i = 1, j, k; i <= na; ++i) {
		j = std::upper_bound(b + 1, b + 1 + nb, a[i]) - b - 1;
		k = std::lower_bound(c + 1, c + 1 + nc, a[i]) - c;
		if (j >= 1 && k <= nc) {
			ans = std::min(ans, calc(i, j, k));
		}
		j = std::lower_bound(b + 1, b + 1 + nb, a[i]) - b;
		k = std::upper_bound(c + 1, c + 1 + nc, a[i]) - c - 1;
		if (j <= nb && k >= 1) {
			ans = std::min(ans, calc(i, j, k));
		}
	}
	for (int i, j = 1, k; j <= nb; ++j) {
		i = std::upper_bound(a + 1, a + 1 + na, b[j]) - a - 1;
		k = std::lower_bound(c + 1, c + 1 + nc, b[j]) - c;
		if (i >= 1 && k <= nc) {
			ans = std::min(ans, calc(i, j, k));
		}
		i = std::lower_bound(a + 1, a + 1 + na, b[j]) - a;
		k = std::upper_bound(c + 1, c + 1 + nc, b[j]) - c - 1;
		if (i <= na && k >= 1) {
			ans = std::min(ans, calc(i, j, k));
		}
	}
	for (int i, j, k = 1; k <= nc; ++k) {
		i = std::upper_bound(a + 1, a + 1 + na, c[k]) - a - 1;
		j = std::lower_bound(b + 1, b + 1 + nb, c[k]) - b;
		if (i >= 1 && j <= nb) {
			ans = std::min(ans, calc(i, j, k));
		}
		i = std::lower_bound(a + 1, a + 1 + na, c[k]) - a;
		j = std::upper_bound(b + 1, b + 1 + nb, c[k]) - b - 1;
		if (i <= na && j >= 1) {
			ans = std::min(ans, calc(i, j, k));
		}
	}
	print(ans);
}

int main() {
	int T = 1;
	read(T);
	while (T--) {
		solve();
	}
}