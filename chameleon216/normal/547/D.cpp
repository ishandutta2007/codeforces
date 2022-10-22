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

const int MX=400100,N=200000;
int M,deg[MX];

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec=1;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int ans[MX];
void dfs(int x)
{
	while(H[x])
	{
		int i=H[x];
		H[x]=E[i].nx;
		if(E[i].w)continue;
		E[i].w=E[i^1].w=1;
		dfs(E[i].y);
		ans[i>>1]=i&1;
	}
}

int main()
{
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y),y+=N;
		Link(x,y),Link(y,x),++deg[x],++deg[y];
	}
	Fr(x,1,2*N)if(deg[x]&1)Link(2*N+1,x),Link(x,2*N+1);
	Fr(x,1,2*N+1)dfs(x);
	Fr(i,1,M)putchar(ans[i]?'r':'b');
	putchar('\n');
	return 0;
}