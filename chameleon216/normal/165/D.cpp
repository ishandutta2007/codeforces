#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<21;
struct FastIO
{
	char buf[MB],*p,*e;
	int getChar()
	{
		if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MX=100100;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec=1;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M,A[MX];
int F[MX],D[MX],sz[MX],son[MX];
int U[MX],dfn[MX],dfn_[MX],dc;
void dfs1(int x,int f,int d)
{
	F[x]=f,D[x]=d,sz[x]=1;
	Fe(i,x)if(y!=f)
	{
		dfs1(y,x,d+1),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,dfn[x]=++dc,dfn_[dc]=x;
	if(son[x])dfs2(son[x],u);
	Fe(i,x)if(y!=F[x]&&y!=son[x])dfs2(y,y);
}

int LCA(int x,int y)
{
	while(U[x]!=U[y])
	{
		if(D[U[x]]>D[U[y]])x=F[U[x]];
		else y=F[U[y]];
	}
	return D[x]<D[y]?x:y;
}

struct Fenwick
{
	int v[MX];
	void Add(int i,int x)
	{
		while(i<=N)v[i]+=x,i+=i&-i;
	}
	void Add(int l,int r,int x)
	{
		Add(l,x),Add(r+1,-x);
	}
	int Ask(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=i&-i;
		return r;
	}
}T;


int main()
{
	IO>>N;
	Fr(i,2,N)
	{
		int x,y;
		IO>>x>>y;
		Link(x,y),Link(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
//	Fr(i,1,N)printf("%d ",son[i]);putchar('\n');
	IO>>M;
	Fr(i,1,M)
	{
		int o;
		IO>>o;
		if(o==1||o==2)
		{
			int e;
			IO>>e,e<<=1;
			int x=E[e^1].y,y=E[e].y;
			int z=D[x]>D[y]?x:y;
			int delta=o-1-A[z];
			if(delta)T.Add(dfn[z],dfn[z]+sz[z]-1,delta);
			A[z]=o-1;
		}
		else
		{
			int x,y;
			IO>>x>>y;
			int z=LCA(x,y);
			int q=T.Ask(dfn[x])+T.Ask(dfn[y])-2*T.Ask(dfn[z]);
			printf("%d\n",q?-1:D[x]+D[y]-2*D[z]);
		}
	}
	return 0;
}