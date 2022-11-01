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
const int N = 2005, M = 2000005;
int t, ans, n, m, r, c, x, y, cnt, num, tot[M], h[M], tot0[M], tot1[M], q[M], id[N][N], e[M<<2], pre[M<<2];
char s[N][N];
bool vis[M], w[M<<2];
inline void add(int x, int y, bool z){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
int main() {
	read(n), read(m), read(r), read(c), read(x), read(y);
	for(int i=1; i<=n; ++i){
		while(isspace(s[i][1]=read()));
		for(int j=2; j<=m; ++j) s[i][j]=read();
	}
	bool f=0;
	for(int j=1; j<=m; ++j){
		for(int i=1; i<=n; ++i) if(s[i][j]=='.'){
			if(!f) f=1, ++cnt;
			id[i][j]=cnt, ++tot[cnt];
		}
		else f=0;
		f=0;
	}
	// for(int i=1; i<=n; ++i){
	// 	for(int j=1; j<=m; ++j) printf("%d ", id[i][j]);
	// 	puts("");
	// }
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(s[i][j]=='.'){
		if(s[i][j-1]=='.') add(id[i][j], id[i][j-1], 0);
		if(s[i][j+1]=='.') add(id[i][j], id[i][j+1], 1);
	}
	vis[q[t=1]=id[r][c]]=1;
	for(int l=1; l<=t; ++l){
		int u=q[l];
		// printf(">>%d\n", u);
		for(int i=h[u]; i; i=pre[i]) if(!vis[e[i]]){
			vis[e[i]]=1, tot0[e[i]]=tot0[u], tot1[e[i]]=tot1[u];
			if(w[i]) ++tot1[e[i]]; else ++tot0[e[i]];
			if(tot0[e[i]]<=x && tot1[e[i]]<=y) q[++t]=e[i];
		}
		ans+=tot[u];
	}
	return printf("%d", ans), 0;
}