#include<cstdio>
const int N=1e5+3;
struct edge{int v,nxt;}g[N+N];
int n,head[N],k;double ans;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u,int dep,int fa){
	int v;
	ans+=1.0/dep;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  Dfs(v,dep+1,u);
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	  scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	Dfs(1,1,0);
	printf("%.9lf\n",ans);
	return 0;
}