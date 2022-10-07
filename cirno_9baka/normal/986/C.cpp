#include<bits/stdc++.h>
using namespace std;
int f[10000005],n,m,vis[5000005],a[5000005],q[10000005],ans,i,j,c[5000005];
int Find(int x)
{
	return (f[x]!=-1?f[x]=Find(f[x]):x);
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[x]=y;
}
void dfs(int i)
{
	if(vis[i])
		return;
	vis[i]=1;
	int j;
	for(j=0;j<n;++j)
		if(((i>>j)&1)^1)
			dfs(i|(1<<j));
}
void dfs2(int i)
{
	if(!vis[i])
		return;
	if(c[i])
		return;
	c[i]=1;
	int j;
	for(j=0;j<n;++j)
		if((i>>j)&1)
			if(vis[i^(1<<j)])
			{
				uniot(i^(1<<j),i);
				dfs2(i^(1<<j));
			}
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&a[i]);
		uniot(i+(1<<n),a[i]);
		dfs(a[i]);
		uniot(i+(1<<n),a[i]^((1<<n)-1));
	}
	for(i=1;i<=m;++i)
		dfs2(a[i]^((1<<n)-1));
	for(i=(1<<n)+1;i<=(1<<n)+m;++i)
		if(!q[Find(i)])
		{
			q[Find(i)]=1;
			++ans;
		}
	cout<<ans;
}