#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=3003;
struct edge{int v,nxt;}g[N+N];
int n,head[N],d[N][N],siz[N][N],k;ll dp[N][N],ans;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u,int fa,int rt){
	int v;
	siz[rt][u]=1;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  d[rt][v]=d[rt][u]+1,Dfs(v,u,rt),siz[rt][u]+=siz[rt][v];
}
void Dp(int s,int t){
	if(dp[s][t])return;
	int v;
	for(int i=head[s];i;i=g[i].nxt)if(d[v=g[i].v][t]>d[s][t]){
	  Dp(v,t);
	  dp[s][t]=std::max(dp[s][t],dp[v][t]+siz[t][v]*siz[v][t]);
	}
	for(int i=head[t];i;i=g[i].nxt)if(d[v=g[i].v][s]>d[s][t]){
	  Dp(v,s);
	  dp[s][t]=std::max(dp[s][t],dp[v][s]+siz[s][v]*siz[v][s]);
	}
}
signed main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	for(u=1;u<=n;u++)Dfs(u,0,u);
	for(u=1;u<=n;u++)Dp(u,u),ans=std::max(ans,dp[u][u]);
	printf("%lld",ans);
	return 0;
}