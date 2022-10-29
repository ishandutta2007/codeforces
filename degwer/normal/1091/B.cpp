#include<stdio.h>
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	ll a = 0, b = 0;
	for (int i = 0; i < n + n; i++)
	{
		ll za, zb;
		scanf("%I64d%I64d", &za, &zb);
		a += za, b += zb;
	}
	printf("%I64d %I64d\n", a / n, b / n);
}