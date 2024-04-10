#include<stdio.h>
typedef long long ll;
int main()
{
	ll n;
	scanf("%I64d", &n);
	ll f0 = 1, f1 = 1;
	for (int i = 0;; i++)
	{
		if (f1 > n)
		{
			printf("%d\n", i - 1);
			break;
		}
		ll t = f0 + f1;
		f0 = f1;
		f1 = t;
	}
}