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
struct FuckCCF
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
	void z(char* s)
	{
		do *s=g();
		while(*s<=32);
		while(*s>32)*++s=g();
		*s=0;
	}
}IO;

const int MX=400100;
int N,M;
char S[MX];

int C[MX][26],F[MX],len[MX],sc=1,las=1;
int I[MX];
void Extend(char c)
{
	int k=c-'a',x=las,y=++sc;
	las=y,len[y]=len[x]+1;
	while(x&&!C[x][k])C[x][k]=y,x=F[x];
	if(!x)F[y]=1;
	else
	{
		int z=C[x][k];
		if(len[z]==len[x]+1)F[y]=z;
		else
		{
			int w=++sc;
			memcpy(C[w],C[z],sizeof(C[z]));
			F[w]=F[z],F[y]=F[z]=w;
			len[w]=len[x]+1;
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
}

struct Edge{int y,nx;}E[MX];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int D[MX],sz[MX],son[MX],U[MX],dfn[MX],dc;
void dfs1(int x,int d)
{
	D[x]=d,sz[x]=1;
	Fe(i,x,y)
	{
		dfs1(y,d+1),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,dfn[x]=++dc;
	if(son[x])dfs2(son[x],u);
	Fe(i,x,y)if(y!=son[x])dfs2(y,y);
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
int fa[MX],X[MX],xc,rt;
/*void Build()
{
	sort(X+1,X+xc+1,cmp);
	int n=xc;
	Fr(i,2,n)X[++xc]=LCA(X[i-1],X[i]);
	sort(X+1,X+xc+1,cmp);
	xc=unique(X+1,X+xc+1)-X-1;
	Fr(i,2,xc)
	{
		int x=X[i-1],y=X[i];
		while(dfn[x]+sz[x]<=dfn[y])x=fa[x];
		Link(x,y),fa[y]=x;
	}
}*/
void Build()
{
	sort(X+1,X+xc+1,cmp);
	xc=unique(X+1,X+xc+1)-X-1;
	int n=xc;
	Fr(i,2,n)
	{
		int x=X[i-1],y=X[i],z=LCA(x,y);
		while(D[fa[x]]>=D[z])x=fa[x];
		if(x==z)fa[y]=x;
		else fa[z]=fa[x],fa[x]=fa[y]=z,X[++xc]=z;
	}
	Fr(i,1,xc)
	{
		int x=X[i];
		if(fa[x])Link(fa[x],x);
		else rt=x;
	}
}


int A[MX],B[MX];
ll ans;
void dfs3(int x)
{
	ans+=(ll)A[x]*B[x]*len[x];
	Fe(i,x,y)
	{
		dfs3(y);
		ans+=((ll)A[x]*B[y]+(ll)B[x]*A[y])*len[x];
		A[x]+=A[y],B[x]+=B[y];
	}
}


int main()
{
	IO.d(N),IO.d(M),IO.z(S+1);
	Fl(i,N,1)Extend(S[i]),I[i]=las;
	Fr(x,2,sc)Link(F[x],x);
	dfs1(1,1);
	dfs2(1,1);
	memset(H,0,sizeof(H)),ec=0;
	Fr(i,1,M)
	{
		int a,b,s;
		IO.d(a),IO.d(b);
		Fr(j,1,a)IO.d(s),X[++xc]=I[s],++A[X[xc]];
		Fr(j,1,b)IO.d(s),X[++xc]=I[s],++B[X[xc]];
		Build();
//		dfs3(X[1]);
		dfs3(rt);
		printf("%lld\n",ans);
		Fr(j,1,xc)
		{
			int x=X[j];
			fa[x]=H[x]=A[x]=B[x]=X[j]=0;
		}
		xc=ans=ec=rt=0;
	}
	return 0;
}