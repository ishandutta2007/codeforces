#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005, M = 500005;
int n, m, q, num, cnt, stop, p, stk[N], dfn[N], low[N], h[N], top[N<<1], siz[N<<1], dep[N<<1], fa[N<<1], e[M<<1], pre[M<<1];
vector<int> a[N<<1];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	stk[++stop]=u;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u]){
		if(!dfn[e[i]]){
			tarjan(e[i]), low[u]=min(low[u], low[e[i]]);
			if(low[e[i]]>=dfn[u]){
				++p;
				a[u].push_back(p);
				do a[p].push_back(stk[stop]); while(stk[stop--]!=e[i]);
			}
		}
		else low[u]=min(low[u], dfn[e[i]]);
	}
}
void dfs1(int u){
	siz[u]=1;
	for(int v:a[u]) fa[v]=u, dep[v]=dep[u]+1, dfs1(v), siz[u]+=siz[v];
}
void dfs2(int u){
	int son=0;
	for(int v:a[u]) if(siz[v]>siz[son]) son=v;
	if(son) top[son]=top[u], dfs2(son);
	for(int v:a[u]) if(v!=son) top[v]=v, dfs2(v);
}
int main() {
	read(n), read(m), read(q), p=n;
	for(int i=1, x, y; i<=m; ++i) read(x), read(y), add(x, y), add(y, x);
	tarjan(1);
	dfs1(1), top[1]=1, dfs2(1);
	while(q--){
		static int x, y, ans;
		read(x), read(y);
		ans=dep[x]+dep[y];
		while(top[x]!=top[y]) if(dep[top[x]]<dep[top[y]]) y=fa[top[y]]; else x=fa[top[x]];
		print(ans/2-min(dep[x], dep[y])), print('\n');
	}
	return flush(), 0;
}