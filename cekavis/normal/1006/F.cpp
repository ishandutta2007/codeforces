#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig = false, c = read(); !isdigit(c); c = read()) {
		if (c == '-') iosig = true;
		if (c == -1) return;
	}
	for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (iosig) x = -x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
const int N = 22;
int n, m, cntg, cntf;
ll ans, v, a[N][N];
pair<int,ll> f[1<<19], g[1<<19];
void dfs1(int x, int y, int st, ll s=0){
	s^=a[x][y];
	if(!st) return (void)(f[++cntf]=make_pair(x, s));
	if(x<n/* && a[x+1][y]*/) dfs1(x+1, y, st-1, s);
	if(y<m/* && a[x][y+1]*/) dfs1(x, y+1, st-1, s);
}
void dfs2(int x, int y, int st, ll s=v){
	if(!st) return (void)(g[++cntg]=make_pair(x, s));
	s^=a[x][y];
	if(x>1/* && a[x-1][y]*/) dfs2(x-1, y, st-1, s);
	if(y>1/* && a[x][y-1]*/) dfs2(x, y-1, st-1, s);
}
int main() {
	// freopen("maze.in", "r", stdin);
	// freopen("maze.out", "w", stdout);
	read(n), read(m), read(v);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) read(a[i][j]);
	dfs1(1, 1, n+m-1>>1);
	dfs2(n, m, n+m-2>>1);
	sort(f+1, f+cntf+1), sort(g+1, g+cntg+1);
	int j=1;
	for(int i=1; i<=cntg; ++i){
		while(f[j]<g[i] && j<cntf) ++j;
		if(f[j]==g[i]){
			int x=j, y=i;
			while(f[x+1]==f[x] && x<cntf) ++x;
			while(g[y+1]==g[y] && y<cntg) ++y;
			ans+=(ll)(x-j+1)*(y-i+1);
			j=x+1, i=y;
		}
	}
	return printf("%lld", ans), 0;
}