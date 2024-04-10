#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])

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
int n, ch[N][2];
char opt[N];
bool f[N], vis[N];
inline void dfs(int u){
	if(ch[u][0]) dfs(ch[u][0]);
	if(ch[u][1]) dfs(ch[u][1]);
	if(opt[u]=='A') f[u]=f[ch[u][0]]&f[ch[u][1]];
	if(opt[u]=='X') f[u]=f[ch[u][0]]^f[ch[u][1]];
	if(opt[u]=='O') f[u]=f[ch[u][0]]|f[ch[u][1]];
	if(opt[u]=='N') f[u]=!f[ch[u][0]];
}
inline void dfs2(int u){
	vis[u]=1;
	if(ch[u][0]){
		if(opt[u]=='N' || opt[u]=='A' && (!f[ch[u][0]]&f[ch[u][1]])!=f[u] || opt[u]=='O' && (!f[ch[u][0]]|f[ch[u][1]])!=f[u] || opt[u]=='X' && (!f[ch[u][0]]^f[ch[u][1]])!=f[u]) dfs2(ch[u][0]);
	}
	if(ch[u][1]){
		if(opt[u]=='A' && (f[ch[u][0]]&!f[ch[u][1]])!=f[u] || opt[u]=='O' && (f[ch[u][0]]|!f[ch[u][1]])!=f[u] || opt[u]=='X' && (f[ch[u][0]]^!f[ch[u][1]])!=f[u]) dfs2(ch[u][1]);
	}
}
int main() {
	read(n);
	rep(i, 1, n){
		while(isspace(opt[i]=read()));
		if(opt[i]=='A' || opt[i]=='O' || opt[i]=='X') read(ch[i][0]), read(ch[i][1]);
		else if(opt[i]=='N') read(ch[i][0]);
		else read(f[i]);
	}
	dfs(1), dfs2(1);
	rep(i, 1, n) if(opt[i]=='I') print(f[1]^vis[i]);
	return flush(), 0;
}