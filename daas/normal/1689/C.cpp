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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,size[MAXN],dp[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
	void init()
	{
		for(int i=1;i<=n;++i) head[i]=0;
		tot=0;
	}
}Ed;
void fun(int u,int fa)
{
	size[u]=1;
	int num=0;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		fun(v,u);
		size[u]+=size[v];
		++num;
	}
	dp[u]=0;
	if(num==0) return;
	if(num==1)
	{
		dp[u]=size[u]-2;
	}
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		dp[u]=max(dp[u],dp[v]+size[u]-2-size[v]);
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read();
			Ed.ADD(u,v);
			Ed.ADD(v,u);
		}
		fun(1,0);
		printf("%d\n",dp[1]);
		Ed.init();
	}
	return 0;
}
//ore no turn,draw!