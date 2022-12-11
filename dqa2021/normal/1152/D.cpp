#include<cstdio>
#include<algorithm>
using namespace std;
//typedef long long ll;
const int Mod=1e9+7;

int n;
int dp[2010][2010][2];
bool vis[2010][2010];
void dfs(int x,int y)
{
	if (vis[x][y]) return; vis[x][y]=true;
	if (x==(n<<1)) return dp[x][y][0]=0,dp[x][y][1]=0,void();
	if (x+y+2<=(n<<1)) dfs(x+1,y+1),dp[x][y][0]=(dp[x][y][0]+dp[x+1][y+1][0])%Mod;
	if (y) dfs(x+1,y-1),dp[x][y][0]=(dp[x][y][0]+dp[x+1][y-1][0])%Mod;
	if (x+y+2<=(n<<1)&&!dp[x+1][y+1][1]||y&&!dp[x+1][y-1][1]) dp[x][y][0]=(dp[x][y][0]+1)%Mod,dp[x][y][1]=1;
	else dp[x][y][1]=0;
}
int main()
{
	scanf("%d",&n);
	dfs(0,0);
	printf("%d\n",dp[0][0][0]);
	return 0;
}