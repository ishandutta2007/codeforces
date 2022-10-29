#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll solve(ll a)
{
	if(a<=9)
	{
		return a;
	}
	ll ret=9;
	ll now=10;
	for(;;)
	{
		int han=0;
		for(int i=1;i<=9;i++)
		{
			if(now*(i+1)<=a)
			{
				ret+=now/10;
			}
			else
			{
				if(i<=a%10)
				{
					ret+=(a-now*i)/10+1;
				}
				else
				{
					ret+=(a-now*i)/10;
				}
				han=1;
				break;
			}
		}
		if(han==1)
		{
			break;
		}
		now*=10;
	}
	return ret;
}
int main()
{
	ll a,b;
	scanf("%I64d%I64d",&a,&b);
	printf("%I64d\n",solve(b)-solve(a-1));
}