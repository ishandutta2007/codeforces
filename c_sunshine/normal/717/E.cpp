#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define next next_
const int maxn=400005;
int n,C[maxn],e[maxn],fa[maxn],sum;
int head[maxn],adj[maxn*2],next[maxn*2],tot;

vector<int> P;

void addedge(int u,int v)
{
	tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;
	tot++;adj[tot]=u;next[tot]=head[v];head[v]=tot;
}

void init()
{
	scanf("%d",&n);tot=1;
	for(int i=1;i<=n;i++)
		scanf("%d",C+i);
	for(int u,v,i=1;i<n;i++)
		scanf("%d%d",&u,&v),addedge(u,v);
}

void tdfs(int x)
{
	if(C[x]==-1)e[x]=1;
	for(int i=head[x];i;i=next[i])
		if(adj[i]!=fa[x])
		{
			fa[adj[i]]=x;
			tdfs(adj[i]);
			e[x]+=e[adj[i]];
		}
}

void Out()
{
	if(P.size()>10000000)while(1);
	for(int i=0;i<P.size();i++)
		printf("%d%c",P[i]," \n"[i+1==P.size()]);
	exit(0);
}

int dfs(int x)
{
	int oe=e[x];
	if(!P.empty())
	{
		if(C[x]==-1)e[x]--,sum--;
		else e[x]++,sum++;
		C[x]=-C[x];
	}
	P.push_back(x);
	if(P.size()>10000000)while(1);
	if(sum==0)Out();
	for(int i=head[x];i;i=next[i])
		if(adj[i]!=fa[x])
		{
			int flag=1;
			while(e[adj[i]]||C[x]==-1&&x==1&&e[x]==1)
			{
				e[x]+=dfs(adj[i]);
				if(C[x]==-1)e[x]--,sum--;
				else e[x]++,sum++;
				C[x]=-C[x];
				P.push_back(x);
				if(P.size()>10000000)while(1);
				if(sum==0)Out();
			}
		}
	return e[x]-oe;
}

int main()
{
	init();
	tdfs(1);
	sum=e[1];
	dfs(1);
	Out();
	return 0;
}