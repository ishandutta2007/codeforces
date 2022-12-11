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
//typedef pair<int,int> P;
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;
int dis[512][512];
vector<int> e[512];
int ans[512][512];

vector<int> h[512];

int work(int x,int y,int *f,int *g){
	int tot=0;
	rep(i,1,n) tot+=(f[i]+g[i]==f[y]);
	if (tot!=f[y]+1) return 0;
	rep(i,1,n) if ((f[i]+g[i]+f[y])&1) return 0;
	rep(i,1,n) h[i].clear();
	rep(i,1,n)
		if (f[i]+g[i]>f[y])
			h[f[i]+g[i]-f[y]>>1].pb(i);
	int z=1;
	rep(i,1,n){
		for (const int &x: h[i]){
			int w=0;
			for (const int &y: e[x])
				if (f[y]+g[y]<f[x]+g[x])
					++w;
			z=1LL*z*w%mod;
		}
	}
	return z;
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) rep(j,1,n) dis[i][j]=int(1e9)*(i!=j);
	rep(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
		dis[u][v]=dis[v][u]=1;
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	rep(i,1,n) rep(j,i,n) ans[i][j]=ans[j][i]=work(i,j,dis[i],dis[j]);
	rep(i,1,n) rep(j,1,n) printf("%d%c",ans[i][j]," \n"[j==n]);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}