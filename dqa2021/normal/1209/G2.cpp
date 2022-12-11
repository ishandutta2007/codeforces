#include<bits/stdc++.h>
#define pb push_back
using namespace std;

#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,q,m=2e5;
int a[200010],b[200010];
set<int> g[200010];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct C{
	int l,m,r;
	int s,mx,t;
}c[1<<19];

void pushup(int x,int l,int r){
	c[x].mx=l==r?b[l]:max(c[ls].mx,c[rs].mx);
	c[x].s=c[x].t?r-l+1:(l==r?0:c[ls].s+c[rs].s);
	if (c[x].s==r-l+1);
	else{
		if (l==r){
			c[x].l=c[x].r=0;
			c[x].m=b[l];
			return;
		}
		if (c[ls].s==mid-l+1){
			c[x].l=max(c[ls].mx,c[rs].l);
			c[x].m=c[rs].m;
			c[x].r=c[rs].r;
		}
		else if (c[rs].s==r-mid){
			c[x].l=c[ls].l;
			c[x].m=c[ls].m;
			c[x].r=max(c[ls].r,c[rs].mx);
		}
		else{
			c[x].l=c[ls].l;
			c[x].m=c[ls].m+c[rs].m+max(c[ls].r,c[rs].l);
			c[x].r=c[rs].r;
		}
	}
}

void build(int x,int l,int r){
	if (l^r) build(ls,l,mid),build(rs,mid+1,r);
	pushup(x,l,r);
}

void update(int x,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr){
		c[x].t+=w; pushup(x,l,r); return;
	}
	if (ql<=mid) update(ls,l,mid,ql,qr,w);
	if (mid<qr) update(rs,mid+1,r,ql,qr,w);
	pushup(x,l,r);
}

//void debugdfs(int x,int l,int r){
//	if (l^r) debugdfs(ls,l,mid),debugdfs(rs,mid+1,r);
//	debug("  %d: %d %d %d  %d  %d  %d\n",x,c[x].l,c[x].m,c[x].r,c[x].s,c[x].mx,c[x].t);
//}

#undef ls
#undef rs
#undef mid

void del(int o){
	if (g[o].empty()) return;
	int l=*g[o].begin(),r=*g[o].rbegin();
	if (l<r) update(1,1,n,l,r-1,-1);
	b[l]=0; update(1,1,n,l,l,0);
}

void ins(int o){
	if (g[o].empty()) return;
	int l=*g[o].begin(),r=*g[o].rbegin();
	if (l<r) update(1,1,n,l,r-1,1);
	b[l]=g[o].size(); update(1,1,n,l,l,0);
}

inline int getans(){
	return n-c[1].l-c[1].m;
}

void solve(){
	n=read(),q=read();
	rep(i,1,n) a[i]=read(),g[a[i]].insert(i);
	rep(i,1,m){
		if (g[i].empty()) continue;
		int l=*g[i].begin(),r=*g[i].rbegin();
		b[l]=g[i].size();
	}
//	rep(i,1,n) debug("b %d = %d\n",i,b[i]);
	build(1,1,n);
	rep(i,1,m){
		if (g[i].empty()) continue;
		int l=*g[i].begin(),r=*g[i].rbegin();
		if (l<r) update(1,1,n,l,r-1,1);
	}
	
//	debugdfs(1,1,n);
	
	printf("%d\n",getans());
	while (q--){
		int x=read(),w=read();
		if (w==a[x]){
			printf("%d\n",getans());
			continue;
		}
		del(a[x]),del(w);
		g[a[x]].erase(x);
		g[w].insert(x);
		ins(a[x]),ins(w);
		a[x]=w;
		printf("%d\n",getans());
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}