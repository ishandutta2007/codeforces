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
	char ob[MB+100],*r,stk[128];
	
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char Get()
	{
//		return getchar();
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void Read(Tp& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void Put(char c)
	{
//		putchar(c);return;
		if(r-ob==MB)fwrite(ob,1,MB,stdout),r=ob;
		*r++=c;
	}
	template<typename Tp>
	void Write(Tp x)
	{
		if(x<0)Put('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
}IO;

const int MX=100100,W=100000005;
int N,M;

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

int rt=1,dis;
void dfs1(int x,int f,int d)
{
	if(d>dis)rt=x,dis=d;
	Fe(i,x,y)if(y!=f)dfs1(y,x,d+E[i].w);
}

int F[MX],he[MX],son[MX];
void dfs2(int x,int f,int w)
{
	F[x]=f;
	Fe(i,x,y)if(y!=f)
	{
		dfs2(y,x,E[i].w),he[x]=max(he[x],he[y]);
		if(he[y]>he[son[x]])son[x]=y;
	}
	he[x]+=w;
}

struct SegmentTree{int v,s,l,r;}T[MX*90];
int tc;
inline int Copy(int i){T[++tc]=T[i];return tc;}
void Ins(int& i,int l,int r,int a,int k)
{
	i=Copy(i),T[i].v+=k,T[i].s+=a*k;
	if(l==r)return;
	int m=(l+r)>>1;
	if(a<=m)Ins(T[i].l,l,m,a,k);
	else Ins(T[i].r,m+1,r,a,k);
}
int Query(int i,int l,int r,int k)
{
	if(l==r){return l*min(k,T[i].v);}
	int m=(l+r)>>1;
	if(k<=T[T[i].r].v)return Query(T[i].r,m+1,r,k);
	else return Query(T[i].l,l,m,k-T[T[i].r].v)+T[T[i].r].s;
}

int I[MX],len[MX];
void dfs3(int x,int t,int n)
{
	I[x]=t,len[x]=n;
	if(son[x])dfs3(son[x],t,n);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		int a=t,nn=max(he[son[x]],n-he[son[x]]);
		Ins(a,1,W,he[y],-1);
		Ins(a,1,W,n-nn,1);
		dfs3(y,a,nn+he[y]);
	}
}

int main()
{
	IO.Read(N),IO.Read(M);
	Fr(i,2,N)
	{
		int x,y,w;
		IO.Read(x),IO.Read(y),IO.Read(w);
		Link(x,y,w),Link(y,x,w);
	}
	dfs1(1,0,0);
//	printf("%d %d\n",rt,dis);
	dfs2(rt,0,0);
//	printf("I   ");Fr(x,1,N)printf("%2d ",x);putchar('\n');
//	printf("F   ");Fr(x,1,N)printf("%2d ",F[x]);putchar('\n');
//	printf("he  ");Fr(x,1,N)printf("%2d ",he[x]);putchar('\n');
//	printf("son ");Fr(x,1,N)printf("%2d ",son[x]);putchar('\n');
	
	int t=0;
	Fr(x,1,N)if(F[x]&&son[F[x]]!=x)
		Ins(t,1,W,he[x],1);
	
	dfs3(rt,t,he[rt]);
	int las=0;
	Fr(i,1,M)
	{
		int x,k;
		IO.Read(x),IO.Read(k);
		x=(x+las-1)%N+1,k=(k+las-1)%N+1;
		las=len[x]+Query(I[x],1,W,2*(k-1));
		IO.Write(las),IO.Put('\n');
	}
	
	return 0;
}