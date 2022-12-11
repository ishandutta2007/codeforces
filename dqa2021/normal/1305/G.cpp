#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;
typedef pair<P,P> Q;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define forall(x,y) for (const int &y: e[x])
const int lim=262143,bt=17,INF=1e9;

int n,m; ll ans;
int a[200010],b[200010];

int fat[200010];
int find(int x){
	return fat[x]?fat[x]=find(fat[x]):x;
}

Q fwt[1<<18];
Q operator+(const Q &x,const Q &y){
	static Q z;
	z.fi=max(x.fi,y.fi);
	z.se=P(-INF,-INF);
	if (x.fi.se^z.fi.se) z.se=max(z.se,x.fi);
	if (x.se.se^z.fi.se) z.se=max(z.se,x.se);
	if (y.fi.se^z.fi.se) z.se=max(z.se,y.fi);
	if (y.se.se^z.fi.se) z.se=max(z.se,y.se);
	return z;
}

inline void merge(int x,int y,const int &w){
	//printf("merge %d %d w %d\n",x,y,w);
	x=find(x),y=find(y);
	if (x==y) return;
	//printf("success\n");
	fat[y]=x,ans+=w,--m;
}

P c[200010];

void solve(){
	n=read()+1;
	rep(i,2,n) a[i]=read(),ans-=a[i];
	m=n;
	while (m>1){
		//puts("=============");
		rep(i,0,lim) fwt[i]=Q(P(-INF,-INF),P(-INF,-INF));
		rep(i,1,n) fwt[a[i]]=fwt[a[i]]+Q(P(a[i],b[i]=find(i)),P(-INF,-INF)),c[i]=P(-INF,-INF);
		rep(j,0,bt) rep(i,0,lim)
			if (i>>j&1) fwt[i]=fwt[i]+fwt[i^(1<<j)];
		rep(i,1,n){
			const auto &[x,y]=fwt[~a[i]&lim];
			//printf("case %d: b %d x %d,%d y %d,%d\n",i,b[i],x.fi,x.se,y.fi,y.se);
			if (x.se^b[i]&&x.se!=-INF) c[b[i]]=max(c[b[i]],P(x.fi+a[i],x.se));
			else if (y.se^b[i]&&y.se!=-INF) c[b[i]]=max(c[b[i]],P(y.fi+a[i],y.se));
		}
		rep(i,1,n) if (b[i]==i) merge(i,c[i].se,c[i].fi);
	}
	printf("%lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}