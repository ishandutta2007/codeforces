#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int dat[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int dp[101][1<<16];
int frm[101][1<<16];
int used[101][1<<16];
typedef pair<int,int>pii;
int ans[100];
int bun[100];
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(make_pair(zan,i));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<num-16;i++)
	{
		ans[vec[i].second]=1;
	}
	for(int i=1;i<=99;i++)
	{
		for(int j=0;j<16;j++)
		{
			if(i%dat[j]==0)
			{
				bun[i]|=(1<<j);
			}
		}
	}
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<(1<<16);j++)
		{
			dp[i][j]=1000000;
			used[i][j]=1;
		}
	}
	dp[max(0,num-16)][0]=0;
	for(int i=max(0,num-16);i<num;i++)
	{
		for(int j=0;j<(1<<16);j++)
		{
			for(int k=used[i][j];k<=58;k++)
			{
				if((j&bun[k])==0)
				{
					if(dp[i][j]+abs(vec[i].first-k)<dp[i+1][j|bun[k]])
					{
						dp[i+1][j|bun[k]]=dp[i][j]+abs(vec[i].first-k);
						frm[i+1][j|bun[k]]=j;
						used[i+1][j|bun[k]]=k;
					}
				}
			}
		}
	}
	int mini=1000000;
	int now;
	for(int i=0;i<(1<<16);i++)
	{
		if(mini>dp[num][i])
		{
			mini=dp[num][i];
			now=i;
		}
	}
	for(int i=num;i>=max(0,num-16)+1;i--)
	{
		ans[vec[i-1].second]=used[i][now];
		now=frm[i][now];
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");
}