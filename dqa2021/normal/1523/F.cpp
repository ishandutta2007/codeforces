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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
const int INF=0x7f7f7f7f;


int n,m,lim;
//P a[16];
struct B{
	int x,y,t;
}a[16],b[110];

int c[128][128],d[1<<14][128];
int getlen(const B &x,const B &y){
	return abs(x.x-y.x)+abs(x.y-y.y);
}

int f[1<<14][101][16];
int g[1<<14][101];

void solve(){
	n=read(),m=read(); lim=(1<<n)-1;
	rep(i,1,n) a[i].x=read(),a[i].y=read();
	rep(i,1,m) b[i].x=read(),b[i].y=read(),b[i].t=read();
	sort(b+1,b+m+1,[&](B x,B y){return x.t<y.t;});
	rep(i,1,n+m) rep(j,1,n+m) c[i][j]=getlen(i<=m?b[i]:a[i-m],j<=m?b[j]:a[j-m]);
	rep(msk,0,lim){
		rep(j,1,n+m){
			d[msk][j]=2e9;
			rep(i,1,n) if (msk>>i-1&1)
				d[msk][j]=min(d[msk][j],getlen(j<=m?b[j]:a[j-m],a[i]));
		}
	}
	memset(f,0x7f,sizeof f);
//	memset(g,-1,sizeof g);
	rep(i,1,n) f[1<<i-1][0][i]=0;
	rep(i,1,m) g[0][i]=1;
	int z=0;
	rep(msk,0,lim){
		rep(t,0,m) rep(p,1,n){
			const int &V=f[msk][t][p];
			if (V==INF) continue;
			z=max(z,t);
			rep(s,1,n) if (msk>>s-1&1^1){
				int &U=f[msk|1<<s-1][t][s];
				U=min(U,V+min(c[p+m][s+m],d[msk][s+m]));
			}
			rep(s,1,m){
				const int e=min(c[p+m][s],d[msk][s]);
				int &U=g[msk][s];
				if (V+e<=b[s].t) U=max(U,t+1);
			}
		}
		rep(p,1,m){
			const int &V=g[msk][p];
			if (V<=0) continue;
			z=max(z,V);
			rep(q,p+1,m){
				const int e=b[p].t+min(c[p][q],d[msk][q]);
				int &U=g[msk][q];
				if (e<=b[q].t) U=max(U,V+1);
			}
			rep(q,1,n) if (msk>>q-1&1^1){
				int &U=f[msk|1<<q-1][V][q];
				U=min(U,b[p].t+min(c[p][q+m],d[msk][q+m]));
			}
		}
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}