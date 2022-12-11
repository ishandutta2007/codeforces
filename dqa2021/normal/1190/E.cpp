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
typedef double db;
const double eps=1e-9;

int n,m;
struct P{
	db x,y;
	P(db X=0,db Y=0):x(X),y(Y){}
}p[100010];
P operator+(P x,P y){
	return P(x.x+y.x,x.y+y.y);
}
P operator-(P x,P y){
	return P(x.x-y.x,x.y-y.y);
}
P operator*(P x,P y){
	return P(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x);
}
db cross(P x,P y){
	return x.x*y.y-x.y*y.x;
}
db dot(P x,P y){
	return x.x*y.x+x.y*y.y;
}
bool operator<(const P &x,const P &y){
	bool a=(x.x>eps||fabs(x.x)<eps&&x.y>0);
	bool b=(y.x>eps||fabs(y.x)<eps&&y.y>0);
	if (a^b) return a>b;
	return cross(x,y)<-eps;
}
bool operator>(const P &x,const P &y){
	return y<x;
}
bool operator!=(const P &x,const P &y){
	bool a=(x.x>eps||fabs(x.x)<eps&&x.y>0);
	bool b=(y.x>eps||fabs(y.x)<eps&&y.y>0);
	if (a^b) return 1;
	return fabs(cross(x,y))>eps;
}

struct Q{
	int w; P o;
};
bool operator<(const Q &x,const Q &y){
	if (x.w^y.w) return x.w<y.w;
	return x.o<y.o;
}

struct L{
	Q l,r;
}g[200010];

bool operator<(const L &x,const L &y){
	if (x.r.o!=y.r.o) return x.r.o<y.r.o;
	return y.l<x.l;
}

bool check(db r){
//	q=0;
	rep(i,1,n){
		db d=dot(p[i],p[i]);
		d=sqrt(d);
		if (d<r) return 0;
		P h={r/d,sqrt(d*d-r*r)/d};
		g[i].l={1,p[i]*h};
		h.y=-h.y;
		g[i].r={1,p[i]*h};
		if (g[i].r<g[i].l) g[i].l.w=0;
	}
	sort(g+1,g+n+1);
	rep(i,n+1,n<<1) g[i]=g[i-n],++g[i].l.w,++g[i].r.w;
//	rep(i,1,n<<1) debug("%d: (%d, (%lf, %lf)  ::  (%d, (%lf, %lf))\n",i,g[i].l.w,g[i].l.o.x,g[i].l.o.y,g[i].r.w,g[i].r.o.x,g[i].r.o.y);
	static int stk[200010],gnd[17][200010]; int top=0;
	per(i,1,n<<1){
		int l=0,r=top;
		while (l<r){
			int mid=l+r+1>>1;
			if (g[i].r<g[stk[mid]].l) l=mid;
			else r=mid-1;
		}
		if (l) gnd[0][i]=stk[l];
		else gnd[0][i]=0;
//		debug("test lk %d = %d\n",i,gnd[0][i]);
		rep(j,1,16) gnd[j][i]=gnd[j-1][gnd[j-1][i]];
		while (top&&g[stk[top]].l<g[i].l) --top;
		stk[++top]=i;
	}
	rep(i,1,n){
		int w=1,x=i;
		per(j,0,16) if (gnd[j][x]&&gnd[j][x]-i<n) w+=1<<j,x=gnd[j][x];
		if (w<=m) return 1;
	}
	return 0;
}

void solve(){
	n=read(),m=read();
	rep(i,1,n){
		db x=read(),y=read();
		p[i]={x,y};
	}
	
//	if (check(1)) puts("ok");
//	return;
	
	double l=0,r=sqrt(2)*100000+1000,mid;
	rep(_,1,60){
		mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%.10lf\n",l);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}