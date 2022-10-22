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

template<typename Tp>
void Read(Tp& x)
{
	char c=getchar(),l=0;
	for(x=0;!isdigit(c);c=getchar())l=c;
	for(;isdigit(c);c=getchar())x=x*10-'0'+c;
	if(l=='-')x=-x;
}

template<typename T1,typename T2>
inline void max_eq(T1& a,T2 b){if(a<b)a=b;}
template<typename T1,typename T2>
inline void min_eq(T1& a,T2 b){if(b<a)a=b;}

const int MX=6050,Inf=0x3f3f3f3f;
int N,W[MX];

struct Arc{int y,nx;}E[MX<<1];
int H[MX],ac;
void Link(int x,int y)
{
	E[++ac].y=y,E[ac].nx=H[x],H[x]=ac;
}

int F[MX],he[MX],son[MX];
void dfs1(int x,int f)
{
	F[x]=f,he[x]=1;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x),max_eq(he[x],he[y]+1);
		if(he[y]>he[son[x]])son[x]=y;
	}
}

int P[MX*6],*pc=P,ans;
int cmp(int a,int b){return a>b;}
void Alloc(int n,int*& dp,int*& ep)
{
	dp=pc,pc+=n+2,ep=pc,pc+=n+2;
	memset(dp,0x3f,(n+2)*sizeof(int));
	memset(ep,0xc0,(n+2)*sizeof(int));
}

void dfs2(int x,int* d,int* e)
{
	if(son[x])dfs2(son[x],d,e);
	int p;
	p=lower_bound(d+1,d+he[x]+1,W[x])-d;
	d[p]=W[x],max_eq(ans,p);
	p=lower_bound(e+1,e+he[x]+1,W[x],cmp)-e;
	e[p]=W[x],max_eq(ans,p);
	
	Fe(j,x,y)if(y!=F[x]&&y!=son[x])
	{
		int *d_,*e_;
		Alloc(he[y],d_,e_);
		dfs2(y,d_,e_);
		Fr(i,1,he[y])
		{
			if(e_[i]!=-Inf-1)
			{
				p=lower_bound(d+1,d+he[x]+1,e_[i])-d-1;
				max_eq(ans,p+i);
			}
			if(d_[i]!=Inf)
			{
				p=lower_bound(e+1,e+he[x]+1,d_[i],cmp)-e-1;
				max_eq(ans,p+i);
			}
		}
		*lower_bound(d_+1,d_+he[y]+2,W[x])=W[x];
		*lower_bound(e_+1,e_+he[y]+2,W[x],cmp)=W[x];
		Fr(i,1,he[y]+1)min_eq(d[i],d_[i]),max_eq(e[i],e_[i]);
	}
}

int main()
{
	Read(N);
	Fr(i,1,N)Read(W[i]);
	Fr(i,2,N)
	{
		int x,y;
		Read(x),Read(y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0);
	int *dp,*ep;
	Alloc(he[1],dp,ep);
	dfs2(1,dp,ep);
	printf("%d\n",ans);
	return 0;
}