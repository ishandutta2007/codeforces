#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>

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

const int N = 100005, inf = 1e9;
int n, m, q, num, cnt, stop, p, low[N], stk[N], w[N], h[N], siz[N<<1], top[N<<1], e[N<<1], pre[N<<1], dfn[N<<1], fa[N<<1], b[N<<1], dep[N<<1], s[N<<3];
vector<int> a[N<<1];
struct heap{
	priority_queue<int, vector<int>, greater<int>> a, b;
	inline void push(int x){ a.push(x);}
	inline void erase(int x){ b.push(x);}
	inline int top(){
		while(b.size() && a.top()==b.top()) a.pop(), b.pop();
		return a.top();
	}
} f[N];
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
				do
					a[p].push_back(stk[stop]), f[p-n].push(w[stk[stop]]);
				while(stk[stop--]!=e[i]);
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
	dfn[u]=++cnt, b[dfn[u]]=(u>n?f[u-n].top():inf);
	int son=0;
	for(int v:a[u]) if(siz[v]>siz[son]) son=v;
	if(son) top[son]=top[u], dfs2(son);
	for(int v:a[u]) if(v!=son) top[v]=v, dfs2(v);
}
void build(int l, int r, int t){
	if(l==r) return (void)(s[t]=b[l]);
	int mid=(l+r)/2, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=min(s[k], s[k|1]);
}
void modify(int l, int r, int t, int x, int y){
	if(l==r) return (void)(s[t]=y);
	int mid=(l+r)/2, k=t<<1;
	if(x<=mid) modify(l, mid, k, x, y); else modify(mid+1, r, k|1, x, y);
	s[t]=min(s[k], s[k|1]);
}
int query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return s[t];
	int mid=(l+r)/2, k=t<<1;
	return min(L<=mid?query(l, mid, k, L, R):inf, R>mid?query(mid+1, r, k|1, L, R):inf);
}
int main() {
	read(n), read(m), read(q), p=n;
	for(int i=1; i<=n; ++i) read(w[i]);
	for(int i=1, x, y; i<=m; ++i) read(x), read(y), add(x, y), add(y, x);
	tarjan(1);
	dfs1(1), top[1]=1, cnt=0, dfs2(1);
	build(1, p, 1);
	while(q--){
		static char opt;
		static int x, y;
		while(isspace(opt=read()));
		read(x), read(y);
		if(opt=='C'){
			if(x!=1){
				f[fa[x]-n].erase(w[x]), f[fa[x]-n].push(y);
				modify(1, p, 1, dfn[fa[x]], f[fa[x]-n].top());
			}
			w[x]=y;
		}
		else{
			int ans=inf;
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]]) swap(x, y);
				ans=min(ans, query(1, p, 1, dfn[top[x]], dfn[x]));
				x=fa[top[x]];
			}
			if(dep[x]>dep[y]) swap(x, y);
			ans=min(ans, query(1, p, 1, dfn[x], dfn[y]));
			print(min(ans, x>n?w[fa[x]]:w[x])), print('\n');
		}
	}
	return flush(), 0;
}