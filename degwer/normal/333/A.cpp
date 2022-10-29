#include<stdio.h>
typedef long long ll;
int main()
{
	ll n;
	scanf("%I64d", &n);
	for (;;)
	{
		if (n % 3 != 0)break;
		n /= 3;
	}
	printf("%I64d\n", (n + 2) / 3);
}