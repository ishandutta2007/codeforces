#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=310,P=998244353;
ll qpow(ll x,ll k=P-2){
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

int n,d,m;
vector <int> G[N];
int dp[N][N*2],g[N*2],D[N];
vector <int> tmp;
void dfs(int u,int f) {
	// n+1 
	rep(i,0,m) dp[u][i]=0;
	dp[u][n+d+2]=1,dp[u][n]=1;
	for(int v:G[u]) if(v!=f) {
		dfs(v,u);
		cmax(D[u],D[v]+1);
		rep(i,0,m) g[i]=dp[u][i],dp[u][i]=0;
		tmp.clear();
		rep(i,0,m) if(dp[v][i]) tmp.pb(i);
		rep(i,0,m) if(g[i]) {
			for(int j:tmp) {
				if(max(j-n-2,i-n-2)>=max(n-i,n-j)) dp[u][max(i,j)]=(dp[u][max(i,j)]+1ll*g[i]*dp[v][j])%P;
				else dp[u][min(i,j)]=(dp[u][min(i,j)]+1ll*g[i]*dp[v][j])%P;
			}
		}
	}
	rep(i,0,m) g[i]=dp[u][i],dp[u][i]=0;
	rep(i,1,n) dp[u][i-1]=g[i];
	rep(i,n+2,m) dp[u][i-1]=g[i];
	dp[u][n+1]+=g[n+1],Mod1(dp[u][n+1]);
	//printf("u=%d\n",u);
	//rep(i,0,m) cout<<dp[u][i]<<' ';
	//puts("");
}

int main(){
	n=rd(),m=n*2+2;
	rep(i,2,n) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	//return d=1,dfs(1,0),0;
	int all=qpow(2,n),ans=0;
	for(d=1;d<n;++d) {
		dfs(1,0);
		int s=all;
		rep(i,n+1,m) s-=dp[1][i],Mod2(s);
		//cout<<d<<' '<<s<<endl;
		ans=(ans+s)%P;
	}
	//cout<<ans<<endl;
	ans=ans*qpow(all)%P;
	printf("%d\n",ans);
}