#include<stdio.h>
typedef long long ll;
int main()
{
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	ll ans = 0;
	for (int i = 1; i <= a; i++)
	{
		ans += (b + i % 5) / 5;
	}
	printf("%I64d\n", ans);
}