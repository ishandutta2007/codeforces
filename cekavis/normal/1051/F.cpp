#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<queue>

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
const int N = 100005, M = 22;
int cnt, num, n, m, Q, x[N], y[N], z[N], top[N], fa[N], siz[N], h[N], e[N<<1], w[N<<1], pre[N<<1];
ll dep[N], xx[M][N], yy[M][N];
bool tr[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
inline void add(int x, int y, int z){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
void dfs1(int u){
	siz[u]=1;
	for(int i=h[u]; i; i=pre[i]) if(!siz[e[i]]) tr[i+1>>1]=1, fa[e[i]]=u, dep[e[i]]=dep[u]+w[i], dfs1(e[i]), siz[u]+=siz[e[i]];
}
void dfs2(int u){
	int son=0;
	for(int i=h[u]; i; i=pre[i]) if(tr[i+1>>1] && e[i]!=fa[u] && siz[e[i]]>siz[son]) son=e[i];
	if(son) top[son]=top[u], dfs2(son);
	for(int i=h[u]; i; i=pre[i]) if(tr[i+1>>1] && e[i]!=fa[u] && e[i]!=son) top[e[i]]=e[i], dfs2(e[i]);
}
inline int lca(int x, int y){
	while(top[x]!=top[y]) if(dep[top[x]]>dep[top[y]]) x=fa[top[x]]; else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
inline void dij(int s, ll *dis){
	memset(dis, 0x3f3f3f3f, n+1<<3);
	q.push(make_pair(dis[s]=0, s));
	while(!q.empty()){
		pair<ll,int> tmp=q.top(); q.pop();
		int u=tmp.second;
		if(dis[u]==tmp.first) for(int i=h[u]; i; i=pre[i]) if(dis[u]+w[i]<dis[e[i]]) q.push(make_pair(dis[e[i]]=dis[u]+w[i], e[i]));
	}
}
int main() {
	read(n), read(m);
	for(int i=1; i<=m; ++i){
		read(x[i]), read(y[i]), read(z[i]);
		add(x[i], y[i], z[i]), add(y[i], x[i], z[i]);
	}
	dfs1(1), top[1]=1, dfs2(1);
	for(int i=1; i<=m; ++i) if(!tr[i]) x[++cnt]=x[i], y[cnt]=y[i], z[cnt]=z[i], dij(x[cnt], xx[cnt]), dij(y[cnt], yy[cnt]);
	read(Q);
	while(Q--){
		static int x, y;
		read(x), read(y);
		ll ans=dep[x]+dep[y]-dep[lca(x, y)]*2;
		for(int i=1; i<=cnt; ++i) ans=min(ans, min(xx[i][x]+yy[i][y], xx[i][y]+yy[i][x])+z[i]);
		print(ans), print('\n');
	}
	return flush(), 0;
}