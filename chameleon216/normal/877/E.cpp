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
const int MX=200100;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M,F[MX],A[MX];
int sz[MX],dfn[MX],dfn_[MX],dc;
void dfs1(int x)
{
	sz[x]=1,dfn[x]=++dc,dfn_[dc]=x;
	Fe(i,x)dfs1(y),sz[x]+=sz[y];
}

struct Segment
{
	int v,z,l,r;
	void flip(){v=(r-l+1-v),z^=1;}
}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
void PushUp(int i){T[i].v=T[li].v+T[ri].v;}
void PushDown(int i)
{
	if(T[i].z)T[li].flip(),T[ri].flip(),T[i].z=0;
}
void Build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r;
	if(l==r){T[i].v=A[dfn_[l]];return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	PushUp(i);
}
void Flip(int i,int a,int b)
{
	if(a<=T[i].l&&T[i].r<=b){T[i].flip();return;}
	PushDown(i);
	if(a<=T[li].r)Flip(li,a,b);
	if(b>=T[ri].l)Flip(ri,a,b);
	PushUp(i);
}
int Ask(int i,int a,int b)
{
	if(a<=T[i].l&&T[i].r<=b)return T[i].v;
	PushDown(i);
	int res=0;
	if(a<=T[li].r)res+=Ask(li,a,b);
	if(b>=T[ri].l)res+=Ask(ri,a,b);
	return res;
}


int main()
{
	scanf("%d",&N);
	Fr(i,2,N)scanf("%d",&F[i]),Link(F[i],i);
	Fr(i,1,N)scanf("%d",&A[i]);
	scanf("%d",&M);
	dfs1(1);
	Build(1,1,N);
	char o[10];
	int x;
	Fr(i,1,M)
	{
		scanf("%s%d",o,&x);
		if(*o=='g')printf("%d\n",Ask(1,dfn[x],dfn[x]+sz[x]-1));
		else Flip(1,dfn[x],dfn[x]+sz[x]-1);
	}
	return 0;
}