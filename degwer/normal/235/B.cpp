#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[100001];
int main()
{
	int num;
	scanf("%d",&num);
	double ans=0.0;
	for(int i=0;i<num;i++)
	{
		double zan;
		scanf("%lf",&zan);
		dp[i+1]=(dp[i]+1.0)*zan;
		ans+=(dp[i]*2+1.0)*zan;
	}
	printf("%.10lf\n",ans);
}