#include<bits/stdc++.h>  
using namespace std;
typedef long long ll;
#define ri register int
const int M=1000000007;
int n,t,i,j,u,v,ans=1<<30,head[100005],Next[200005],adj[200005],k,vis[100005],top;
ll a[100005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	if(vis[i]==1)
	{
		ans=min(ans,top);
		return;
	}
	vis[i]=1;
	int j;
	top++;
	if(top>=ans)
	{
		vis[i]=0;
		top--;
		return;
	}
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			dfs(adj[j],i);
	top--;
	vis[i]=0;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<=63;i++)
	{
		u=v=0;
		for(j=1;j<=n;j++)
			if((a[j]>>i)&1)
				if(u==0)
					u=j;
				else
					if(v==0)
						v=j;
					else
					{
						printf("3");
						return 0;
					}
		if(v!=0)
		{
			Push(u,v);
			Push(v,u);
		}
	}
	for(i=1;i<=n;i++)
		dfs(i,0);
	if(ans>n)
		printf("-1");
	else
		printf("%d",ans);
}