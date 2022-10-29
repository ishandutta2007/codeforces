#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod;
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
int main()
{
	ll a;
	scanf("%I64d%I64d",&a,&mod);
	printf("%I64d\n",(po(3,a)+mod-1)%mod);
}