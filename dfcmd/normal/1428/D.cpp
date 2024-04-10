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

const int N = 100005;

int n;
int a[N], c[N], matched[N];

void solve() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		matched[i] = 0;
	}
	std::vector<std::pair<int, int>> ans;
	int lst = 0, now = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 3) {
			lst = i;
			if (now) {
				ans.push_back({now, i});
			}
			ans.push_back({++now, i});
			c[i] = now;
		}
	}
	std::vector<int> sta;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 2) {
			sta.push_back(i);
			ans.push_back({++now, i});
			c[i] = now;
		} else if (a[i] == 1) {
			if (sta.empty()) {
				ans.push_back({++now, i});
			} else {
				ans.push_back({c[sta.back()], i});
				sta.pop_back();
				matched[i] = 1;
			}
		}
	}
	if (!sta.empty()) {
		print(-1);
		return;
	}
	if (lst) {
		bool flag = 0;
		for (int i = lst + 1; i <= n; ++i) {
			if (a[i] > 0 && !matched[i]) {
				ans.push_back({c[lst], i});
				flag = 1;
				break;
			}
		}
		if (!flag) {
			print(-1);
			return;
		}
	}
	print((int)ans.size());
	for (auto v : ans) {
		print(v.first, ' '), print(v.second);
	}
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}