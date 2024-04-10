#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dp1[2001];
ll dp2[2001][2001];
ll com[2001][2001];
bool flag[2000];
int main()
{
	int num;
	scanf("%d",&num);
	vector<int>vec;
	fill(flag,flag+2000,false);
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		if(zan>0)
		{
			zan--;
		}
		if(zan>=0)
		{
			flag[zan]=true;
		}
		vec.push_back(zan);
	}
	int na=0,nb=num;
	for(int i=0;i<num;i++)
	{
		if(vec[i]>=0)
		{
			if(flag[i])
			{
				nb--;
			}
			else
			{
				na++;
				nb--;
				nb--;
			}
		}
	}
	for(int i=1;i<=num;i++)
	{
		com[i][0]=com[i][i]=1;
		for(int j=1;j<=i-1;j++)
		{
			com[i][j]=(com[i-1][j]+com[i-1][j-1])%mod;
		}
	}
	dp1[0]=1;
	dp1[1]=0;
	for(int i=2;i<=num;i++)
	{
		dp1[i]=1;
		for(int j=1;j<=i;j++)
		{
			dp1[i]*=j;
			dp1[i]%=mod;
		}
		for(int j=0;j<i;j++)
		{
			dp1[i]=(dp1[i]+mod-(dp1[j]*com[i][j])%mod)%mod;
		}
	}
	for(int i=1;i<=num;i++)
	{
		dp2[0][i]=dp1[i];
	}
	ll now=1;
	for(int i=1;i<=num;i++)
	{
		dp2[i][0]=now;
		now*=(i+1);
		now%=mod;
	}
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=num;j++)
		{
			dp2[i][j]=(dp2[i][j-1]*j+dp2[i-1][j]*i)%mod;
		}
	}
	printf("%I64d\n",dp2[na][nb]);
}