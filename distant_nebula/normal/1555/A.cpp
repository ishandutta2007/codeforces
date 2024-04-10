#include <cstdio>
#include <algorithm>
#define ll long long
int T;
ll n;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &n);
		n+=n&1;
		n>>=1;
		if(n<=3) puts("15");
		else printf("%lld\n", n*5);
	}
	return 0;
}