#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,u,v,head[N],Next[N*2],adj[N*2],insta[N],k,vis[N],dep[N],siz[N],mn[N],mnn[N];
int head2[N],Next2[N],adj2[N],ans[N*2],tot,vi[N],i,j,p[N];
bool flag;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void Push2(int u,int v)
{
	Next2[++k]=head2[u];
	head2[u]=k;
	adj2[k]=v;
}
void dfs(int i)
{
	insta[i]=1;
	vis[i]=1;
	int j;
	for(j=head[i];j;j=Next[j])
		if(!vis[adj[j]])
			dfs(adj[j]);
		else
			if(!insta[adj[j]])
				flag=false;
	insta[i]=0;
}
void dfs2(int i)
{
	int j;
	vis[i]=1;
	siz[i]=0;
	mn[i]=1<<30;
	for(j=head[i];j;j=Next[j])
		if(!vis[adj[j]])
		{
			dep[adj[j]]=dep[i]+1;
			dfs2(adj[j]);
			if(mn[i]>mn[adj[j]])
			{
				mn[i]=min(mn[i],mn[adj[j]]);
				mnn[i]=mnn[adj[j]];
			}
			siz[i]+=siz[adj[j]];
		}
		else
		{
			++siz[i];
			--siz[adj[j]];
			if(mn[i]>dep[adj[j]])
			{
				mn[i]=dep[adj[j]];
				mnn[i]=adj[j];
			}
		}
	if(siz[i]>1)
		ans[++tot]=i;
	if(siz[i]==1)
		Push2(mnn[i],i);
}
void tag(int i)
{
	if(vi[i])
		return;
	vi[i]=1;
	ans[++tot]=i;
	int j;
	for(j=head2[i];j;j=Next2[j])
		tag(adj2[j]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
		tot=k=0;
		for(i=1;i<=n;++i)
		{
			head2[i]=vi[i]=head[i]=0;
			p[i]=i;
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
		}
		k=0;
		for(i=2;i<=n;++i)
			swap(p[i],p[rnd()%i+1]);
		for(i=1;i<=100&&i<=n;++i)
		{
			flag=true;
			for(j=1;j<=n;++j)
				vis[j]=0;
			dfs(p[i]);
			if(flag)
				break;
		}
		if(i>100||i>n)
		{
			puts("-1");
			continue;
		}
		int x=p[i];
		for(i=1;i<=n;++i)
			vis[i]=0;
		dep[x]=1;
		dfs2(x);
		for(i=1;i<=tot;++i)
			tag(ans[i]);
		int s=0;
		for(i=1;i<=n;++i)
			if(!vi[i])
				++s;
		if(s<(n+4)/5)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;++i)
			if(!vi[i])
				printf("%d ",i);
		printf("\n");
	}
}