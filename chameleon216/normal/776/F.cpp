#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=100100,Inf=0x3f3f3f3f;
int N,M,A[MX];

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec=1;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int L[MX],R[MX],stk[MX],tp;
void Build()
{
	int c=0;
	Fr(i,1,N)
	{
		Fl(j,R[i],1)
		{
			int x=c+j;
			while(int y=stk[tp--])Link(x,y),Link(y,x);
			stk[++tp]=x;
		}
		Fr(j,1,L[i])stk[++tp]=0;
		c+=R[i];
	}
}

int B[MX],O[MX],oc,dz[MX],mz[MX];
void dfs1(int x,int f)
{
	O[++oc]=x,dz[x]=1,mz[x]=0;
	Fe(i,x,y)if(!B[y]&&y!=f)
		dfs1(y,x),dz[x]+=dz[y],mz[x]=max(mz[x],dz[y]);
}
int Centroid(int rt)
{
	oc=0,dfs1(rt,0);
	int z=dz[rt];
	Fr(i,2,oc)
	{
		int x=O[i];
		mz[x]=max(mz[x],z-dz[x]);
		if(mz[x]<mz[rt])rt=x;
	}
	return rt;
}
void Divide(int x,int c)
{
	x=Centroid(x),B[x]=c;
	Fe(i,x,y)if(!B[y])Divide(y,c+1);
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		++L[x],++R[y];
	}
	++L[1],++R[N];
	Build();
	Divide(1,1);
	Fr(i,1,M+1)printf("%d ",B[i]);
	putchar('\n');
	return 0;
}