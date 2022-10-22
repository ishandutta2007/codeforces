#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=400100;
int N,M,X[MX],Y[MX];

struct Graph{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int dfn[MX],low[MX],dc;
int stk[MX],tp,scc[MX],sc;
void Tarjan(int x)
{
	dfn[x]=low[x]=++dc,stk[++tp]=x;
	Fe(i,x,y)
	{
		if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
		else if(!scc[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++sc;
		int z=0;
		while(x!=z)z=stk[tp--],scc[z]=sc;
	}
}

int dp[MX];

int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		scanf("%d%d",&X[i],&Y[i]);
		Link(X[i],Y[i]);
	}
	Tarjan(1);
	memset(H,0,(N+1)*sizeof(int));
	dp[scc[1]]=1,ec=0;
	Fr(i,1,M)
	{
		int x=scc[X[i]],y=scc[Y[i]];
		if(!x||!y)continue;
		else if(x==y)dp[x]=-1;
		else Link(x,y);
	}
	Fl(x,sc,1)Fe(i,x,y)
	{
		if(dp[x]==-1||dp[y]==-1)dp[y]=-1;
		else dp[y]=min(dp[x]+dp[y],2);
	}
	Fr(x,1,N)printf("%d ",dp[scc[x]]);
	putchar('\n');
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
		memset(H,0,(N+1)*sizeof(*H));
		memset(dfn,0,(N+1)*sizeof(*dfn));
		memset(low,0,(N+1)*sizeof(*low));
		memset(scc,0,(N+1)*sizeof(*scc));
		memset(dp,0,(N+1)*sizeof(*dp));
		ec=tp=dc=sc=0;
	}
}