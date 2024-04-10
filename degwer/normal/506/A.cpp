#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef pair<int,int>pii;
typedef pair<pii,int>pi3;
int dat[30001];
int dp[30001][1601];
int main()
{
	int num,d;
	scanf("%d%d",&num,&d);
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		dat[zan]++;
	}
	int maxi=0;
	for(int i=0;i<=30000;i++)for(int j=0;j<=1600;j++)dp[i][j]=-1000000000;
	dp[d][800]=dat[d];
	for(int i=d;i<=30000;i++)
	{
		for(int j=-800;j<=800;j++)
		{
			if(d+j>=1)
			{
				for(int k=-1;k<=1;k++)
				{
					if(d+j+k>=1&&i+d+j+k<=30000)
					{
						dp[i+d+j+k][j+k+800]=max(dp[i+d+j+k][j+k+800],dp[i][j+800]+dat[i+d+j+k]);
					}
				}
			}
			maxi=max(maxi,dp[i][j+800]);
		}
	}
	printf("%d\n",maxi);
}