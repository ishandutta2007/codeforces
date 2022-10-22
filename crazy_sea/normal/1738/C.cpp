#include<cstdio>
using namespace std;
bool dp[120][120][2];
bool chk(int x,int y,bool p)
{ 
	if(x<0||y<0) return 0;
	if(x==0&&y==0) return !p;
	if(x==0) return dp[x][y-1][p];
	else if(y==0) return dp[x-1][y][p];
	else return dp[x-1][y][p]&dp[x][y-1][p];
}
void init(int n)
{
	dp[0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0&&j==0) continue;
			for(int k=0;k<2;k++)
				dp[i][j][k]=chk(i-1,j,k^1)|chk(i,j-1,k);
		}
	}
}
int n,t1,t0,a,T;
int main()
{
	scanf("%d",&T);
	init(100);
	while(T--)
	{
		scanf("%d",&n);
		t0=t1=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a%2==0) t0++;
			else t1++;
		}
		printf("%s\n",dp[t1][t0][0]?"Alice":"Bob");
	}
}