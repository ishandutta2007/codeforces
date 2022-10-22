#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,head[1000010],tot,len[1000010],son[1000010],ans[1000010];
int pre[1000010],*dp[1000010],*id=pre;
struct sb
{
	int to,nextn;
}a[2000010];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u,int fa)
{
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		format(v,u);
		len[u]=max(len[u],len[v]);
		if(len[v]>len[son[u]])
			son[u]=v;
	}
	++len[u];
}
void dsu(int u,int fa)
{
	dp[u][0]=1;
	if(son[u])
	{
		dp[son[u]]=dp[u]+1;
		dsu(son[u],u);
		ans[u]=ans[son[u]]+1;
	}
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa || v==son[u])
			continue;
		dp[v]=id;
		id+=len[v];
		dsu(v,u);
		for(int j=0;j<len[v];++j)
		{
			dp[u][j+1]+=dp[v][j];
			if(dp[u][j+1]>dp[u][ans[u]] || (dp[u][j+1]==dp[u][ans[u]] && j+1<ans[u]))
				ans[u]=j+1;
		}
	}
	if(dp[u][ans[u]]==1)
		ans[u]=0;
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
	}
	format(1,0);
	dp[1]=id;
	id+=len[1];
	dsu(1,0);
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}