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
const int N = 200005;
int n, now, p[N];
char s[N];
void solve(){
	read(n), reads(s + 1);
	s[0] = '<', s[n] = '>';
	now = n;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == '>') p[i] = now--;
	now = 0;
	for (register int i = n; i; --i)
		if (s[i - 1] == '>' && s[i] == '<') p[i] = ++now;
	for (register int i = n, j; i; i = j){
		j = i;
		while (j && s[j - 1] == '<' && s[j] == '<') --j;
		if (j == i){ --j; continue; }
		for (register int k = j + 1; k <= i; ++k) p[k] = ++now;
	}
	for (register int i = 1; i <= n; ++i) print(p[i], ' '); putchar('\n');
	now = 0;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == '<') p[i] = ++now;
	now = n;
	for (register int i = n; i; --i)
		if (s[i - 1] == '<' && s[i] == '>') p[i] = now--;
	for (register int i = 1; i <= n; ++i)
		if (s[i - 1] == '>' && s[i] == '>') p[i] = now--;
	for (register int i = 1; i <= n; ++i) print(p[i], ' '); putchar('\n');
}
int main(){
	int T = 1;
	read(T);
	while (T--) solve();
}
/*
1
13 >><<<><>><<>
13 12 3 5 6 11 2 10 9 1 4 8 7 
10 9 1 2 3 11 4 12 8 5 6 13 7 
*/