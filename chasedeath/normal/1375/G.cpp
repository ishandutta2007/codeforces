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

const int N=1e6+10,INF=1e9+10;

int n;
vector <int> G[N];
int dp[N][2],g[N][2];
void dfs(int u,int f) {
	dp[u][1]=1;
	for(int v:G[u]) if(v!=f) {
		dfs(v,u);
		dp[u][0]+=dp[v][1];
		dp[u][1]+=dp[v][0];
	}
}

int ans=1e9;
void dfs2(int u,int f) {
	if(f) {
		g[u][1]=g[f][0]+1;
		g[u][0]=g[f][1];
		g[u][0]+=dp[f][0]-dp[u][1];
		g[u][1]+=dp[f][1]-dp[u][0]-1;
	}
	//cout<<"$"<<u<<' '<<dp[u][1]<<' '<<g[u][0]<<endl;
	cmin(ans,dp[u][1]+g[u][0]-1);
	for(int v:G[u]) if(v!=f) dfs2(v,u);
}

int main(){
	n=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0),dfs2(1,0);
	printf("%d\n",ans);
}