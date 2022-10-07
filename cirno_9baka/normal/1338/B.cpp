#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
int n,i,s,j,f=-1,y=1,ans,t,u,v,k,head[N],Next[N*2],adj[N*2],d[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa,int p)
{
	if(d[i]==1)
	{
		if(f==-1)
			f=p;
		if(f!=p)
			y=3;
	}
	int j,s=0;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i,p^1);
			if(d[adj[j]]==1)
				++s;
		}
	ans-=max(s-1,0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		++d[u],++d[v];
		Push(u,v);
		Push(v,u);
	}
	ans=n-1;
	for(i=1;i<=n;++i)
		if(d[i]>=2)
			break;
	int rt=i;
	dfs(rt,0,0);
	cout<<y<<' '<<ans;
}