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
const int INF=1e9;

int n;
vector<int> e[100010];
int d[100010];
int ans=1;

int f[2][100010];

void dfs(int x,int fa){
	f[0][x]=-INF,f[1][x]=1;
	for (int y: e[x]){
		if (y==fa) continue;
		dfs(y,x);
		rep(u,0,1) rep(v,0,1) if (!(u&v)) ans=max(ans,f[u][x]+f[v][y]);
		f[0][x]=max(f[0][x],max(f[0][y],f[1][y])+d[x]-2);
		f[1][x]=max(f[1][x],f[0][y]+1);
	}
}

void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	rep(i,1,n) d[i]=e[i].size();
	//rep(u,1,n) for (int v: e[u]) ans=max(ans,d[u]+d[v]-2);
	//getsiz(1,0); Siz=siz[1],Rt=-1;
	//getroot(1,0); solve(Rt);
	dfs(1,0);
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}