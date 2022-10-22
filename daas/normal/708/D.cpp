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
const int MAXN=110;
const int inf=1e9;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,S,T,ans,res[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXN*8],nextn[MAXN*8],l[MAXN*8],cost[MAXN*8];
	void ADD(int u,int v,int _l,int _cost)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l,cost[tot]=_cost;
		head[u]=tot;
	}
	void build(int u,int v,int _l,int _cost)
	{
		ADD(u,v,_l,_cost);
		ADD(v,u,0,-_cost);
	}
}Ed;
int dis[MAXN],dl[MAXN],h,t,pre[MAXN],pd[MAXN];
int SPFA()
{
	memset(dis,0x3f,sizeof(dis));
	int loop=T+1;
	dis[S]=h=t=0;
	dl[++t]=S;
	while(h!=t)
	{
		h=h%loop+1;
		int u=dl[h];
		pd[u]=0;
		for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(dis[v]<=dis[u]+Ed.cost[i] || !Ed.l[i]) continue;
			pre[v]=i;
			dis[v]=dis[u]+Ed.cost[i];
			if(!pd[v])
			{
				t=t%loop+1;
				dl[t]=v;
				pd[v]=1;
			}
		}
	}
	return dis[T]!=dis[0];
}
void EK()
{
	while(SPFA())
	{
		int minn=0x3f3f3f3f;
		for(int i=T;i!=S;i=Ed.to[pre[i]^1]) minn=min(minn,Ed.l[pre[i]]);
		for(int i=T;i!=S;i=Ed.to[pre[i]^1])
		{
			ans+=Ed.cost[pre[i]]*minn;
			Ed.l[pre[i]]-=minn;
			Ed.l[pre[i]^1]+=minn;
		}
	}
}
int main()
{
	n=read(),m=read();
	S=1,T=n;
	Ed.tot=1;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),c=read(),f=read();
		res[u]-=f;
		res[v]+=f;
		if(c<f)
		{
			ans+=f-c;
			Ed.build(v,u,f-c,0);
			Ed.build(v,u,c,1);
			Ed.build(u,v,inf,2);
		}
		else
		{
			Ed.build(u,v,c-f,1);
			Ed.build(u,v,inf,2);
			Ed.build(v,u,f,1);
		}
	}
	Ed.build(T,S,inf,0);
	S=n+1,T=S+1;
	for(int i=1;i<=n;++i)
		if(res[i]>0) Ed.build(S,i,res[i],0);
		else Ed.build(i,T,-res[i],0);
	EK();
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!