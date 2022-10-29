#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	ll mini=10000000000000000LL;
	for(int p=0;p<3;p++)
	{
		if((a+b)%2!=0)
		{
			ll t=a;
			a=b;
			b=c;
			c=t;
			continue;
		}
		ll k=(a+b)/2;
		mini=min(mini,k+abs(a-k));
		ll t=a;
		a=b;
		b=c;
		c=t;
	}
	printf("%I64d\n",mini);
}