#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<double,int>pdi;
int dp[5000];
int main()
{
	int num,spe;
	scanf("%d%d",&num,&spe);
	vector<pdi>vec;
	for(int i=0;i<num;i++)
	{
		int za;
		double zb;
		scanf("%d%lf",&za,&zb);
		vec.push_back(make_pair(zb,za));
	}
	sort(vec.begin(),vec.end());
	int maxi=0;
	for(int i=0;i<num;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(vec[i].second>=vec[j].second)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		maxi=max(maxi,dp[i]);
	}
	printf("%d\n",num-maxi);
}