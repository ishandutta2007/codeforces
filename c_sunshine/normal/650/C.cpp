#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
inline void readi(int &x);
#define ID(_i,_j) ((_i-1)*m+_j)
const int maxn=2000005;
int n,m,dn;
int a[maxn],fa[maxn];
int head[maxn],adj[maxn*2],next[maxn*2],tot;
int ind[maxn],lv[maxn];
int p[maxn],I,J;
int q[maxn*2],qh,qt;
int addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;ind[v]++;}

bool cmpj(int aa,int b)
{return a[ID(I,aa)]<a[ID(I,b)];}
bool cmpi(int aa,int b)
{return a[ID(aa,J)]<a[ID(b,J)];}

int getfa(int x)
{return fa[x]?fa[x]=getfa(fa[x]):x;}
void merge(int x,int y)
{if(x!=y)fa[x]=y;}

int main()
{
	readi(n),readi(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",a+ID(i,j));
	for(I=1;I<=n;I++)
	{
		for(int j=1;j<=m;j++)p[j]=j;
		sort(p+1,p+m+1,cmpj);
		for(int j=1;j<m;j++)
			if(a[ID(I,p[j])]==a[ID(I,p[j+1])])
			merge(getfa(ID(I,p[j])),getfa(ID(I,p[j+1])));
	}
	for(J=1;J<=m;J++)
	{
		for(int i=1;i<=n;i++)p[i]=i;
		sort(p+1,p+n+1,cmpi);
		for(int i=1;i<n;i++)
			if(a[ID(p[i],J)]==a[ID(p[i+1],J)])
			merge(getfa(ID(p[i],J)),getfa(ID(p[i+1],J)));
	}
	for(I=1;I<=n;I++)
	{
		for(int j=1;j<=m;j++)p[j]=j;
		sort(p+1,p+m+1,cmpj);
		for(int j=1;j<m;j++)
			if(a[ID(I,p[j])]!=a[ID(I,p[j+1])])
			addedge(getfa(ID(I,p[j])),getfa(ID(I,p[j+1])));
	}
	for(J=1;J<=m;J++)
	{
		for(int i=1;i<=n;i++)p[i]=i;
		sort(p+1,p+n+1,cmpi);
		for(int i=1;i<n;i++)
			if(a[ID(p[i],J)]!=a[ID(p[i+1],J)])
			addedge(getfa(ID(p[i],J)),getfa(ID(p[i+1],J)));
	}
	qh=qt=maxn;
	for(int i=1;i<=n*m;i++)
		if(ind[i]==0)lv[q[++qt]=i]=1;
	for(int u,v,i;qh<qt;)
		for(i=head[u=q[++qh]];i;i=next[i])
			if(--ind[v=adj[i]]==0)
			{
				if(a[u]==a[v])
				{
					lv[v]=lv[u];
					q[qh--]=v;
				}
				else
				{
					lv[v]=lv[u]+1;
					q[++qt]=v;
				}
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%c",lv[getfa(ID(i,j))]," \n"[j==m]);
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}