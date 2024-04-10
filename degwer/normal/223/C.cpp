#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
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
int main()
{
	int num,kai;
	scanf("%d%d",&num,&kai);
	kai--;
	vector<ll>vec;
	for(int i=0;i<num;i++)
	{
		ll zan;
		scanf("%I64d",&zan);
		vec.push_back(zan);
	}
	vector<ll>tims;
	tims.push_back(1);
	ll now=1;
	for(int i=1;i<num;i++)
	{
		now*=(kai+i);
		now%=mod;
		now*=inv(i);
		now%=mod;
		tims.push_back(now);
	}
	vector<ll>ret;
	for(int i=0;i<num;i++)
	{
		ll sum=0;
		for(int j=i;j>=0;j--)
		{
			sum+=(tims[j]*vec[i-j])%mod;
			sum%=mod;
		}
		if(i!=0)
		{
			printf(" ");
		}
		printf("%I64d",sum);
	}
	printf("\n");
}