#include<bits/stdc++.h>
using namespace std;
const int N=505,E=200005;
int n,m,cnt[N],x;
char c[N],b[N];
int head[N],Next[E],adj[E],cap[E],cost[E];
int q[N*10000],pre[N],vis[N],now[N];
int flow,S,T,num=1;
long long d[N];
void addedge(int u,int v,int f,int w)
{
	//cout<<u<<' '<<v<<' '<<f<<' '<<w<<endl;
	Next[++num]=head[u],head[u]=num,adj[num]=v,cap[num]=f,cost[num]=w;
	Next[++num]=head[v],head[v]=num,adj[num]=u,cap[num]=0,cost[num]=-w;
}
bool SPFA()
{
	int i,l,r;
	q[l=r=1]=S;
	vis[S]=1;
	memset(d,0x7f,sizeof(d));
	d[S]=0;
	while(l<=r)
	{
		for(i=head[q[l]];i;i=Next[i])
			if(cap[i]&&d[adj[i]]>d[q[l]]+cost[i])
			{
				d[adj[i]]=d[q[l]]+cost[i];
				if(!vis[adj[i]])
				{
					vis[adj[i]]=1;
					q[++r]=adj[i];
				}
			}
		vis[q[l]]=0;
		++l;
	}
	return (d[T]<1<<30);
}
bool dfs(int i,int f)
{
	if(i==T)
	{
		flow=f;
		return true;
	}
	if(vis[i])
		return false;
	int j;
	vis[i]=1;
	for(j=now[i];j;now[i]=j=Next[j])
		if(cap[j]&&d[adj[j]]==d[i]+cost[j]&&dfs(adj[j],min(f,cap[j])))
		{
			cap[j]-=flow;
			cap[j^1]+=flow;
			vis[i]=0;
			return true;
		}
	vis[i]=0;
	return false;
}
long long ans,ansf;
void minmax()
{
	while(SPFA())
	{
		memcpy(now,head,sizeof(now));
		while(dfs(S,2147483646))
			ans+=flow*d[T],ansf+=flow;
	}
}
int i,j,k;
long long s=0;
int main()
{
	scanf("%d",&n);
	scanf("%s",c+1);
	scanf("%d",&m);
	while(m--)
	{
		int q;
		scanf("%s",b);
		scanf("%d",&q);
		for(j=1;j<=n;++j)
		{
			for(k=0;b[k]&&c[j+k]==b[k];++k);
			if(!b[k])
			{
				//cout<<j<<' '<<k<<endl;
				addedge(j,j+k,1,q);
				++cnt[j];
				--cnt[j+k];
				s+=q;
			}
		}
	}
	scanf("%d",&x);
	for(i=1;i<=n;++i)
		addedge(i,i+1,x,0);
	S=0;
	T=n+2;
	for(j=1;j<=n+1;++j)
	{
		if(cnt[j]>0)
			addedge(S,j,cnt[j],0);
		if(cnt[j]<0)
			addedge(j,T,-cnt[j],0);
	}
	minmax();
	cout<<s-ans;
}