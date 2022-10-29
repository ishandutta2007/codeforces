#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b, mok;
	scanf("%I64d%I64d%I64d", &a, &b, &mok);
	if (a > b)swap(a, b);
	if (b >= mok)printf("0\n");
	else if (b <= 0)printf("-1\n");
	else
	{
		ll c = 0;
		if (a < 0)
		{
			ll t = (-a) / b;
			c += t;
			a += t*b;
		}
		for (;;)
		{
			if (a > b)swap(a, b);
			if (b >= mok)
			{
				printf("%I64d\n", c);
				return 0;
			}
			a += b;
			c++;
		}
	}
}