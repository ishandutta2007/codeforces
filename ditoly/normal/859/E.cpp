#include<cstdio>
#define MN 200000
#define MOD 1000000007
struct edge{int nx,t;}e[MN+5];
int t[MN+5],h[MN+5],en,rt,cnt,u[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x)
{
	if(!t[x]||t[x]==x)rt=x;cnt+=u[x]=1;
	for(int i=h[x];i;i=e[i].nx)
		if(!u[e[i].t])dfs(e[i].t);
}
int main()
{
	int n,i,x,ans=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&x),scanf("%d",&t[x]),ins(x,t[x]);
	for(i=1;i<=2*n;++i)if(!u[i])
	{
		rt=cnt=0;dfs(i);
		if(!rt)ans=ans*2%MOD;
		else if(!t[rt])ans=1LL*ans*cnt%MOD; 
	}
	printf("%d",ans);
}