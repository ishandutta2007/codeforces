#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	scanf("%I64d", &n);
	ll ret = 1;
	for (ll i = 2;; i++)
	{
		if (i*i > n)break;
		if (n%i == 0)
		{
			ret *= i;
			for (;;)
			{
				n /= i;
				if (n%i != 0)break;
			}
		}
	}
	printf("%I64d\n", ret * n);
}