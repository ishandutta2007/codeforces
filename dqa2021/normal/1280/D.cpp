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
typedef pair<int,ll> P;
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
const ll INF=1e18;

int n,m;
int w[3010];
vector<int> e[3010];

P dp[3010][3010];
int siz[3010];

void merge(P *F,P *G,int a,int b){
	static P H[3010];
	rep(i,0,a+b) H[i]=P(0,-INF);
	rep(i,0,a) rep(j,0,b) H[i+j]=max(H[i+j],P(F[i].fi+G[j].fi,F[i].se+G[j].se));
	rep(i,0,a+b) F[i]=H[i];
}

void dfs1(int x,int f){
	siz[x]=0; dp[x][0]=P(0,w[x]);
	forall(x,y) if (y^f){
		dfs1(y,x);
		merge(dp[x],dp[y],siz[x],siz[y]);
		siz[x]+=siz[y];
	}
	dp[x][siz[x]+1]=P(0,-INF);
	per(i,0,siz[x]) dp[x][i+1]=max(dp[x][i+1],P(dp[x][i].fi+(dp[x][i].se>0),0));
	++siz[x];
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) w[i]=-read(),e[i].clear();
	rep(i,1,n) w[i]+=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	printf("%d\n",dp[1][m-1].fi+(dp[1][m-1].se>0));
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}