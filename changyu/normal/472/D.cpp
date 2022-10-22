#include<cstdio>
#include<cstring>
const int N=2003;
struct node{int v,c,nxt;}mst[N+N];
int n,g[N][N],d[N],used[N],fa[N],head[N],k;
inline void Insert(int u,int v,int c){mst[++k]=(node){v,c,head[u]};head[u]=k;}
void Dfs(int u,int f){
	int v;
	for(int i=head[u];i;i=mst[i].nxt)
	  if((v=mst[i].v)!=f)
		d[v]=d[u]+mst[i].c,Dfs(v,u);
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(u=1;u<=n;u++)
	  for(v=1;v<=n;v++){
		scanf("%d",&g[u][v]);
		if(u==v&&g[u][v]||u!=v&&!g[u][v])return 0*puts("NO");
		if(v<u&&g[u][v]!=g[v][u])return 0*puts("NO");
	  }
	memset(d,63,sizeof d);
	d[1]=0;
	for(int j=1;j<=n;j++){
	  u=0;
	  for(v=1;v<=n;v++)
		if(!used[v]&&d[v]<d[u])
		  u=v;
	  used[u]=1;
	  if(fa[u])
		Insert(fa[u],u,d[u]),Insert(u,fa[u],d[u]);
	  for(v=1;v<=n;v++)
		if(d[v]>g[u][v])
		  d[v]=g[u][v],fa[v]=u;
	}
	for(u=1;u<=n;u++){
	  d[u]=0;Dfs(u,0);
	  for(v=1;v<=n;v++)
		if(g[u][v]!=d[v])return 0*puts("NO");
	}
	return 0*puts("YES");
}