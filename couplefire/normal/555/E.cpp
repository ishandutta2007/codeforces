#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=19650827;
const int INF=0x3f3f3f3f;
const int N=2e5+7;
const int M=2e6+7;
int n,m,q;
struct Edge{
	int e,next;
}edge[M];
int head[N],dfn[N],low[N],fa[N][20],dep[N],tag[N],cnt=1,tim=0,n_tag=0;
int s1[N],s2[N];
int n_col,col[N];
vector<int> G[N];
void add(int s,int e)
{
	edge[++cnt].e=e;
	edge[cnt].next=head[s];
	head[s]=cnt;
}
bool flag[M],vis[N];
void tarjan(int x,int in_edge)
{
	dfn[x]=low[x]=++tim;
	for(int i=head[x];i;i=edge[i].next)
	{
		int to=edge[i].e;
		if(!dfn[to])
		{
			tarjan(to,i);
			low[x]=min(low[to],low[x]);
			if(dfn[x]<low[to])
				flag[i]=flag[i^1]=1;
		}
		else if((i^1)!=in_edge)
			low[x]=min(low[x],dfn[to]);
	}
}
void dfs1(int x)
{
	col[x]=n_col;
	for(int i=head[x];i;i=edge[i].next)
	{
		int to=edge[i].e;
		if(col[to]||flag[i]) continue;
		dfs1(to);
	}
}
void dfs2(int x,int from)
{
	tag[x]=n_tag;
	dep[x]=dep[from]+1;
	fa[x][0]=from;
	for(int i=1;i<20;++i)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=0;i<G[x].size();++i)
	{
		int to=G[x][i];
		if(to==from) continue;
		dfs2(to,x);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;--i)
	{
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];	
	} 
	if(x==y) return x;
	for(int i=19;i>=0;--i)
	{
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
bool check(int x)
{
	for(int i=0;i<G[x].size();++i)
	{
		int to=G[x][i];
		if(to==fa[x][0]) continue;
		if(!check(to)) return 0;
		if(s1[to]&&s2[to]) return 0;
		s1[x]+=s1[to],s2[x]+=s2[to];
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
			tarjan(i,0);
	}
	for(int i=1;i<=n;++i)
	{
		if(col[i]) continue;
		n_col++;
		dfs1(i);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=head[i];j;j=edge[j].next)
		{
			int to=edge[j].e;
			if(col[to]>col[i])
			G[col[i]].push_back(col[to]),G[col[to]].push_back(col[i]);
		}
	}
	for(int i=1;i<=n_col;++i)
	{
		if(!tag[i])
		++n_tag,dfs2(i,0);
	}
	for(int i=1;i<=q;++i)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		s=col[s],t=col[t];
		if(s==t) continue;
		if(tag[s]!=tag[t])
		{
			printf("No");
			return 0;
		}
		int p=LCA(s,t);
		s1[s]++,s1[p]--;
		s2[t]++,s2[p]--;
	}
	for(int i=1;i<=n_col;++i)
	{
		if(dep[i]==1)
		{
			if(!check(i))
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
	return 0;
}