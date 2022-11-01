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
int n, k, num, cnt, ans[N], h[N], e[N<<1], pre[N<<1], fa[N][21];
bool vis[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	for(int i=0; fa[u][i]; ++i) fa[u][i+1]=fa[fa[u][i]][i];
	travel(i, u) if(e[i]!=*fa[u]) *fa[e[i]]=u, dfs(e[i]);
}
int main() {
	read(n), read(k);
	rep(i, 2, n){
		static int x, y;
		read(x), read(y);
		add(x, y), add(y, x);
	}
	dfs(n);
	vis[0]=vis[n]=1;
	int tot=1;
	for(int i=n-1; i; --i) if(!vis[i]){
		int tmp=i, dep=1;
		for(int j=20; j--;) if(!vis[fa[tmp][j]]) tmp=fa[tmp][j], dep+=1<<j;
		if(tot+dep<=n-k){
			tot+=dep;
			for(tmp=i; !vis[tmp]; tmp=*fa[tmp]) vis[tmp]=1;
		}
		else ans[++cnt]=i;
	}
	while(cnt) print(ans[cnt--]), print(' ');
	return flush(), 0;
}