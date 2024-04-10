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
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,D,chk[MAXN];
struct node
{
	int head[MAXN],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
int dp[MAXN][2],ans;
void fun(int u,int fa)
{
	dp[u][0]=dp[u][1]=-1e9;
	if(chk[u]) dp[u][0]=0;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		fun(v,u);
		int val=dp[v][0]+1;
		if(val>dp[u][0]) dp[u][1]=dp[u][0],dp[u][0]=val;
		else dp[u][1]=max(dp[u][1],val);
	}
}
void change(int u,int fa)
{
	if(dp[u][0]<=D) ++ans;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(v==fa) continue;
		int vs=dp[v][0]+1,val=dp[u][0]+1;
		if(vs==dp[u][0]) val=dp[u][1]+1;
		if(val>dp[v][0]) dp[v][1]=dp[v][0],dp[v][0]=val;
		else dp[v][1]=max(dp[v][1],val);
		change(v,u);
	}
}
int main()
{
	n=read(),m=read(),D=read();
	for(int i=1;i<=m;++i) chk[read()]=1;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		Ed.ADD(u,v);
		Ed.ADD(v,u);
	}
	fun(1,0);
	change(1,0);
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!