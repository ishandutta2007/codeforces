#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[2005],dp[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0]=1;
	for(int i=1;i<=n;i++)for(int j=200000;j>=a[i];j--)dp[j]|=dp[j-a[i]];
	int sum=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(a[i]%2)pos=i;
		}
	if(dp[sum/2]==0&&sum%2==0)
			{
				printf("0\n");
				return 0;
			}
	while(1)
	{
		int sum=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(a[i]%2)pos=i;
		}
		if(sum%2)
		{
			printf("0\n");
			return 0;
		}
		else
		{
			if(pos)
			{
				printf("1\n%d\n",pos);
				return 0;
			}
			else for(int i=1;i<=n;i++)a[i]/=2;
		}
	}
	return 0;
}