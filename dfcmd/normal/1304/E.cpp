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
const int N = 100005;
int n, q;
std::vector<int> E[N];
int fa[N][17], dep[N];
void dfs(int u){
	dep[u] = dep[fa[u][0]] + 1;
	for (register int i = 1; i <= 16; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : E[u]) if (v != fa[u][0]) fa[v][0] = u, dfs(v);
}
int LCA(int u, int v){
	if (dep[u] < dep[v]) std::swap(u, v);
	for (register int i = 16; ~i; --i)
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (register int i = 16; ~i; --i)
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int dist(int u, int v){
	return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}
void solve(){
	read(n);
	for (register int i = 1, u, v; i < n; ++i)
		read(u), read(v), E[u].push_back(v), E[v].push_back(u);
	dfs(1);
	read(q);
	while (q--){
		int x, y, u, v, k, d, ans = 0;
		read(x), read(y), read(u), read(v), read(k);
		d = dist(u, v);
		if (k >= d && (k & 1) == (d & 1)) ans = 1;
		d = dist(u, x) + dist(v, y) + 1;
		if (k >= d && (k & 1) == (d & 1)) ans = 1;
		d = dist(u, y) + dist(v, x) + 1;
		if (k >= d && (k & 1) == (d & 1)) ans = 1;
		if (ans) prints("YES"); else prints("NO");
	}
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