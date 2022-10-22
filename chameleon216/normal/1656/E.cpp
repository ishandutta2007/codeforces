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

const int MX=100100;
int N,W[MX],deg[MX];

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

void dfs(int x,int f,int s)
{
	Fe(i,x,y)if(y!=f)
		dfs(y,x,-s);
	W[x]=deg[x]*s;
}

int Work()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
		++deg[x],++deg[y];
	}
	dfs(1,0,1);
	Fr(x,1,N)printf("%d ",W[x]);putchar('\n');
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		Work();
		Fr(x,1,N)H[x]=deg[x]=W[x]=0;
		ec=0;
	}
	return 0;
}