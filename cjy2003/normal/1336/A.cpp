#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to;
}bi[400040];
int n,k,head[200020],num,siz[200020],dep[200020],p[200020];
long long ans;
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void dfs(int v,int fa)
{
	siz[v]=1;dep[v]=dep[fa]+1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);
		siz[v]+=siz[u];
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return dep[x]-siz[x]>dep[y]-siz[y];});
	for(int i=1;i<=k;++i)ans+=dep[p[i]]-siz[p[i]];
	printf("%lld",ans);
	return 0;
}