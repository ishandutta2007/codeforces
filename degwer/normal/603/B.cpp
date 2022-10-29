#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	ll p, k;
	scanf("%I64d%I64d", &p, &k);
	if (k == 0)
	{
		ll r = 1;
		for (int i = 0; i < p - 1; i++)r = (r*p) % mod;
		printf("%I64d\n", r);
	}
	else if (k == 1)
	{
		ll r = 1;
		for (int i = 0; i < p; i++)r = (r*p) % mod;
		printf("%I64d\n", r);
	}
	else
	{
		ll n = 1;
		ll e = -1;
		for (int i = 0;; i++)
		{
			n = (n*k) % p;
			if (n == 1)
			{
				e = i + 1;
				break;
			}
		}
		ll r = 1;
		for (int i = 0; i < (p - 1) / e; i++)r = (r*p) % mod;
		printf("%I64d\n", r);
	}
}