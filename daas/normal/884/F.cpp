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
const int inf=1e9;
const int MAXN=110*26;
const int MAXM=MAXN*100;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,S,T,dis[MAXN],dl[MAXN],h,t,pd[MAXN];
struct node
{
	int head[MAXN],tot,st[MAXN];
	int to[MAXM],nextn[MAXM],l[MAXM],cost[MAXM];
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
int build(int N)
{
	for(int i=1;i<=N;++i) Ed.st[i]=Ed.head[i];
	memset(dis,-0x3f,sizeof(dis));
	dis[S]=h=t=0;
	dl[++t]=S;
	int loop=N+1;
	while(h!=t)
	{
		h=h%loop+1;
		int u=dl[h];
		pd[u]=0;
		for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(dis[v]>=dis[u]+Ed.cost[i] || !Ed.l[i]) continue;
			dis[v]=dis[u]+Ed.cost[i];
			if(!pd[v])
			{
				pd[v]=1;
				t=t%loop+1;
				dl[t]=v;
			}
		}
	}
	return dis[T]!=dis[0];
}
int vis[MAXN];
pair<int,int> fun(int u,int flow)
{
	if(u==T) return make_pair(flow,0);
	int rest=flow,use=0;
	vis[u]=1;
	for(int i=Ed.st[u];i!=0 && rest!=0;i=Ed.nextn[i])
	{
		Ed.st[u]=i;
		int v=Ed.to[i];
		if(dis[v]!=dis[u]+Ed.cost[i] || vis[v] || !Ed.l[i]) continue;
		pair<int,int> K=fun(v,min(Ed.l[i],rest));
		if(!K.first) dis[v]=inf;
		Ed.l[i]-=K.first;
		Ed.l[i^1]+=K.first;
		rest-=K.first;
		use+=K.second+K.first*Ed.cost[i];
	}
	vis[u]=0;
	return make_pair(flow-rest,use);
}
void Dinic(int N)
{
	int ans=0;
	while(build(N))
		while(1)
		{
			pair<int,int> K=fun(S,inf);
			if(!K.first) break;
			ans+=K.second;
		}
	printf("%d\n",ans);
}
int ton[MAXN],val[MAXN];
char s[MAXN];
int main()
{
	n=read();
	Ed.tot=1;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) ++ton[s[i]-'a'];
	for(int i=1;i<=n;++i) val[i]=read();
	S=n+26+26*(n/2)+1,T=S+1;
	for(int i=1;i<=n;++i) Ed.build(i,T,1,0);
	for(int i=1;i<=26;++i)
	{
		Ed.build(S,i+n,ton[i-1],0);
		for(int j=1;j<=n/2;++j)
		{
			Ed.build(i+n,n+26+(i-1)*(n/2)+j,1,0);
			Ed.build(n+26+(i-1)*(n/2)+j,j,1,(s[j]-'a'==i-1?val[j]:0));
			Ed.build(n+26+(i-1)*(n/2)+j,n-j+1,1,(s[n-j+1]-'a'==i-1?val[n-j+1]:0));
		}
	}
	Dinic(T);
	return 0;
}
//ore no turn,draw!