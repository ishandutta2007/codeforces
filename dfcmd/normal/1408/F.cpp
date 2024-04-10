#include <bits/stdc++.h>

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
		static int num[40];
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (*num = 0; x; x /= 10) {
			num[++*num] = x % 10;
		}
		while (*num){
			putchar(num[*num] ^ '0');
			--*num;
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

int n;
std::vector<std::pair<int, int>> ans;

void merge(int l1, int l2, int len) {
	for (int i = 0; i < len; ++i) {
		ans.push_back({l1 + i, l2 + i});
	}
}

void solve(int l, int r) {
	if (l + 1 == r) {
		return;
	}
	int md = (l + r + 1) >> 1;
	solve(l, md), solve(md, r);
	merge(l, md, md - l);
}

int main() {
	read(n);
	int k = 0;
	while (n >> (k + 1)) {
		++k;
	}
	int now = 0, lst = k;
	for (int i = k - 1; ~i; --i) {
		if (n >> i & 1) {
			solve(now, now + (1 << i));
			now += 1 << i;
			lst = i;
		}
	}
	solve(now, now + (1 << k));
	for (int i = lst; i < k; ++i) {
		if (n >> i & 1 && i != lst) {
			merge(now - (1 << (i + 1)), now - (1 << i), 1 << i);
		} else {
			merge(now - (1 << i), now, 1 << i);
			now += 1 << i;
		}
	}
	print((int)ans.size());
	for (auto v : ans) {
		print(v.first + 1, ' '), print(v.second + 1);
	}
}