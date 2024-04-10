#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
const ll INF=1e18;

int n,m,q;
ll dis[610][610];
ll w[610][610];
ll L[610][610];
ll f[610][610];
void solve(){
	n=read(),m=read();
	rep(i,1,n) rep(j,1,n) dis[i][j]=i==j?0:INF;
	rep(i,1,m){
		int u=read(),v=read(); ll w=read();
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	memcpy(w,dis,sizeof w);
	rep(k,1,n) rep(i,1,n) rep(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	q=read();
	memset(L,-1,sizeof L);
	rep(i,1,q){
		int u=read(),v=read(); ll w=read();
		L[u][v]=L[v][u]=max(L[u][v],w);
	}
	rep(v,1,n){
		rep(a,1,n){
			ll &V=f[v][a]; V=-INF;
			rep(b,1,n)
				if (dis[v][b]!=INF&&~L[a][b]) V=max(V,L[a][b]-dis[v][b]);
		}
	}
	int ans=0;
	rep(v,1,n)
		rep(u,1,n){
			if (u^v&&w[u][v]!=INF){
				bool g=0;
				rep(a,1,n)
					if (dis[u][a]!=INF&&dis[u][a]+w[u][v]<=f[v][a]){
						g=1; break;
					}
				ans+=g; 
			}
		}
	printf("%d\n",ans>>1);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}