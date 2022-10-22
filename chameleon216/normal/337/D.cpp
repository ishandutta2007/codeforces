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
const int MX=220000,Inf=0x3f3f3f3f;
int N,M,D,C[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int dp[MX],ep[MX];

void dfs1(int x,int f)
{
	dp[x]=C[x]?0:-Inf;
	Fe(i,x)if(y!=f)
		dfs1(y,x),dp[x]=max(dp[x],dp[y]+1);
}

void dfs2(int x,int f)
{
	int mx1=C[x]?0:-Inf,mx2=C[x]?0:-Inf,son=0;
	Fe(i,x)
	{
		int a=(y==f?ep[x]:dp[y])+1;
		if(a>mx1)mx2=mx1,mx1=a,son=y;
		else if(a>mx2)mx2=a;
	}
	Fe(i,x)if(y!=f)
		ep[y]=(y==son?mx2:mx1),dfs2(y,x);
}

int main()
{
	scanf("%d%d%d",&N,&M,&D);
	Fr(i,1,M)
	{
		int x;
		scanf("%d",&x),C[x]=1;
	}
	Fo(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y),Add(x,y),Add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	int cnt=0;
	Fr(x,1,N)
	{
		int d=dp[x];
		if(x!=1)d=max(d,ep[x]+1);
		if(d<=D)++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}