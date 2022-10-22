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

const int MX=200100;
int N,M;

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

char B[MX],C[MX];
void dfs1(int x,int b)
{
	B[x]=b;
	Fe(i,x,y)
	{
		if(!B[y])dfs1(y,3-b);
		else if(B[y]==b)printf("NO\n"),exit(0);
	}
}

int id[MX],ic;
void dfs2(int x)
{
	C[x]=1;
	Fe(i,x,y)if(E[i].w)
	{
		if(C[y]==0)dfs2(y);
		else if(C[y]==1)printf("NO\n"),exit(0);
	}
	C[x]=2,id[x]=++ic;
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y,w;
		scanf("%d%d%d",&w,&x,&y);
		Link(x,y,w),Link(y,x,w);
	}
	Fr(x,1,N)if(!B[x])dfs1(x,1);
	Fr(i,1,ec)if(E[i].w!=B[E[i].y])E[i].w=0;
	Fr(x,1,N)if(!C[x])dfs2(x);
	printf("YES\n");
	Fr(x,1,N)printf("%c %d\n",B[x]==1?'L':'R',id[x]);
	return 0;
}//