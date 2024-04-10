#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

//#define DEBUG
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

bool c[200010];

#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)

struct D{
	int a; ll b,c; int t;
}d[1<<19];

ll sum(int sz,int w){
	return 1LL*w*(w-1)/2*sz;
//	if (w==0) return 0;
//	if (w>=0) return 1LL*w*(w-1)/2*sz;
//	w=-w; return -(1LL*w*(w-1)/2*sz);
}

void settag(int o,int l,int r,int w){
	if (!w) return;
	if (w<0){
		w=-w;
		d[o].b-=1LL*w*d[o].t;
		d[o].a-=w;
		d[o].c-=1LL*d[o].b*w+sum(d[o].t,w);
	}
	else{
		d[o].c+=1LL*d[o].b*w+sum(d[o].t,w);
		d[o].b+=1LL*w*d[o].t;
		d[o].a+=w;
	}
}

void pushdown(int o,int l,int r){
	if (!d[o].a) return;
	settag(ls,l,mid,d[o].a);
	settag(rs,mid+1,r,d[o].a);
	d[o].a=0;
}

void pushup(int o){
	d[o].b=d[ls].b+d[rs].b;
	d[o].c=d[ls].c+d[rs].c;
	d[o].t=d[ls].t+d[rs].t;
}

void update(int o,int l,int r,int ql,int qr,int w){
	if (ql<=l&&r<=qr){
//		printf("  upd %d %d %d  %d %d  %d\n",o,l,r,ql,qr,w);
		settag(o,l,r,w);
		return;
	}
	pushdown(o,l,r);
	if (ql<=mid) update(ls,l,mid,ql,qr,w);
	if (mid<qr) update(rs,mid+1,r,ql,qr,w);
	pushup(o);
}

void modify(int o,int l,int r,int p,ll b,ll c,int t){
	if (l==r) return d[o]={0,b,c,t},void();
	pushdown(o,l,r);
	if (p<=mid) modify(ls,l,mid,p,b,c,t);
	else modify(rs,mid+1,r,p,b,c,t);
	pushup(o);
}

int query(int o,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return d[o].t;
	/*pushdown(o,l,r);*/ int z=0;
	if (ql<=mid) z=query(ls,l,mid,ql,qr);
	if (mid<qr) z+=query(rs,mid+1,r,ql,qr);
	return z;
}

#undef mid

void solve(){
	int Q=read(),D=read();
	int n=2e5;   // test!!!
	while (Q--){
		int p=read();
		if (c[p]){
			if (p!=1) update(1,1,n,max(1,p-D),p-1,-1);
			modify(1,1,n,p,0,0,0);
		}
		else{
			if (p!=1) update(1,1,n,max(1,p-D),p-1,1);
			int w=p<n?query(1,1,n,p+1,min(n,p+D)):0;
//			printf("test w %d\n",w);
			modify(1,1,n,p,w,1LL*w*(w-1)/2,1);
		}
		c[p]^=1;
		printf("%lld\n",d[1].c);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}