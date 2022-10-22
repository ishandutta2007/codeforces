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
const int MAXN=610;
const int MAXM=MAXN*MAXN*3;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,p,q,S,T,deep[MAXN],dl[MAXN],h,t;
struct node
{
	int head[MAXN],tot,st[MAXN];
	int to[MAXM],nextn[MAXM],l[MAXM];
	void ADD(int u,int v,int _l)
	{
		to[++tot]=v,nextn[tot]=head[u],l[tot]=_l;
		head[u]=tot;
	}
	void build(int u,int v,int _l)
	{
		ADD(u,v,_l);
		ADD(v,u,0);
	}
}Ed;
int build(int N)
{
	for(int i=1;i<=N;++i) Ed.st[i]=Ed.head[i];
	memset(deep,0,sizeof(deep));
	deep[S]=1; h=t=0;
	dl[++t]=S;
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i];
			if(deep[v] || !Ed.l[i]) continue;
			deep[v]=deep[u]+1;
			if(v==T) return 1;
			dl[++t]=v;
		}
	}
	return 0;
}
int fun(int u,int flow)
{
	if(u==T) return flow;
	int rest=flow;
	for(int i=Ed.st[u];i!=0 && rest!=0;i=Ed.nextn[i])
	{
		Ed.st[u]=i;
		int v=Ed.to[i];
		if(deep[v]!=deep[u]+1 || !Ed.l[i]) continue;
		int K=fun(v,min(rest,Ed.l[i]));
		if(!K) deep[v]=0;
		Ed.l[i]-=K;
		Ed.l[i^1]+=K;
		rest-=K;
	}
	return flow-rest;
}
int ans=0;
void Dinic(int N)
{
	while(build(N))
		while(1)
		{
			int K=fun(S,inf);
			if(!K) break;
			ans-=K;
		}
	printf("%d\n",-ans);
}
int main()
{
	n=read();
	Ed.tot=1;
	S=2*n+1,T=S+1;
	for(int i=1;i<=n;++i)
	{
		int K=read();
		for(int j=1;j<=K;++j)
		{
			int x=read();
			Ed.build(i,x+n,inf);
		}
	}
	int oo=3e8;
	for(int i=1;i<=n;++i) Ed.build(i+n,T,oo);
	for(int i=1;i<=n;++i)
	{
		int v=read(); ans+=oo-v;
		Ed.build(S,i,oo-v);
	}
	Dinic(T);
	return 0;
}
//ore no turn,draw!