#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	for (;;)
	{
		if (a > b)swap(a, b);
		b %= a;
		if (b == 0)return a;
	}
}
int main()
{
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	if (gcd(a, b) != 1)
	{
		printf("Impossible\n");
		return 0;
	}
	for (;;)
	{
		if (a == b)
		{
			break;
		}
		if (a > b)
		{
			printf("%I64d", (a - 1) / b);
			a -= (a - 1) / b*b;
			printf("A");
		}
		else
		{
			printf("%I64d", (b - 1) / a);
			b -= (b - 1) / a*a;
			printf("B");
		}
	}
	printf("\n");
}