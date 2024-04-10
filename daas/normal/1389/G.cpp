#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=3e5+10;
const int MAXM=3e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,c[MAXN],w[MAXN],sp[MAXN],spe[MAXN];
ll val[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXM*2],nextn[MAXM*2],l[MAXM*2];
	void ADD(int u,int v,int _l)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l;
		head[u]=tot;
	}
}Ed,En;
int dfn[MAXN],low[MAXN],tim,cut[MAXM],point[MAXN],cnt;
void tarjan(int u,int from)
{
	dfn[u]=low[u]=++tim;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(!dfn[v])
		{
			tarjan(v,i^1);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) cut[i>>1]=1;
		}
		else if(i!=from) low[u]=min(low[u],dfn[v]);
	}
}
void paint(int u)
{
	point[u]=cnt;
	val[cnt]+=c[u];
	spe[cnt]|=sp[u];
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(point[v] || cut[i>>1]) continue;
		paint(v);
	}
}
int size[MAXN],father[MAXN];
void remake(int u,int fa)
{
	size[u]=spe[u];
	for(int i=En.head[u];i!=0;i=En.nextn[i])
	{
		int v=En.to[i];
		if(v==fa) continue;
		remake(v,u);
		size[u]+=size[v];
	}
	if(!size[u]) val[fa]+=val[u],father[u]=fa,val[u]=-1;
}
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
ll dp[MAXN],ans[MAXN];
void fun(int u,int fa)
{
	dp[u]=val[u];
	for(int i=En.head[u];i!=0;i=En.nextn[i])
	{
		int v=En.to[i];
		if(v==fa) continue;
		fun(v,u);
		dp[u]=dp[u]+max(0ll,dp[v]-En.l[i]);
	}
}
void change(int u,int fa)
{
	ans[u]=dp[u];
	for(int i=En.head[u];i!=0;i=En.nextn[i])
	{
		int v=En.to[i];
		if(v==fa) continue;
		ll dpu=dp[u]-max(0ll,dp[v]-En.l[i]);
		dp[v]+=max(0ll,dpu-En.l[i]);
		change(v,u);
	}
}
int main()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=K;++i) sp[read()]=1;
	for(int i=1;i<=n;++i) c[i]=read();
	for(int i=1;i<=m;++i) w[i]=read();
	Ed.tot=1;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		Ed.ADD(u,v,0);
		Ed.ADD(v,u,0);
	}
	tarjan(1,0);
	for(int i=1;i<=n;++i) if(!point[i]) ++cnt,paint(i);
	for(int u=1;u<=n;++u)
		for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(point[u]==point[v]) continue;
			En.ADD(point[u],point[v],w[i>>1]);
		}
	for(int i=1;i<=cnt;++i) father[i]=i;
	int rt=1;
	while(!spe[rt]) ++rt;
	remake(rt,0);
	fun(rt,0);
	change(rt,0);
	for(int i=1;i<=n;++i) printf("%lld ",ans[find(point[i])]);
	putchar('\n');
	return 0;
}
//ore no turn,draw!