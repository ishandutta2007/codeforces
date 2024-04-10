#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,k,i,a,b,da,db,u,v,head[N],Next[N*2],adj[N*2],j,dp[N],ans,dd,t;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j,mxx=0;
	dp[i]=0;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i);
			if(dp[i]<dp[adj[j]]+1)
			{
				mxx=max(mxx,dp[i]);
				dp[i]=dp[adj[j]]+1;
			}
			else
				mxx=max(mxx,dp[adj[j]]+1);
		}
	ans=max(ans,mxx+dp[i]);
}
void dis(int i,int fa,int d)
{
	int j;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
			dis(adj[j],i,d+1);
	if(i==b)
		dd=d;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
		for(i=1;i<=n;++i)
			head[i]=0;
		k=0;
		for(i=1;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
			Push(v,u);
		}
		if(db<=da*2)
		{
			puts("Alice");
			continue;
		}
		ans=0;
		dfs(1,0);
		dis(a,0,0);
		if(dd<=da||ans<=da*2)
			puts("Alice");
		else
			puts("Bob");
	}
}