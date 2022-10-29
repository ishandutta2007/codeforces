#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
long double kai[101];
void calccom()
{
	kai[0]=1;
	for(int i=1;i<=100;i++)
	{
		kai[i]=kai[i-1]*i;
	}
}
ll dp[50][51][50];
int main()
{
	calccom();
	int num;
	scanf("%d",&num);
	vector<int>vec;
	int sum=0;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
		sum+=zan;
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	int gen;
	scanf("%d",&gen);
	if(gen>=sum)
	{
		printf("%d\n",num);
		return 0;
	}
	long double ans=0;
	for(int p=0;p<num;p++)
	{
		vector<int>zv;
		for(int i=0;i<num;i++)
		{
			if(i!=p)
			{
				zv.push_back(vec[i]);
			}
			for(int j=0;j<=gen;j++)
			{
				for(int k=0;k<=num-1;k++)
				{
					dp[i][j][k]=0;
				}
			}
			dp[0][0][0]=1;
		}
		for(int i=0;i<num-1;i++)
		{
			for(int j=0;j<=gen;j++)
			{
				for(int k=0;k<=num-1;k++)
				{
					dp[i+1][j][k]=dp[i][j][k];
				}
				if(j-zv[i]>=0)
				{
					for(int k=0;k<=num-1;k++)
					{
						if(k!=0)
						{
							dp[i+1][j][k]+=dp[i][j-zv[i]][k-1];
						}
					}
				}
			}
		}
		for(int j=gen-vec[p]+1;j<=gen;j++)
		{
			for(int k=0;k<=num-1;k++)
			{
				ans+=(long double)dp[num-1][j][k]*kai[k]*kai[num-1-k]*(long double)k;
			}
		}
	}
	printf("%lf\n",double(ans/kai[num]));
}