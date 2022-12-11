#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to;
}bi[200020];
int n,head[100010],num,d[100010],dep[100010],ans,rt,mi=1;
bool vis[100010];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);ans+=d[v]>1&&d[u]>1;
	}
	if(d[v]==1&&v!=rt&&dep[v]%2==0)mi=3;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x),++d[x],++d[y];
	}
	for(int i=1;i<=n;++i)
		if(d[i]==1)
		{
			rt=i;
			if(!vis[bi[head[i]].to])vis[bi[head[i]].to]=1,++ans;
		}
	dfs(rt,0);
	printf("%d %d\n",mi,ans);
	return 0;
}