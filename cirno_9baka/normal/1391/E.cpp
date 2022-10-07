#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k,t,u,v,head[N],Next[N*2],adj[N*2],son[N],siz[N],vis[N],tot,i,j,fa[N];
vector<int> g[N];
struct str{
	int x;
};
bool operator <(str a,str b)
{
	return g[a.x].size()<g[b.x].size();
}
priority_queue<str> q;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int f)
{
	int j;
	siz[i]=vis[i]=1;
	son[i]=0;
	fa[i]=f;
	for(j=head[i];j;j=Next[j])
		if(!vis[adj[j]])
		{
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
			if(siz[adj[j]]>siz[son[i]])
				son[i]=adj[j];
		}
}
void dfs2(int i)
{
	int j;
	vis[i]=1;
	g[tot].push_back(i);
	for(j=head[i];j;j=Next[j])
		if(!vis[adj[j]])
			dfs2(adj[j]);
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
		for(i=1;i<=n;++i)
			vis[i]=head[i]=0;
		k=0;
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
			Push(v,u);
		}
		dfs(1,0);
		for(i=1;i<=n;++i)
			vis[i]=0;
		int len=0;
		for(i=1;i;i=son[i])
			++len;
		if(len>=(n+1)/2)
		{
			puts("PATH");
			printf("%d\n",len);
			for(i=1;i;i=son[i])
				printf("%d ",i);
			printf("\n");
			continue;
		}
		tot=len=0;
		for(i=1;i;i=son[i])
		{
			if(siz[i]<=(n-len)/2)
			{
				++tot;
				g[tot].clear();
				dfs2(i);
				break;
			}
			++len;
			vis[i]=1;
			for(j=head[i];j;j=Next[j])
				if(!vis[adj[j]]&&fa[adj[j]]==i&&adj[j]!=son[i])
				{
					++tot;
					g[tot].clear();
					dfs2(adj[j]);
				}
		}
		for(i=1;i<=tot;++i)
			q.push((str){i});
		puts("PAIRING");
		printf("%d\n",((n+1)/2+1)/2);
		int t=(n+1)/2;
		while(q.size()>=2&&t>0)
		{
			str x=q.top();
			q.pop();
			str y=q.top();
			q.pop();
			printf("%d %d\n",*g[x.x].rbegin(),*g[y.x].rbegin());
			g[x.x].pop_back();
			g[y.x].pop_back();
			if(g[x.x].size())
				q.push(x);
			if(g[y.x].size())
				q.push(y);
			t-=2;
		}
		while(!q.empty())
			q.pop();
	}
}