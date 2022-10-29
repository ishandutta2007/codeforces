#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[201][40001][2];
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
	int num,pa,pb;
	fscanf(fr,"%d%d%d",&num,&pa,&pb);
	vector<int>vec;
	vec.push_back(0);
	for(int i=0;i<num;i++)
	{
		int zan;
		fscanf(fr,"%d",&zan);
		vec.push_back(zan);
	}
	for(int i=0;i<=num;i++)
	{
		for(int j=0;j<40001;j++)
		{
			dp[i][j][0]=dp[i][j][1]=1000000000;
		}
	}
	dp[0][0][0]=dp[0][0][1]=0;
	int sum=0;
	for(int i=1;i<=num;i++)
	{
		sum+=vec[i];
		for(int j=0;j<=40000;j++)
		{
			if(j<=pa&&j>=vec[i])
			{
				dp[i][j][0]=min(dp[i-1][j-vec[i]][0],dp[i-1][j-vec[i]][1]+min(vec[i],vec[i-1]));
			}
			if(sum-j<=pb&&sum-j>=0)
			{
				dp[i][j][1]=min(dp[i-1][j][1],dp[i-1][j][0]+min(vec[i],vec[i-1]));
			}
		}
	}
	int mini=1000000000;
	for(int i=0;i<=40000;i++)
	{
		mini=min(mini,min(dp[num][i][0],dp[num][i][1]));
	}
	if(mini==1000000000)
	{
		fprintf(fw,"-1\n");
	}
	else
	{
		fprintf(fw,"%d\n",mini);
	}
}