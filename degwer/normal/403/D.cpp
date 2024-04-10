#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dp[51][1001];
ll rui[51][1001];
ll po(ll a,ll b)
{
	vector<int>vec;
	for(;;)
	{
		if(b==0)
		{
			break;
		}
		vec.push_back(b%2);
		b/=2;
	}
	reverse(vec.begin(),vec.end());
	ll ret=1;
	for(int i=0;i<vec.size();i++)
	{
		ret*=ret;
		ret%=mod;
		if(vec[i])
		{
			ret*=a;
			ret%=mod;
		}
	}
	return ret;
}
ll inv(ll a)
{
	return po(a,mod-2);
}
ll kai[2001];
ll invkai[2001];
void calc()
{
	kai[0]=invkai[0]=1;
	for(int i=1;i<=2000;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=mod;
	}
	for(int i=1;i<=2000;i++)
	{
		invkai[i]=inv(kai[i]);
	}
}
ll com(ll a,ll b)
{
	ll ret=kai[a];
	ret*=inv(kai[b]);
	ret%=mod;
	ret*=inv(kai[a-b]);
	ret%=mod;
	return ret;
}
ll ans[51][1001];
int main()
{
	calc();
	dp[0][0]=1;
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<1000;j++)
		{
			for(int k=j;k<=1000;k+=i+1)
			{
				dp[i+1][k]+=dp[i][j];
				dp[i+1][k]%=mod;
			}
		}
	}
	for(int i=0;i<=50;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			for(int k=0;k<=j;k++)
			{
				ans[i][j]+=((dp[i][k]*kai[i+j-k])%mod*invkai[j-k])%mod;
				ans[i][j]%=mod;
			}
		}
	}/*
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=10;j++)
		{
			printf("%d  ",dp[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=10;j++)
		{
			printf("%d  ",ans[i][j]);
		}
		printf("\n");
	}*/
	int data;
	scanf("%d",&data);
	for(int p=0;p<data;p++)
	{
		int num,ko;
		scanf("%d%d",&num,&ko);
		num-=ko*(ko+1)/2;
		if(num<0)
		{
			printf("0\n");
			continue;
		}
		printf("%I64d\n",ans[ko][num]);
	}
}