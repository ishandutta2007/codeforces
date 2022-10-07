#include<bits/stdc++.h>
using namespace std;
const int N=100005,E=1000005;
int dis[N],head[N],Next[E],adj[E],cap[E],k=1,S,T;
int que[N],now[N];

void addedge(int u,int v,int w)
{
	Next[++k]=head[u],head[u]=k,adj[k]=v,cap[k]=w;
	Next[++k]=head[v],head[v]=k,adj[k]=u,cap[k]=0;
}
bool BFS()
{
	int i,l,r;
	memset(dis,-1,sizeof(dis));
	que[l=r=1]=S;
	dis[S]=0;
	while(l<=r)
	{
		for(i=head[que[l]];i;i=Next[i])
			if(dis[adj[i]]==-1&&cap[i])
			{
				dis[adj[i]]=dis[que[l]]+1;
				que[++r]=adj[i];
			}
		++l;
	}
	return (dis[T]!=-1);
}
int fl;
bool DFS(int i,int f)
{
	if(i==T)
	{
		fl=f;
		return true;
	}
	int j;
	for(j=now[i];j;now[i]=j=Next[j])
		if(dis[adj[j]]==dis[i]+1&&cap[j]&&DFS(adj[j],min(cap[j],f)))
		{
			cap[j]-=fl;
			cap[j^1]+=fl;
			return true;
		}
	return false;
}
long long Dinic()
{
	long long ans=0;
	while(BFS())
	{
		memcpy(now,head,sizeof(head));
		while(DFS(S,10000000))
			ans+=fl;
	}
	return ans;
}
int n,m,i,j;
char c[205][205];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	int ans=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			ans+=(c[i][j]=='#');
	S=0,T=n*m*2+1;
	int w=n*m;
	for(i=1;i<=n;++i)
		for(j=1;j<m;++j)
		{
			if(i!=n)
			{
				addedge((i-1)*m+j,(i-1)*m+j+w,1);
				addedge((i-1)*m+j,(i-1)*m+j+1+w,1);
			}
			if(i!=1)
			{
				addedge((i-1)*m+j,(i-2)*m+j+w,1);
				addedge((i-1)*m+j,(i-2)*m+j+1+w,1);
			}
		}
	int s=0;
	for(i=1;i<=n;++i)
		for(j=1;j<m;++j)
			if(c[i][j]=='#'&&c[i][j+1]=='#')
			{
				addedge(0,(i-1)*m+j,1);
				++s;
			}
	for(i=1;i<n;++i)
		for(j=1;j<=m;++j)
			if(c[i][j]=='#'&&c[i+1][j]=='#')
			{
				addedge((i-1)*m+j+w,T,1);
				++s;
			}
	cout<<ans-s+Dinic();
}