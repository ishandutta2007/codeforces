#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b;
	scanf("%I64d%I64d",&a,&b);
	ll ans=0;
	for(;;)
	{
		if(a>=b)
		{
			if(b==1)
			{
				printf("%I64d\n",ans+a);
				break;
			}
			ans+=a/b;
			a%=b;
			if(a==1)
			{
				printf("%I64d\n",ans+b);
				break;
			}
		}
		else
		{
			swap(a,b);
		}
	}
}