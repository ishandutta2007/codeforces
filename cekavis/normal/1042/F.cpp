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
const int N = 1000005;
int n, k, num, ans, h[N], f[N], g[N], pre[N<<1], e[N<<1];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u, int fa=0){
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa) dfs(e[i], u);
	int cnt=0;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa) g[++cnt]=f[e[i]]+1;
	sort(g+1, g+cnt+1);
	while(cnt>1 && g[cnt-1]+g[cnt]>k) --cnt, ++ans;
	f[u]=g[cnt];
}
int main() {
	read(n), read(k);
	for(int i=1; i<n; ++i){
		static int x, y;
		read(x), read(y);
		add(x, y), add(y, x);
	}
	for(int i=1; i<=n; ++i) if(pre[h[i]]){
		dfs(i);
		printf("%d", ans+1);
		return 0;
	}
	return 0;
}