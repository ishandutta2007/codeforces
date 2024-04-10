#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int i,j,n,m,head[N],Next[N*2],adj[N*2],k,mx,d[N],u,v;
int au[N*5],av[N*5],p;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int t,int fa)
{
	int j;
	int mp=t;
	bool flag=false;
	au[++p]=i;
	av[p]=mp;
	if(t==mx)
	{
		t=mx-d[i];
		au[++p]=i;
		av[p]=t;
		flag=true;
	}
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],t+1,i);
			au[++p]=i;
			av[p]=++t;
			if(t==mx)
			{
				t=mx-d[i];
				au[++p]=i;
				av[p]=t;
				flag=true;
			}
		}
	if(!flag)
	{
		au[++p]=i;
		av[p]=mp-1;
	}
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
		Push(u,v);
		Push(v,u);
		++d[u],++d[v];
	}
	for(i=1;i<=n;++i)
		mx=max(mx,d[i]);
	au[p=1]=1,av[p=1]=0;
	int tp=0;
	for(i=head[1];i;i=Next[i])
	{
		dfs(adj[i],tp+1,1);
		au[++p]=1;
		av[p]=++tp;
	}
	printf("%d\n",p);
	for(i=1;i<=p;++i)
		printf("%d %d\n",au[i],av[i]);
}