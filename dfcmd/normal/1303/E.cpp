#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
char buf[1 << 23], *ps = buf, *pt = buf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int read(char *s){
	int n = 0;
	char ch = getchar();
	for (; isspace(ch) && ch != EOF; ch = getchar()) ;
	for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
	return s[n] = '\0', n;
}
char pbuf[1 << 23], *pp = pbuf;
#define putchar(x) (pp == pbuf + (1 << 23) ? fwrite(pbuf, 1, 1 << 23, stdout), pp = pbuf : 0, *pp++ = x)
struct __IO_flusher{ ~__IO_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } IO_flusher;
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
void print(const char *s, int n = -1, char ch = '\n'){
	if (n == -1) n = strlen(s);
	for (register int i = 0; i < n; ++i) putchar(s[i]);
	putchar(ch);
}
const int N = 405, INF = 0x3f3f3f3f;
int n, m, f[N][N];
char s[N], t[N];
void solve(){
	n = read(s + 1), m = read(t + 1);
	for (register int p = 1; p <= m; ++p){
		for (register int i = 0; i <= n; ++i)
			for (register int j = 0; j <= p; ++j)
				f[i][j] = -INF;
		f[0][0] = 0;
		for (register int i = 1; i <= n; ++i)
			for (register int j = 0; j <= i && j <= p; ++j){
				int k = f[i - 1][j];
				if (k >= 0) f[i][j] = k + (k <= m - p && s[i] == t[p + k + 1]);
				if (j && s[i] == t[j]) f[i][j] = std::max(f[i][j], f[i - 1][j - 1]);
			}
		if (f[n][p] == m - p) return print("YES"), void(0);
	}
	print("NO");
}
int main(){
	int T = read();
	while (T--) solve();
}