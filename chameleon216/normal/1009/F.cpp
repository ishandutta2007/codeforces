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

const int MX=1000100;
int N;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int F[MX],he[MX],son[MX];
void dfs1(int x,int f)
{
	F[x]=f,he[x]=1;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x),he[x]=max(he[x],he[y]+1);
		if(he[y]>he[son[x]])son[x]=y;
	}
}

int dp_[MX],dc,*dp[MX],A[MX];
void dfs2(int x)
{
	dp[x]=&dp_[++dc];
	if(son[x])dfs2(son[x]),A[x]=A[son[x]]+1;
	++dp[x][0];
	if(dp[x][A[x]]<=1)A[x]=0;
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		dfs2(y);
		Fr(j,1,he[y])
		{
			dp[x][j]+=dp[y][j-1];
			if(dp[x][j]>dp[x][A[x]]||(dp[x][j]==dp[x][A[x]]&&j<A[x]))A[x]=j;
		}
	}
}


int main()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0);
	dfs2(1);
	Fr(i,1,N)printf("%d\n",A[i]);
	return 0;
}