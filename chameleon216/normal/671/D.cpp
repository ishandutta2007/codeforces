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

const int MX=300100;
int N,M,I[MX],D[MX];

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

struct SkewHeap{ll v,z;int d,l,r;}T[MX];
void Add(int x,ll v){if(x)T[x].v+=v,T[x].z+=v;}
void PushDown(int x)
{
	if(T[x].z)
	{
		Add(T[x].l,T[x].z);
		Add(T[x].r,T[x].z);
		T[x].z=0;
	}
}
int Merge(int x,int y)
{
	if(!x||!y)return x|y;
	if(T[x].v>T[y].v)swap(x,y);
	PushDown(x);
	T[x].r=Merge(T[x].r,y);
	swap(T[x].l,T[x].r);
	return x;
}
void Pop(int& x)
{
	PushDown(x);
	x=Merge(T[x].l,T[x].r);
}

void dfs1(int x,int f,int d)
{
	D[x]=d;
	Fe(i,x,y)if(y!=f)dfs1(y,x,d+1);
}
void dfs2(int x,int f)
{
	ll s=0;
	Fe(i,x,y)if(y!=f)
	{
		dfs2(y,x);
		s+=T[I[y]].v,Add(I[y],-T[I[y]].v);
		I[x]=Merge(I[x],I[y]);
	}
	Add(I[x],s);
	while(T[I[x]].d>=D[x])Pop(I[x]);
	if(!I[x])printf("-1\n"),exit(0);
}

int main()
{
	scanf("%d%d",&N,&M);
	if(N==1)printf("0\n"),exit(0);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0,1);
	Fr(i,1,M)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		T[i].v=c,T[i].d=D[y],I[x]=Merge(I[x],i);
	}
	ll ans=0;
	Fe(i,1,y)dfs2(y,1),ans+=T[I[y]].v;
	printf("%lld\n",ans);
	return 0;
}