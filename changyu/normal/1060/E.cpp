#include<cstdio>
const int N=2e5+1;
struct edge{int v,nxt;}g[N+N];
int n,siz[2][N],head[N],k;long long ans,f[2][N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u,int fa)
{
	int v;
	siz[0][u]=1;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  Dfs(v,u);
	  for(int k=0;k<2;k++)
		siz[k][u]+=siz[k^1][v],f[k][u]+=f[k^1][v]+siz[k^1][v];
	}
}
inline void Update(int u,int v){
	for(int k=0;k<2;k++)
	  siz[k][v]-=siz[k^1][u],f[k][v]-=f[k^1][u]+siz[k^1][u];
	for(int k=0;k<2;k++)
	  siz[k][u]+=siz[k^1][v],f[k][u]+=f[k^1][v]+siz[k^1][v];
}
void Dfs1(int u,int fa){
	int v;
	ans+=(f[0][u]+f[1][u]+siz[1][u])>>1;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  Update(v,u),Dfs1(v,u),Update(u,v);
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	Dfs(1,0);Dfs1(1,0);
	printf("%I64d",ans>>1);
	return 0;
}