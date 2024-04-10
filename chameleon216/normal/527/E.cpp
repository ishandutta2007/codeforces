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

const int MX=400100;
int N,M,deg[MX];

struct Edge{int y,b,nx;}E[MX*2];
int H[MX],ec=1;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}
void Link(int x,int y){Add(x,y),Add(y,x);}

int X[MX],Y[MX],cc,cur=0;
void dfs2(int x)
{
	while(H[x])
	{
		int i=H[x];
		H[x]=E[i].nx;
		if(E[i].b)continue;
		E[i].b=E[i^1].b=1,dfs2(E[i].y);
		X[++cc]=x,Y[cc]=E[i].y;
		if(cur^=1)swap(X[cc],Y[cc]);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y);
		++deg[x],++deg[y];
	}
	int las=0;
	Fr(x,1,N)if(deg[x]&1)
	{
		if(!las)las=x;
		else Link(x,las),las=0;
	}
	if((ec/2)&1)Link(1,1);
	Fr(x,1,N)dfs2(x);
	printf("%d\n",cc);
	Fr(i,1,cc)printf("%d %d\n",X[i],Y[i]);
	return 0;
}