#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int N,M,qc;
vector<int> Q[MX];

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec=1;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int dfn[MX],low[MX],dc;
int stk[MX],tp,bcc[MX],bc;
void Tarjan(int x,int e)
{
	dfn[x]=low[x]=++dc,stk[++tp]=x;
	Fe(i,x,y)
	{
		if(!dfn[y])Tarjan(y,i),low[x]=min(low[x],low[y]);
		else if((i^e)!=1)low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++bc;
		int z=0;
		while(z!=x)z=stk[tp--],bcc[z]=bc;
	}
}

int F[MX],sz[MX],son[MX],dfn_[MX];
void dfs1(int x,int f)
{
	F[x]=f,sz[x]=1,dfn[x]=++dc,dfn_[dc]=x;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}

int B[MX],num1,num2;
inline void Add(int x)
{
	for(int v:Q[x])
	{
		int i=v>>1,a=v&1;
		num1-=B[i]==1;
		num2-=B[i]==2;
		B[i]|=1<<a;
		num1+=B[i]==1;
		num2+=B[i]==2;
	}
}
inline void Del(int x)
{
	for(int v:Q[x])B[v>>1]=0;
}
void dfs2(int x,bool c)
{
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])dfs2(y,1);
	if(son[x])dfs2(son[x],0);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		Fr(j,dfn[y],dfn[y]+sz[y]-1)Add(dfn_[j]);
	}
	Add(x);
	if(num1&&num2)printf("No\n"),exit(0);
	if(x==1&&(num1||num2))printf("No\n"),exit(0);
	if(c)
	{
		Fr(j,dfn[x],dfn[x]+sz[x]-1)Del(dfn_[j]);
		num1=num2=0;
	}
}


int main()
{
	scanf("%d%d%d",&N,&M,&qc);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	Fr(i,1,N)if(!dfn[i])Tarjan(i,0);
	memset(H,0,sizeof(H)),ec=0;
	memset(dfn,0,sizeof(dfn)),dc=0;
	Fr(i,1,M)
	{
		int x=bcc[E[i<<1|1].y],y=bcc[E[i<<1].y];
		if(x!=y)Link(x,y),Link(y,x);
	}
	Fr(i,1,qc)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=bcc[x],y=bcc[y];
		Q[x].push_back(i<<1);
		Q[y].push_back(i<<1|1);
	}
	Fr(x,1,bc)if(!F[x])
		dfs1(x,0),dfs2(x,1);
	printf("Yes\n");
	return 0;
}