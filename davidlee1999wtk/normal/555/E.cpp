#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<map>
#define INF 1000000000
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int fr[N*2],to[N*2],pre[N*2],h[N],cou,fd[N*2],tot,dfn[N],low[N];
int cnt,sc[N];
vector<int> G[N];
int in[N],dep[N],fa[N][19],lg,maxd,z,f1[N],f2[N],s1[N],s2[N],ok;
inline void Addedge(int a,int b)
{
	cou++;
	fr[cou]=a;
	to[cou]=b;
	pre[cou]=h[a];
	h[a]=cou;
}

void dfs1(int x,int p)
{
	dfn[x]=low[x]=++tot;
	int i,v;
	for(i=h[x];i;i=pre[i])
	{
		v=to[i];
		if(!dfn[v])
		{
			dfs1(v,i);
			low[x]=min(low[x],low[v]);
			if(low[v]>dfn[x])
				fd[i]=1,fd[((i-1)^1)+1]=1;
		}
		else if(((i-1)^1)+1!=p)
			low[x]=min(low[x],low[v]);
	}	
}

void dfs2(int x)
{
	int i,v;
	sc[x]=cnt;
	for(i=h[x];i;i=pre[i])
	{
		v=to[i];
		if(!sc[v]&&!fd[i])
			dfs2(v);
	}	
}

void dfs3(int x)
{
	int i,len=G[x].size(),v;
	in[x]=++z;
	maxd=max(maxd,dep[x]);
	for(i=0;i<len;i++)
	{
		v=G[x][i];
		if(!in[v])
		{
			dep[v]=dep[x]+1;
			fa[v][0]=x;
			dfs3(v);
		}
	}
}

void dfs4(int x)
{
	int i,len=G[x].size(),v;
	//debug(x);
	for(i=0;i<len;i++)
	{
		v=G[x][i];
		if(v!=fa[x][0])
		{
			dfs4(v);
			s1[x]+=s1[v];
			s2[x]+=s2[v];
		}
	}
	s1[x]+=f1[x];
	s2[x]+=f2[x];
	if(s1[x]>0&&s2[x]>0)
		ok=1;
}

void initlca()
{
    int i,j,n=cnt;
    lg=int(log(maxd)/log(2)+0.5);
    for(j=1;j<=lg;j++)
        for(i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}

inline int lca(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    int i;
    for(i=lg;i>=0;i--)
        if(dep[fa[v][i]]>=dep[u])
            v=fa[v][i];
    if(u==v) return u;
    for(i=lg;i>=0;i--)
        if(fa[v][i]!=fa[u][i])
            u=fa[u][i],v=fa[v][i];
    if(fa[v][0]!=fa[u][0])
    	return 0;
    return fa[v][0];
}

int main()
{
	int i,n,m,q,a,b,c;
	cin>>n>>m>>q;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		Addedge(a,b);
		Addedge(b,a);
	}
	for(i=1;i<=n;i++)
		if(!dfn[i])
			dfs1(i,0);
	for(i=1;i<=n;i++)
		if(!sc[i])
		{
			cnt++;
			dfs2(i);
		}
	//debug(cnt);
	//for(i=1;i<=n;i++)
		//debug(sc[i]);
	for(i=1;i<=cou;i++)
		if(fd[i])
			G[sc[fr[i]]].push_back(sc[to[i]]);
	//return 0;
	for(i=1;i<=cnt;i++)
		if(!dep[i])
		{
			dep[i]=i;
			fa[i][0]=i;
			dfs3(i);
		}
	initlca();
	while(q--)
	{
		scanf("%d%d",&a,&b);
		a=sc[a],b=sc[b];
		//debug(a);
		//debug(b);
		if(a!=b)
		{
			c=lca(a,b);
			if(c==0)
				ok=1;
			f1[a]++;
			f2[b]++;
			f1[c]--,f2[c]--;
		}
	}
	for(i=1;i<=cnt;i++)
		if(fa[i][0]==i)
			dfs4(i);
	if(ok)
		printf("No\n");
	else printf("Yes\n");
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
8 7 8
6 3
4 5
2 5
7 3
7 8
4 7
1 5
6 3
5 2
6 3
6 4
6 3
6 3
1 5
5 2
*/