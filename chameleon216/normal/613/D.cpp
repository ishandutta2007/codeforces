#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void d(Tp& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
}IO;

const int MX=100100;
int N,M;

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int F[MX],D[MX],sz[MX],son[MX];
int U[MX],dfn[MX],dc;
void dfs1(int x,int f,int d)
{
	F[x]=f,D[x]=d,sz[x]=1;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x,d+1),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,dfn[x]=++dc;
	if(son[x])dfs2(son[x],u);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])dfs2(y,y);
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

bool cmp(int x,int y){return dfn[x]<dfn[y];}


int X[MX],xc,Y[MX*2],yc;
int fa[MX],B[MX],dp[MX],ans;

void dfs3(int x)
{
	int c=0;
	Fe(i,x,y)dfs3(y),c+=dp[y];
	if(B[x])ans+=c,dp[x]=1;
	else if(c>=2)++ans;
	else dp[x]=c;
}

void Build()
{
	sort(X+1,X+xc+1,cmp);
	Fr(i,1,xc)Y[++yc]=X[i];
	Fr(i,2,xc)Y[++yc]=LCA(X[i-1],X[i]);
	sort(Y+1,Y+yc+1,cmp);
	yc=unique(Y+1,Y+yc+1)-Y-1;
	
	Fr(i,2,yc)
	{
		int x=Y[i-1],y=Y[i];
		while(dfn[x]+sz[x]<=dfn[y])x=fa[x];
		Link(x,y),fa[y]=x;
	}
}
int Calc()
{
	Fr(i,1,xc)B[X[i]]=1;
	Fr(i,1,xc)if(B[F[X[i]]])return -1;
	dfs3(Y[1]);
	return ans;
}
void Destroy()
{
	Fr(i,1,yc)
	{
		int x=Y[i];
		H[x]=fa[x]=B[x]=dp[x]=0;
	}
	ec=xc=yc=ans=0;
}


int main()
{
	IO.d(N);
	Fr(i,2,N)
	{
		int x,y;
		IO.d(x),IO.d(y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	memset(H,0,sizeof(H)),ec=0;
	
	IO.d(M);
	Fr(i,1,M)
	{
		IO.d(xc);
		Fr(j,1,xc)IO.d(X[j]);
		Build();
		printf("%d\n",Calc());
		Destroy();
	}
	return 0;
}