#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;
const int MX=220000,Mod=1000000007;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int N;
int C[MX];
ll dp[MX][2];

void dfs1(int x)
{
	dp[x][C[x]]=1;
	Fe(i,x)
	{
		dfs1(y);
		dp[x][1]=(dp[x][1]*(dp[y][1]+dp[y][0])%Mod+dp[x][0]*dp[y][1]%Mod)%Mod;
		dp[x][0]=dp[x][0]*(dp[y][1]+dp[y][0])%Mod;
	}
}


int main()
{
	scanf("%d",&N);
	Fr(x,2,N)
	{
		int f;
		scanf("%d",&f),++f;
		Add(f,x);
	}
	Fr(x,1,N)scanf("%d",&C[x]);
	dfs1(1);
	printf("%lld\n",dp[1][1]);
	return 0;
}