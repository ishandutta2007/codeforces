#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dp[101][2501];
void calc()
{
	dp[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		for(int j=0;j<=2500;j++)
		{
			for(int k=0;k<26;k++)
			{
				if(j>=k)
				{
					dp[i][j]+=dp[i-1][j-k];
				}
			}
			dp[i][j]%=mod;
		}
	}
}
int main()
{
	calc();
	int data;
	scanf("%d",&data);
	for(int p=0;p<data;p++)
	{
		string str;
		cin>>str;
		ll sum=0;
		for(int i=0;i<str.size();i++)
		{
			sum+=str[i]-'a';
		}
		printf("%I64d\n",(dp[str.size()][sum]+mod-1)%mod);
	}
}