#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>
#include<iostream>

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

const int N = 200005, M = 20;
int n, m, q, num, cnt, tot, node, a[N], h[N], fa[N], ans[N], siz[N], stk[N], dep[N], dfn[N], top[N], root[N], last[N];
int e[N<<1], pre[N<<1], s[N<<2], f[N][M], lson[N*M*2], rson[N*M*2], ss[N*M*2];
pair<int,int> b[N];
vector<int> c[N], d[N];
vector<pair<int,int> > w[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs1(int u){
	siz[u]=1;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u])
		fa[e[i]]=u, dep[e[i]]=dep[u]+1, dfs1(e[i]), siz[u]+=siz[e[i]];
}
void dfs2(int u){
	dfn[u]=++cnt, a[cnt]=dep[u];
	int son=0;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u] && siz[e[i]]>siz[son]) son=e[i];
	if(son) top[son]=top[u], dfs2(son);
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u] && e[i]!=son)
		top[e[i]]=e[i], dfs2(e[i]);
	last[u]=cnt;
}
void dfs3(int u){
	stk[++tot]=u, f[u][0]=stk[a[dfn[u]]];
	for(int i=1; i<M; ++i) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u]) dfs3(e[i]);
	--tot;
}
void build(int l, int r, int t){
	s[t]=n;
	if(l==r) return (void)(s[t]=a[l]);
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
}
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(s[t]=min(s[t], x));
	int mid=(l+r)>>1, k=t<<1;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
}
void calc(int l, int r, int t, int x=n){
	x=min(x, s[t]);
	if(l==r) return (void)(a[l]=x);
	int mid=(l+r)>>1, k=t<<1;
	calc(l, mid, k, x), calc(mid+1, r, k|1, x);
}
inline int LCA(int x, int y){
	while(top[x]!=top[y]) if(dep[top[x]]>dep[top[y]]) x=fa[top[x]]; else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
void modify(int l, int r, int &t, int x, int y){
	ss[t?t:t=++node]+=y;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) modify(l, mid, lson[t], x, y);
	else modify(mid+1, r, rson[t], x, y);
}
void merge(int &x, int y){
	if(!x || !y) return (void)(x|=y);
	ss[x]+=ss[y];
	merge(lson[x], lson[y]), merge(rson[x], rson[y]);
}
bool query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return ss[t];
	int mid=(l+r)>>1;
	if(L<=mid && query(l, mid, lson[t], L, R)) return 1;
	if(R>mid && query(mid+1, r, rson[t], L, R)) return 1;
	return 0;
}
void dfs4(int u){
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u])
		dfs4(e[i]), merge(root[u], root[e[i]]);
	for(unsigned i=0; i<c[u].size(); ++i) modify(1, n, root[u], c[u][i], 1);
	for(unsigned i=0; i<d[u].size(); ++i) modify(1, n, root[u], d[u][i], -1);
	for(unsigned i=0; i<w[u].size(); ++i)
		ans[w[u][i].second]+=!query(1, n, root[u], dfn[w[u][i].first], last[w[u][i].first]);
}
int main() {
	read(n);
	for(int i=2, x; i<=n; ++i) read(x), add(x, i), add(i, x);
	top[1]=dep[1]=1, dfs1(1), dfs2(1), build(1, n, 1);
	read(m);
	for(int i=1; i<=m; ++i){
		int x, y, xx, yy;
		read(x), read(y), xx=x, yy=y, c[x].push_back(dfn[y]), c[y].push_back(dfn[x]);
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x, y);
			b[++tot]=make_pair(dfn[top[x]], dfn[x]), x=fa[top[x]];
		}
		if(dep[x]>dep[y]) swap(x, y);
		b[++tot]=make_pair(dfn[x], dfn[y]);
		while(tot) change(1, n, 1, b[tot].first, b[tot].second, dep[x]), --tot;
		d[x].push_back(dfn[xx]), d[x].push_back(dfn[yy]);
	}
	calc(1, n, 1), dfs3(1);
	read(q);
	for(int i=1, x, y, lca; i<=q; ++i){
		read(x), read(y), lca=LCA(x, y);
		if(x==y) continue;
		for(int j=M; j--;){
			if(dep[f[x][j]]>dep[lca]) x=f[x][j], ans[i]+=1<<j;
			if(dep[f[y][j]]>dep[lca]) y=f[y][j], ans[i]+=1<<j;
		}
		if(dep[f[x][0]]>dep[lca] || dep[f[y][0]]>dep[lca]) ans[i]=-1;
		else{
			++ans[i];
			if(x!=lca && y!=lca) w[x].push_back(make_pair(y, i));
		}
	}
	dfs4(1);
	for(int i=1; i<=q; ++i) print(ans[i]), print('\n');
	return flush(), 0;
}