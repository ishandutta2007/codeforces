#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
namespace fastIO{
#define getchar() my_getchar()
#define putchar(x) my_putchar(x)
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
	char buf[IN_BUF], *ps = buf, *pt = buf;
	inline char my_getchar() {
		return ps == pt && (pt = (ps = buf) + fread(buf, 1, IN_BUF, stdin), ps == pt) ? EOF : *ps++;
	}
	template<typename T> inline bool read(T &x){
		char op = 0, ch = getchar();
		for (x = 0; !isdigit(ch) && ch != EOF; ch = getchar()) if (ch == '-') op ^= 1;
		if (ch == EOF) return false;
		for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ '0');
		if (ch != '.') return op ? x = -x : 0, true; else ch = getchar();
		T t = 1;
		for (; isdigit(ch); ch = getchar()) t /= 10, x += (ch ^ '0') * t;
		return op ? x = -x : 0, true;
	}
	inline int reads(char *s){
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar()) ;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
		return s[n] = '\0', n;
	}
	char pbuf[OUT_BUF], *pp = pbuf;
	struct _flusher{ ~_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } OutputFlusher;
	inline void my_putchar(char x){
		pp == pbuf + OUT_BUF ? fwrite(pbuf, 1, OUT_BUF, stdout), pp = pbuf : 0, *pp++ = x;
	}
	template<typename T> inline void print_(T x){
		if (x == 0) return putchar('0'), void(0);
		int cnt = 0, num[25];
		for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
		while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	}
	template<typename T> inline void print(T x, char ch = '\n'){
		print_(x), putchar(ch);
	}
	inline void prints_(const char *s, int n = -1){
		if (n == -1) n = strlen(s);
		for (register int i = 0; i < n; ++i) putchar(s[i]);
	}
	inline void prints(const char *s, int n = -1, char ch = '\n'){
		prints_(s, n), putchar(ch);
	}
	template<typename T> inline void printd_(T x, int n){
		if (x < 0) x = -x, putchar('-');
		long long a, b;
		if (n == 0) return a = x + 0.5, print_(a), void(0);
		a = x, x -= a;
		while (n--) x *= 10;
		b = x + 0.5;
		print_(a), putchar('.'), print_(b);
	}
	template<typename T> inline void printd(T x, int n, char ch = '\n'){
		printd_(x, n), putchar(ch);
	}
}
using namespace fastIO;
const int N = 55, M = 20005;
int n, m, L, a[N][M], f[N][M];
void solve(){
	read(n), read(m), read(L);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			read(a[i][j]), a[i][j] += a[i][j - 1];
	for (register int i = L; i <= m; ++i)
		f[1][i] = a[1][i] - a[1][i - L];
	for (register int i = 2; i <= n; ++i){
		for (register int j = L; j <= m; ++j) f[i][j] = 0;
		for (register int j = L + L, s = 0; j <= m; ++j){
			s = std::max(f[i - 1][j - L] + a[i][j - L] - a[i][j - 2 * L], s);
			f[i][j] = std::max(f[i][j], s + a[i][j] - a[i][j - L]);
		}
		for (register int j = m - L, s = 0; j >= L; --j){
			s = std::max(f[i - 1][j + L] + a[i][j + L] - a[i][j], s);
			f[i][j] = std::max(f[i][j], s + a[i][j] - a[i][j - L]);
		}
		for (register int j = L; j <= m; ++j){
			for (register int k = std::max(L, j - L + 1); k <= j; ++k)
				f[i][j] = std::max(f[i][j], f[i - 1][k] + a[i][j] - a[i][k - L]);
			for (register int k = std::min(m, j + L - 1); k >= j; --k)
				f[i][j] = std::max(f[i][j], f[i - 1][k] + a[i][k] - a[i][j - L]);
		}
	}
	int ans = 0;
	for (register int i = L; i <= m; ++i) ans = std::max(ans, f[n][i]);
	print(ans);
}
int main(){
	int T = 1;
	// read(T);
	while (T--) solve();
}
/*
1
13 >><<<><>><<>
13 12 3 5 6 11 2 10 9 1 4 8 7 
10 9 1 2 3 11 4 12 8 5 6 13 7 
*/