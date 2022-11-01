#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
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

const int N = 500005;
const ll inf = 1e18;
int n, q, num, L[N], R[N], h[N], fa[N], e[N], pre[N], w[N];
ll D, ans[N], d[N], s[N<<2], lazy[N<<2];
struct item{ int l, r, id;};
vector<item> f[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void build(int l, int r, int t){
	if(l==r) return (void)(s[t]=d[l]);
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1), s[t]=min(s[k], s[k|1]);
	// printf("build: %d %d %lld\n", l, r, s[t]);
}
ll query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return s[t];
	int mid=(l+r)>>1, k=t<<1;
	if(R<=mid) return query(l, mid, k, L, R)+lazy[t];
	if(L>mid) return query(mid+1, r, k|1, L, R)+lazy[t];
	return min(query(l, mid, k, L, R), query(mid+1, r, k|1, L, R))+lazy[t];
}
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(s[t]+=x, lazy[t]+=x);
	int mid=(l+r)>>1, k=t<<1;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
	s[t]=min(s[k], s[k|1])+lazy[t];
}
void dfs(int u){
	D+=w[u], change(1, n, 1, L[u], R[u], -w[u]<<1);
	// printf("dfs: %d\n", u);
	for(auto j:f[u]) ans[j.id]=query(1, n, 1, j.l, j.r)+D;
	for(int i=h[u]; i; i=pre[i]) dfs(e[i]);
	D-=w[u], change(1, n, 1, L[u], R[u], w[u]<<1);
}
int main() {
	read(n), read(q);
	for(int i=2; i<=n; ++i)
		read(fa[i]), read(w[i]), add(fa[i], i), d[i]=d[fa[i]]+w[i];
	for(int i=1; i<=n; ++i) L[i]=R[i]=i;
	for(int i=n; i; --i) L[fa[i]]=min(L[fa[i]], L[i]), R[fa[i]]=max(R[fa[i]], R[i]);
	for(int i=1; i<=n; ++i) if(h[i]) d[i]=inf;
	for(int i=1, v, l=0, r=0; i<=q; ++i){
		read(v), read(l), read(r);
		f[v].push_back((item){l, r, i});
	}
	build(1, n, 1), dfs(1);
	for(int i=1; i<=q; ++i) print(ans[i]), print('\n');
	return flush(), 0;
}