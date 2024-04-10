#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int N,n,m,q;
int vis[MAXN],deep[MAXN],jump[MAXN][22],R[MAXN],father[MAXN];
struct node
{
	int head[MAXN*2],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed,T;
void format(int u,int fa)
{
	vis[u]=1;
	deep[u]=deep[fa]+1;
	int LOG=log2(deep[u]);
	jump[u][0]=fa;
	for(int i=1;i<=LOG;++i) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(vis[v]) continue;
		format(v,u);
	}
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	int C=deep[x]-deep[y],LOG=log2(C);
	for(int i=0;i<=LOG;++i) if(C&(1<<i)) x=jump[x][i];
	if(x==y) return x;
	LOG=log2(deep[x]);
	for(int i=LOG;i>=0;--i) if(jump[x][i]!=jump[y][i]) x=jump[x][i],y=jump[y][i];
	return jump[x][0];
}
int dfn[MAXN],low[MAXN],tim,z[MAXN],top;
vector<int> P[MAXN*2];
vector<pair<int,int>> E[MAXN*2];
void tarjan(int u,int from)
{
	dfn[u]=low[u]=++tim;
	z[++top]=u;
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i]) if(i!=from)
	{
		int v=Ed.to[i];
		if(!dfn[v])
		{
			tarjan(v,i^1);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				++N;
				T.ADD(u,N);
				P[N].push_back(u);
				int x;
				do
				{
					x=z[top--];
					T.ADD(N,x);
					P[N].push_back(x);
				}while(x!=v);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
int Deep[MAXN*2],Jump[MAXN*2][23],sum[MAXN*2];
void Format(int u,int fa)
{
	Deep[u]=Deep[fa]+1;
	int LOG=log2(Deep[u]);
	Jump[u][0]=fa;
	for(int i=1;i<=LOG;++i) Jump[u][i]=Jump[Jump[u][i-1]][i-1];
	for(int i=T.head[u];i!=0;i=T.nextn[i])
	{
		int v=T.to[i];
		Format(v,u);
	}
}
int TLCA(int x,int y)
{
	if(Deep[x]<Deep[y]) swap(x,y);
	int C=Deep[x]-Deep[y],LOG=log2(C);
	for(int i=0;i<=LOG;++i) if(C&(1<<i)) x=Jump[x][i];
	if(x==y) return x;
	LOG=log2(Deep[x]);
	for(int i=LOG;i>=0;--i) if(Jump[x][i]!=Jump[y][i]) x=Jump[x][i],y=Jump[y][i];
	return Jump[x][0];
}
int col[MAXN],flag;
void paint(int u)
{
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		if(col[v]==-1)
		{
			col[v]=col[u]^1;
			paint(v);
		}
		else if(col[u]==col[v]) flag=1;
	}
}
void Push(int u)
{
	for(int i=T.head[u];i!=0;i=T.nextn[i])
	{
		int v=T.to[i];
		sum[v]+=sum[u];
		Push(v);
	}
}
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
int main()
{
	N=n=read(),m=read();
	Ed.tot=1;
	for(int i=1;i<=n;++i) father[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		if(find(u)!=find(v)) father[find(u)]=find(v);
		Ed.ADD(u,v);
		Ed.ADD(v,u);
	}
	for(int i=1;i<=n;++i) if(!deep[i]) format(i,0);
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i,0),R[i]=1;
	for(int i=1;i<=n;++i) if(R[i]) Format(i,0);
	for(int u=1;u<=n;++u)
	{
		for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
		{
			int v=Ed.to[i],tmp=u;
			if(u>v) continue;
			if(Deep[tmp]<Deep[v]) swap(tmp,v);
			E[Jump[tmp][0]].push_back(make_pair(tmp,v));
		}
	}
	for(int p=n+1;p<=N;++p)
	{
		for(int i=0;i<P[p].size();++i) col[P[p][i]]=-1,Ed.head[P[p][i]]=0;
		Ed.tot=flag=0;
		for(int i=0;i<E[p].size();++i)
		{
			Ed.ADD(E[p][i].first,E[p][i].second);
			Ed.ADD(E[p][i].second,E[p][i].first);
		}
		col[P[p][0]]=0;
		paint(P[p][0]);
		sum[p]=flag;
	}
	for(int i=1;i<=n;++i) if(R[i]) Push(i);
	q=read();
	int QQ=0;
	while(q--)
	{
		int u=read(),v=read();
		++QQ;
		if(find(u)!=find(v)) {puts("No");continue;}
		int dis=deep[u]+deep[v]-2*deep[LCA(u,v)];
		if(dis&1) puts("Yes");
		else
		{
			dis=sum[u]+sum[v]-sum[TLCA(u,v)]-sum[Jump[TLCA(u,v)][0]];
			if(dis) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
//ore no turn,draw!