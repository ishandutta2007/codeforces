#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
int main()
{
	ll num,gen;
	scanf("%I64d%I64d",&num,&gen);
	ll ans=1;
	for(int i=0;i<num-gen;i++)
	{
		ans*=(num-gen);
		ans%=mod;
	}
	for(int i=0;i<gen-1;i++)
	{
		ans*=gen;
		ans%=mod;
	}
	printf("%I64d\n",ans);
}