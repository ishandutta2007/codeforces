#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
const int N=2e5+3;
struct edge{int v,nxt;}g[1000003];
int n,m,S,T,siz[N],dfn[N],low[N],f[N],head[N],t0,t1,k;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u,int fa){
	int v;
	siz[u]=1,dfn[u]=++k,low[u]=k;
	if(u==T)f[u]=1;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  if(!dfn[v]){
		Dfs(v,u);
		siz[u]+=siz[v];
		low[u]=min(low[u],low[v]);
		if(f[v]&&u==S)t0=n-1-siz[v];
		if(f[v])f[u]=1;
		if(u==T&&low[v]>=dfn[u])t1+=siz[v];
	  }else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	int Test;scanf("%d",&Test);for(;Test--;){
	int u,v;
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(u=1;u<=n;u++)head[u]=0,f[u]=0,dfn[u]=0;
	k=0;
	t0=t1=0;
	for(;m--;)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	k=0;
	Dfs(S,0);
	printf("%lld\n",(long long)t0*t1);
	}return 0;
}