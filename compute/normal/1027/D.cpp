#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int cost[maxn];
int far[maxn];
int arr[maxn];
int vis[maxn];
void init()
{
	for(int i=0;i<maxn;i++) far[i]=i;
}
int Find(int x)
{
	return x==far[x]?x:far[x]=Find(far[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	far[y]=x;
}
int dfs(int u)
{
	vis[u]++;
	int ret=cost[u];
	if(vis[arr[u]]==1) ret=min(ret,dfs(arr[u]));
	else if(!vis[arr[u]])ret=dfs(arr[u]);
	return ret;
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		Union(i,arr[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[Find(i)])
		{
			ans+=dfs(i);
			vis[Find(i)]=1;
		}
	}
	printf("%d\n",ans);
}