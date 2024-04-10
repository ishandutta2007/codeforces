#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	void a(char& c)
	{
		do c=g();
		while(c<=32);
	}
	void y(char* s)
	{
		do *s=g();
		while(*s<=32);
		while(*s>32)*++s=g();
		*s=0;
	}
	template<typename T>
	void d(T& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void w(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	void z(const char* s)
	{
		while(*s)w(*s++);
	}
	template<typename T>
	void v(T x)
	{
		if(x<0)w('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)w(stk[tp--]);
	}
}IO;

const int MX=200100;

int N,M;
ll A[MX];
struct Edge{int x,y,w,b,id;}ed[MX];
inline bool operator<(const Edge& a,const Edge& b)
{
	return a.w<b.w;
}

struct Graph{int y,w,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y,int w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

struct DisjointSet
{
	int f[MX];
	void Build(){Fr(i,1,N)f[i]=i;}
	int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
	bool Union(int x,int y)
	{
		x=Find(x),y=Find(y);
		if(x==y)return 0;
		f[x]=y;
		return 1;
	}
}dsu;

void Kruskal()
{
	sort(ed+1,ed+M+1);
	dsu.Build();
	Fr(i,1,M)
	{
		int x=ed[i].x,y=ed[i].y,w=ed[i].w;
		if(dsu.Union(x,y))
		{
			Link(x,y,w),Link(y,x,w);
			ed[i].b=1;
		}
	}
}

int F[MX],D[MX],sz[MX],son[MX];
int U[MX],dfn[MX],dfn_[MX],dc;
int W[MX],V[MX];
void dfs1(int x,int f,int d,int w)
{
	F[x]=f,D[x]=d,sz[x]=1,W[x]=w;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x,d+1,E[i].w),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int u,int v)
{
	U[x]=u,V[x]=max(v,W[x]),dfn[x]=++dc,dfn_[dc]=x;
	if(son[x])dfs2(son[x],u,V[x]);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])dfs2(y,y,0);
}

#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
int val[MX*4];
void Build(int i,int l,int r)
{
	if(l==r){val[i]=W[dfn_[l]];return;}
	Build(li,l,mid);
	Build(ri,mid+1,r);
	val[i]=max(val[li],val[ri]);
}
int Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return val[i];
	int res=0;
	if(a<=mid)res=max(res,Ask(li,l,mid,a,b));
	if(b>mid)res=max(res,Ask(ri,mid+1,r,a,b));
	return res;
}

int AskP(int x,int y)
{
	int res=0;
	while(U[x]!=U[y])
	{
		if(D[U[x]]<D[U[y]])swap(x,y);
		res=max(res,V[x]),x=F[U[x]];
	}
	if(D[x]>D[y])swap(x,y);
	if(x!=y)res=max(res,Ask(1,1,N,dfn[x]+1,dfn[y]));
	return res;
}

int main()
{
	IO.d(N),IO.d(M);
	Fr(i,1,M)
	{
		IO.d(ed[i].x),IO.d(ed[i].y),IO.d(ed[i].w);
		ed[i].id=i;
	}
	Kruskal();
	dfs1(1,0,1,0);
	dfs2(1,1,0);
	Build(1,1,N);
	ll sum=0;
	Fr(i,2,N)sum+=W[i];
	Fr(i,1,M)
	{
		int id=ed[i].id;
		A[id]=sum;
		if(!ed[i].b)
		{
			int a=AskP(ed[i].x,ed[i].y);
			A[id]+=ed[i].w-a;
		}
	}
	Fr(i,1,M)IO.v(A[i]),IO.w('\n');
	return 0;
}