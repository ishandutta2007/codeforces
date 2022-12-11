#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int to,nxt;
}bi[2020];
int n,head[1010],num,rt,siz[1010],maxs[1010],st[1010],tp,nd,now,d,w[1010];
void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void dfs(int v,int fa)
{
	siz[v]=1;maxs[v]=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);
		maxs[v]=max(maxs[v],siz[u]);
		siz[v]+=siz[u];
	}
	maxs[v]=max(maxs[v],n-siz[v]);
	if(maxs[v]<maxs[rt])rt=v;
}
void dfs0(int v,int fa)
{
	siz[v]=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs0(u,v);
		siz[v]+=siz[u];
	}
}
void dfs1(int v,int fa)
{
	w[v]=(now+=d);
	printf("%d %d %d\n",fa,v,w[v]-w[fa]);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);
	}
}
bool cmp(int x,int y){return siz[x]<siz[y];}
int main()
{
	scanf("%d",&n);nd=n*n*2/9;
	if(n==1)return 0; 
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	maxs[0]=0x3f3f3f3f;
	dfs(1,0);
	dfs0(rt,0);
	for(int i=head[rt];i;i=bi[i].nxt)st[++tp]=bi[i].to;
	sort(st+1,st+1+tp,cmp);
	int p=0,sum=0;
	for(int i=1;i<=tp;++i)
	{
		sum+=siz[st[i]];
		if((sum+1)*(n-sum)>nd){p=i;break;}
	}
	now=0,d=1;
	for(int i=1;i<=p;++i)dfs1(st[i],rt);
	now=0,d=sum+1;
	for(int i=p+1;i<=tp;++i)dfs1(st[i],rt);
	return 0;
}