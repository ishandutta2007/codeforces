#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool dp[30000];
int main()
{
	int num,mok;
	scanf("%d%d",&num,&mok);
	mok--;
	vector<int>vec;
	for(int i=0;i<num-1;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	fill(dp,dp+num,false);
	dp[0]=true;
	for(int i=0;i<num-1;i++)
	{
		if(dp[i])
		{
			dp[i+vec[i]]=true;
		}
	}
	if(dp[mok])printf("YES\n");
	else printf("NO\n");
}