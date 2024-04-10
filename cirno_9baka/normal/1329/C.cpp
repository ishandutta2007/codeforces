#include<bits/stdc++.h>
using namespace std;
const int N=1005,E=262144;
const int M=998244353;
const int V=499122177;
int i,n,m,a[1100005],t,p;
int vis[1100005];
vector<int> g[1100005];
int tmp[1100005],tx[1100005];
long long ans;
void dfs(int i,int d)
{
	g[i].clear();
	if(i>=(1<<n-1))
	{
		g[i].push_back(a[i]);
		return;
	}
	dfs(i<<1,d+1);
	dfs(i<<1|1,d+1);
	int j,k,p=0;
	for(j=0,k=0;j<g[i<<1].size()&&k<g[i<<1|1].size();)
		if(g[i<<1][j]<g[i<<1|1][k])
		{
			tx[p]=0;
			tmp[p++]=g[i<<1][j++];
		}
		else
		{
			tx[p]=1;
			tmp[p++]=g[i<<1|1][k++];
		}
	while(j<g[i<<1].size())
	{
		tx[p]=0;
		tmp[p++]=g[i<<1][j++];
	}
	while(k<g[i<<1|1].size())
	{
		tx[p]=1;
		tmp[p++]=g[i<<1|1][k++];
	}
	tmp[p++]=a[i];
	for(j=0;j<p;++j)
		g[i].push_back(tmp[j]);
	if(d<m)
	{
		int c=(1<<m-d-1)/2,mx=0,my=0;
		for(j=p-1;j>=0;--j)
			if(vis[tmp[j]])
				break;
		++j;
		ans+=tmp[j];
		vis[tmp[j]]=1;
	}
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
		scanf("%d %d",&n,&m);
		for(i=1;i<=(1<<n)-1;++i)
		{
			scanf("%d",&a[i]);
			vis[a[i]]=0;
		}
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
		int tot=0;
		for(i=1;i<=(1<<n)-1;++i)
			if(!vis[a[i]])
				tmp[++tot]=i;
		for(i=tot;i>=1;--i)
			printf("%d ",tmp[i]);
		printf("\n");
	}
}