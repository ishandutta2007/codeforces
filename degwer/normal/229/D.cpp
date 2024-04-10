#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[5000][5000];
int rui[5001];
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	rui[0]=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		rui[i+1]=rui[i]+zan;
	}
	for(int i=0;i<5000;i++)
	{
		for(int j=0;j<5000;j++)
		{
			dp[i][j]=-1000000000;
		}
	}
	for(int i=0;i<num;i++)
	{
		dp[0][i]=1;
	}
	for(int i=1;i<num;i++)
	{
		int maxi=-1000000000;
		int now=i;
		for(int j=i;j<num;j++)
		{
			for(;;)
			{
				if(now<0)
				{
					break;
				}
				if(rui[i]-rui[now]>rui[j+1]-rui[i])
				{
					break;
				}
				else
				{
					maxi=max(maxi,dp[now][i-1]);
					now--;
				}
			}
			dp[i][j]=maxi+1;
		}
	}
	int ans=-1;
	for(int i=0;i<num;i++)
	{
		ans=max(ans,dp[i][num-1]);
	}
	printf("%d\n",num-ans);
}