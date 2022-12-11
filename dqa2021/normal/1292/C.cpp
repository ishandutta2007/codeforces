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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n;
vector<int> e[3010];

int dis[3010][3010];
void dfs1(int x,int f,int d,int *dis){
	dis[x]=d;
	forall(x,y) if (y^f) dfs1(y,x,d+1,dis);
}

int siz[3010],id[3010],fat[3010];
void dfs2(int x,int f){
	siz[x]=1; id[x]=++*id; fat[x]=f;
	forall(x,y) if (y^f) dfs2(y,x),siz[x]+=siz[y];
}

vector<P> g[3010];

ll dp[3010][3010];

ll w[3010][3010];

ll getval(int x,int y){
	//printf("getval %d %d = %lld\n",x,y,w[x][y]);
	return w[x][y];
	/*int a,b;
	if (id[x]<=id[y]&&id[y]<id[x]+siz[x]) a=n-siz[x]+1;
	else a=siz[x];
	if (id[y]<=id[x]&&id[x]<id[y]+siz[y]) b=n-siz[y]+1;
	else b=siz[y];
	printf("getval %d %d = %d %d\n",x,y,a,b);
	return 1LL*a*b;*/
}

void dfs3(int x,int f,int b,ll *w){
	w[x]=b*(fat[x]==f?siz[x]:n-siz[f]);
	forall(x,y) if (y^f) dfs3(y,x,b,w);
}

void solve(){
	n=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	rep(i,1,n) dfs1(i,0,0,dis[i]);
	dfs2(1,0);
	rep(i,1,n) rep(j,i+1,n) g[dis[i][j]].emplace_back(i,j);
	rep(i,1,n) forall(i,j) dfs3(j,i,j==fat[i]?siz[i]:n-siz[j],w[i]);
	
	//getval(1,3); return;
	
	for (const auto &[x,y]: g[1]) dp[x][y]=getval(x,y);
	const auto chk=[&](int x,int y,ll w){
		if (x>y) swap(x,y);
		dp[x][y]=max(dp[x][y],w);
	};
	rep(_,1,n-2){
		for (const auto &[x,y]: g[_]){
			//printf("dis %d dp %d %d = %lld\n",_,x,y,dp[x][y]);
			forall(x,z) if (dis[y][z]==_+1) chk(y,z,dp[x][y]+getval(y,z));
			forall(y,z) if (dis[x][z]==_+1) chk(x,z,dp[x][y]+getval(x,z));
		}
	}
	ll z=0;
	rep(i,1,n) rep(j,i+1,n) z=max(z,dp[i][j]);
	printf("%lld\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}