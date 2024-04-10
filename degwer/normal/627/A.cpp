#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	ll t = a - b;
	if (t < 0 || t % 2 == 1)
	{
		printf("0\n");
		return 0;
	}
	t >>= 1;
	ll ans = 1;
	for (int i = 0; i <= 50; i++)
	{
		if ((t&(1LL << i)) != 0)
		{
			if ((b&(1LL << i)) != 0)
			{
				printf("0\n");
				return 0;
			}
		}
		else if ((b&(1LL << i)) != 0)
		{
			ans *= 2;
		}
	}
	if (t == 0)ans -= 2;
	printf("%I64d\n", ans);
}