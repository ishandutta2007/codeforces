#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll jou[101];
int main()
{
	string str;
	cin>>str;
	jou[0]=1;
	for(int i=1;i<=100;i++)
	{
		jou[i]=(jou[i-1]*2)%mod;
	}
	reverse(str.begin(),str.end());
	ll ans=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1')
		{
			ans+=jou[i]*jou[str.size()];
			ans%=mod;
		}
	}
	printf("%I64d\n",(ans*((mod+1)/2))%mod);
}