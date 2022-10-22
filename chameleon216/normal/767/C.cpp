#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;
const int MX=1200000;
int N,Rt,K;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int sz[MX],dp[MX];
void dfs1(int x)
{
	Fe(i,x)dfs1(y),sz[x]+=sz[y];
}
void Print(int a,int b)
{
	printf("%d %d",a,b);
	exit(0);
}
void dfs2(int x)
{
	Fe(i,x)
	{
		dfs2(y);
		if(dp[y])
		{
			if(dp[x])Print(dp[x],dp[y]);
			else dp[x]=dp[y];
		}
	}
	if(x!=Rt&&dp[x]&&sz[x]==2*K)Print(dp[x],x);
	if(!dp[x]&&sz[x]==K)dp[x]=x;
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int f;
		scanf("%d%d",&f,&sz[i]);
		if(!f)Rt=i;
		else Add(f,i);
	}
	dfs1(Rt);
	if(sz[Rt]%3){printf("-1");return 0;}
	K=sz[Rt]/3;
	dfs2(Rt);
	printf("-1");
	return 0;
}