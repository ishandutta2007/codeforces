#include<bits/stdc++.h>
using namespace std;
const int N=100005,E=1000005,inf=2147483640;

int dis[N],head[N],Next[E],adj[E],cap[E],k=1,S,T;
int que[N],now[N];

void addedge(int u,int v,int w)
{
	Next[++k]=head[u],head[u]=k,adj[k]=v,cap[k]=w;
	Next[++k]=head[v],head[v]=k,adj[k]=u,cap[k]=0;
	//cout<<u<<' '<<v<<' '<<w<<endl;
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
		while(DFS(S,inf))
			ans+=fl;
	}
	return ans;
}
int n,i,x[N],y[N],w[N];
long long s;
map<int,map<int,int> > mp;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d",&x[i],&y[i],&w[i]);
		swap(x[i],y[i]);
		mp[x[i]][y[i]]=i;
		s+=w[i];
	}
	S=0,T=2*n+1;
	for(i=1;i<=n;++i)
	{
		if((x[i]%2)&&(y[i]%2))
		{
			addedge(S,i*2-1,inf);
			if(mp[x[i]][y[i]+1])
				addedge(i*2,mp[x[i]][y[i]+1]*2-1,inf);
			if(mp[x[i]][y[i]-1])
				addedge(i*2,mp[x[i]][y[i]-1]*2-1,inf);
		}
		if((x[i]%2==0)&&(y[i]%2))
			addedge(i*2,T,inf);
		if((x[i]%2==0)&&(y[i]%2==0))
		{
			if(mp[x[i]][y[i]+1])
				addedge(i*2,mp[x[i]][y[i]+1]*2-1,inf);
			if(mp[x[i]][y[i]-1])
				addedge(i*2,mp[x[i]][y[i]-1]*2-1,inf);
		}
		if(x[i]%2&&(y[i]%2==0))
		{
			if(mp[x[i]+1][y[i]])
				addedge(i*2,mp[x[i]+1][y[i]]*2-1,inf);
			if(mp[x[i]-1][y[i]])
				addedge(i*2,mp[x[i]-1][y[i]]*2-1,inf);
		}
		addedge(i*2-1,i*2,w[i]);
	}
	cout<<s-Dinic();
}