#include<bits/stdc++.h>
#define pb push_back
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
const double eps=1e-9,INF=1e100;


int n; double L;
struct C{
	double l,r,v; int e;
}c[400010]; int m;
bool operator<(const C &x,const C &y){
	return x.v<y.v;
}
double a[400010],b[400010];

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct D{
	double s; int t;  // s + t * INF
	inline double to_real()const{
		return t?INF:s;
	}
}mn[1<<20],tg[1<<20];
D operator+(const D &x,const D &y){
	return (D){x.s+y.s,x.t+y.t};
}
bool operator<(const D &x,const D &y){
	return x.t<y.t||x.t==y.t&&x.s<y.s;
}

inline void pushup(int x){
	mn[x]=tg[x]+min(mn[ls],mn[rs]);
}

void update(int x,int l,int r,int ql,int qr,const D &w){
	if (ql<=l&&r<=qr){
		tg[x]=tg[x]+w,mn[x]=mn[x]+w;
		return;
	}
	if (ql<=mid) update(ls,l,mid,ql,qr,w);
	if (mid<qr) update(rs,mid+1,r,ql,qr,w);
	pushup(x);
}

D query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return mn[x];
	if (qr<=mid) return tg[x]+query(ls,l,mid,ql,qr);
	if (mid<ql) return tg[x]+query(rs,mid+1,r,ql,qr);
	return tg[x]+min(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}

#undef ls
#undef rs
#undef mid

void solve(){
	n=read(); L=read();
	rep(i,1,n){
		double l=read(),r=read(),v;
		scanf("%lf",&v); ++v;
		if (l!=c[m].r) c[m+1]=(C){c[m].r,l,1.0,m+1},++m;
		c[m+1]=(C){l,r,v,m+1},++m;
	}
	if (c[m].r!=L) c[m+1]=(C){c[m].r,L,1.0,m+1},++m;
	rep(i,1,m){
//		const C &o=c[i];
		a[i]=-(c[i].r-c[i].l)/(c[i].v+1);
		b[i]=fabs(c[i].v-1)<eps?INF:(c[i].r-c[i].l)/(c[i].v-1);
		if (fabs(c[i].v-1)<eps){
			update(1,1,m,i,m,(D){0.0,1});
		}
		else update(1,1,m,i,m,(D){b[i],0});
	}
//	rep(i,1,m) debug("c0 %d: %lf %lf %lf %d\n",i,c[i].l,c[i].r,c[i].v,c[i].e);
//	debug("===============\n");
	sort(c+1,c+m+1);
//	rep(i,1,m) debug("c %d: %lf %lf %lf %d\n",i,c[i].l,c[i].r,c[i].v,c[i].e);
//	debug("===============\n");
	double z=0.0;
	rep(_,1,m){
		const C &o=c[_];
		if (fabs(o.v-1)<eps){
			update(1,1,m,o.e,m,(D){a[o.e],-1});
		}
		else update(1,1,m,o.e,m,(D){a[o.e]-b[o.e],0});
		const double d=a[o.e]+max(0.0,-query(1,1,m,o.e,m).to_real());
//		debug("test %d: d %lf v %lf w %lf  a %lf b %lf\n",o.e,d,o.v,(o.r-o.l+d)/o.v,a[o.e],b[o.e]);
//		assert(d<b[o.e]+eps);
		z+=(o.r-o.l+d)/o.v;
		update(1,1,m,o.e,m,(D){d-a[o.e],0});
	}
	printf("%.12lf\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}