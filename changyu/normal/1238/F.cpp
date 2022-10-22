#include<cstdio>
const int N=300003;
struct edge{int v,nxt;}g[N+N];
int head[N],k,n,deg[N],p,dis[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u,int fa){
	int v;
	dis[u]=dis[fa]+(deg[u]==1?1:deg[u]-1);
	p=dis[u]>dis[p]?u:p;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  Dfs(v,u);
}
int main(){
	int u,v;
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(u=1;u<=n;u++)head[u]=0,deg[u]=0;
	k=0;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u),deg[u]++,deg[v]++;
	p=0;
	Dfs(1,0),Dfs(p,0);
	printf("%d\n",dis[p]);
	}return 0;
}