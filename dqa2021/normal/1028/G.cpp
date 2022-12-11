#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll dp[10010][6];
bool vis[10010][6];
ll dfs(int x,int y)
{
	if (vis[x][y]) return dp[x][y];
	vis[x][y]=true;
	if (y==1) return dp[x][y]=x;
	dp[x][y]=dfs(x,y-1);
	for (int i=1;i<=x;i++)
	{
		dp[x][y]++;
		dp[x][y]+=dfs(min(x+dp[x][y],10000LL),y-1);
	}
	return dp[x][y];
}
ll bin[10010]; int bintop;
void print()
{
	printf("%d",bintop);
	for (int i=1;i<=bintop;i++) printf(" %lld",bin[i]);
	printf("\n");
	fflush(stdout);  //about interactive rules?
}
void dfs2(ll x,int y)
{
	int xx=min(10000LL,x);  //caution xx and x
	if (y==1)
	{
		bintop=0;
		for (int i=0;i<xx;i++) bin[++bintop]=x+i;
		print();
		scanf("%*d");
		return;
	}
	bintop=0;
	ll cur=dp[xx][y-1];
	for (int i=1;i<=xx;i++)
	{
		bin[++bintop]=x+cur;
		cur++; cur+=dp[min(xx+cur,10000LL)][y-1];
	}
	print();
	int res; scanf("%d",&res);
	if (res==-1) return;
	if (!res) return dfs2(x,y-1);
	dfs2(bin[res]+1,y-1);
}
int main()
{
	dfs(1,5);
	dfs2(1,5);
	return 0;
}