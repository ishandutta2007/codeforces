#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[51];
int main()
{
	int num;
	ll gen;
	scanf("%d%I64d",&num,&gen);
	dp[0]=dp[1]=1;
	for(int i=2;i<=50;i++)dp[i]=dp[i-1]+dp[i-2];
	vector<int>ret;
	for(int i=0;i<num;i++)
	{
		if(dp[num-i-1]>=gen)
		{
			ret.push_back(i+1);
		}
		else
		{
			gen-=dp[num-i-1];
			ret.push_back(i+2);
			ret.push_back(i+1);
			i++;
		}
	}
	for(int i=0;i<num;i++)
	{
		if(i!=0)printf(" ");
		printf("%d",ret[i]);
	}
	printf("\n");
}