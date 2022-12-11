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
//typedef pair<int,int> P;
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
#define ctz __builtin_ctz

int n,q,h[310]; const int m=1000;
bool mp[310][310];

namespace LA{

int a[310][310],V[310][310];

void gauss0(int n,int a[][310],int *V,int o){
	per(i,1,n)
		if (i^o){
			int &z=V[i];
			rep(j,i+1,n) iadd(z,1LL*a[i][j]*V[j]%mod);
			z=1LL*z*qpow(a[i][i],mod-2)%mod;
		}
		else V[i]=1;
}

int b[310][310],c[310][310],s[310][310],d[310][310],_c[310][310];

void gauss1(int n,int a[][310],int b[][310],int c[][310]){
	rep(i,1,n){
		int p=-1;
		rep(j,i,n) if (a[j][i]) {p=j; break;}
		assert(~p);
		if (p^i){
			rep(j,1,n){
				swap(a[p][j],a[i][j]);
				swap(b[p][j],b[i][j]);
				swap(c[p][j],c[i][j]);
			}
		}
		const int t=qpow(a[i][i],mod-2);
		rep(j,1,n){
			a[i][j]=1LL*a[i][j]*t%mod;
			b[i][j]=1LL*b[i][j]*t%mod;
			c[i][j]=1LL*c[i][j]*t%mod;
		}
		rep(j,1,n) if (j^i&&a[j][i]){
			const int s=1LL*a[j][i]*t%mod;
			rep(k,1,n){
				iadd(a[j][k],1LL*a[i][k]*s%mod);
				iadd(b[j][k],1LL*b[i][k]*s%mod);
				iadd(c[j][k],1LL*c[i][k]*s%mod);
			}
		}
	}
}

}
using namespace LA;

void prepare(){
	rep(i,1,n){
		rep(u,1,n) rep(v,1,n)
			a[u][v]=u==v||mp[v][u]?v:0;
		rep(j,1,n) iadd(a[j][j],i);
		LA::gauss0(n,a,V[i],i);  // row
	}
	rep(i,1,n) rep(j,1,n) a[i][j]=V[j][i],d[i][j]=i==j||mp[j][i]?j:0,_c[i][j]=i==j;
	
	LA::gauss1(n,a,d,_c);
	
	rep(i,1,n) rep(j,1,n) rep(k,1,n) add(b[i][j],1LL*d[i][k]*V[j][k]%mod);
	memcpy(c,_c,sizeof c);
	
	rep(i,1,n) rep(j,1,n) if (b[i][j]) assert(i==j);
	rep(i,1,n) rep(j,1,n) s[i][j]=V[i][j],add(s[i][j],s[i][j-1]);
}

int dp[310];
int tri[1010][310];
int pw[32][310];

void build(){
	fill(dp+1,dp+n+1,m+1);
	per(i,1,n){
		if (h[i]>0) dp[i]=1;
		else if (dp[i]>m) continue;
		rep(j,1,i-1) if (mp[i][j]) dp[j]=min(dp[j],dp[i]+1);
	}
	rep(i,1,n){
		pw[0][i]=i;
		rep(j,1,10) pw[j][i]=1LL*pw[j-1][i]*pw[j-1][i]%mod;
	}
	memset(tri,0,sizeof tri);
	rep(i,1,n) if (dp[i]<=m){
		rep(j,1,n){
			add(tri[dp[i]][j],1LL*pw[0][j]*c[j][i]%mod*upd(h[i])%mod);
		}
	}
	rep(i,1,m){
		const int j=i+(i&-i),k=ctz(i);
		if (j>m) continue;
		const auto F=tri[i],H=pw[k]; auto G=tri[j];
		rep(t,1,n) add(G[t],1LL*F[t]*H[t]%mod);
	}
}

void update(int x,int w){
	static int f[310];
	rep(i,1,n) f[i]=1LL*c[i][x]*w%mod*pw[0][i]%mod;
	for (x=dp[x];x<=m;x+=x&-x){
		auto F=tri[x];
		rep(j,1,n) add(F[j],f[j]);
		const auto G=pw[ctz(x)];
		rep(j,1,n) f[j]=1LL*f[j]*G[j]%mod;
	}
}

int query(int o,int l,int r){
	static int g[310],h[310];
	rep(i,1,n) h[i]=1,g[i]=0;
	int z=0;
	rep(i,l,r) if (dp[i]>o) add(z,upd(::h[i]));
	for (;o;o-=o&-o){
		const auto F=tri[o];
		rep(i,1,n) add(g[i],1LL*h[i]*F[i]%mod);
		const int k=ctz(o); const auto G=pw[k];
		rep(i,1,n) h[i]=1LL*h[i]*G[i]%mod;
	}
	rep(i,1,n) add(z,1LL*(s[i][r]-s[i][l-1]+mod)*g[i]%mod);
	return z;
}

void solve(){
	#define a h
	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n){
		int g=read();
		while (g--) mp[read()][i]=1;
	}
	prepare();
	build();
	q=read();
	while (q--){
		if (read()&1){
			int k=read(),l=read(),r=read();
			printf("%d\n",query(k,l,r));
		}
		else{
			int x=read(),w=read();
			a[x]+=w;
			if (a[x]-w<=0&&a[x]>0) build();
			else if (dp[x]<=m) update(x,w);
		}
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}