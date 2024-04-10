#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
char buf[1 << 23], *ps = buf, *pt = buf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
long long read(){
	register long long x = 0;
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
int n, a[100];
long long m;
void solve(){
	m = read(), n = read();
	for (register int i = 0; i < 60; ++i) a[i] = 0;
	for (register int i = 1; i <= n; ++i){
		int x = read(), k = 0;
		while (x > 1) x >>= 1, ++k;
		++a[k];
	}
	int ans = 0;
	for (register int i = 0, k = 0; i < 60; ++i){
		if (m >> i & 1){
			while (k < 60 && !a[k]) ++k;
			if (k == 60) return print(-1), void(0);
			--a[k], m ^= 1ll << i, ans += k - i;
			for (register int j = i; j < k; ++j) ++a[j];
			k = i;
		}
		a[i + 1] += a[i] >> 1, a[i] = 0;
	}
	if (m) return print(-1), void(0);
	print(ans);
}
int main(){
	int T = read();
	while (T--) solve();
}