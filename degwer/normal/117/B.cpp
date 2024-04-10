#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
ll mod=1000000000LL;
int main()
{
	ll a,b,m;
	scanf("%I64d%I64d%I64d",&a,&b,&m);
	for(ll i=1;i<=min(m,a);i++)
	{
		ll now=(i*mod)%m;
		if(!(now==0||(i*mod)/m!=(i*mod+b)/m))
		{
			printf("1 %09I64d\n",i);
			return 0;
		}
	}
	printf("2\n");
}