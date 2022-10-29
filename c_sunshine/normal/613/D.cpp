#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=100005;

int n,m;
int head[maxn],adj[maxn*2],next[maxn*2],tot;
int fa[maxn][17],dfn[maxn],dep[maxn],idx;

void addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;}

void tdfs(int x)
{
	dfn[x]=++idx;
	dep[x]=dep[*fa[x]]+1;
	for(int i=head[x];i;i=next[i])
		if(adj[i]!=*fa[x])
		{
			*fa[adj[i]]=x;
			tdfs(adj[i]);
		}
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=16;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	for(int i=16;i>=0;i--)
		if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	if(u!=v)return fa[u][0];
	return u;
}
 
int UP(int u,int d)
{
	for(int i=16;i>=0;i--)
		if(dep[fa[u][i]]>=d)u=fa[u][i];
	return u;
}
void init()
{
	scanf("%d",&n);
	for(int u,v,i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v),addedge(v,u);
	}
	tdfs(1);
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}

int p[maxn],t[maxn],fth[maxn],cnt,st[maxn],top;
int se[maxn];
int f[maxn][2];
vector<int> A[maxn];

bool cmpdfn(int a,int b)
{return dfn[a]<dfn[b];}

void dp(int x)
{
	f[x][0]=0;
	int s=n+1;
	for(int tmp,y,i=0;i<A[x].size();i++)
	{
		dp(y=A[x][i]);
		tmp=dep[y]-dep[x]==1?f[y][0]:min(f[y][0],f[y][1]+1);
		f[x][0]+=tmp;
		if(!se[x])s=min(s,f[y][1]-tmp);
	}
	f[x][1]=min(f[x][0],f[x][0]+s);
	if(!se[x])
	{
		int s=1;
		for(int i=0;i<A[x].size();i++)
			s+=min(f[A[x][i]][0],f[A[x][i]][1]);
		f[x][0]=min(f[x][0],s);
	}
	if(se[x])f[x][0]=n+1;
}

int work()
{
	scanf("%d",&m);
	cnt=0;
	for(int i=1;i<=m;i++)
		scanf("%d",p+i),t[++cnt]=p[i],se[p[i]]=1;
	sort(p+1,p+m+1,cmpdfn);
	top=0;
	for(int i=1;i<=m;i++)
		if(!top)fth[st[++top]=p[i]]=0;
		else
		{
			int a=p[i],lca=LCA(a,st[top]);
			for(;dep[st[top]]>dep[lca];top--)
				if(dep[st[top-1]]<=dep[lca])
					fth[st[top]]=lca;
			if(st[top]!=lca)
			{
				t[++cnt]=lca;
				se[lca]=0;
				fth[lca]=st[top];
				st[++top]=lca;
			}
			fth[a]=lca;
			st[++top]=a;
		}
	sort(t+1,t+cnt+1,cmpdfn);
	int imp=0,rt;
	for(int i=1;i<=cnt;i++)
		if(fth[t[i]])
		{
			A[fth[t[i]]].push_back(t[i]);
			if(se[t[i]]&&se[fth[t[i]]]&&dep[t[i]]-dep[fth[t[i]]]==1)imp=1;
		}
		else rt=t[i];
	if(imp)
	{
		for(int i=1;i<=cnt;i++)
			if(fth[t[i]])A[fth[t[i]]].clear();
		return -1;
	}
	dp(rt);
	for(int i=1;i<=cnt;i++)
		if(fth[t[i]])A[fth[t[i]]].clear();
	return min(f[rt][0],f[rt][1]);
}

int main()
{
	init();
	int Q;
	for(scanf("%d",&Q);Q--;)
		printf("%d\n",work());
	return 0;
}