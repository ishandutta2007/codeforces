#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool ispr(ll a)
{
	for (ll i = 2;; i++)
	{
		if (i*i > a)return true;
		if (a%i == 0)return false;
	}
}
ll gcd(ll a, ll b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int main()
{
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		ll a;
		scanf("%I64d", &a);
		if (a == 2)
		{
			printf("1/6\n");
			continue;
		}
		ll lb, ub;
		for (ll t = a;; t--)
		{
			if (ispr(t))
			{
				lb = t;
				break;
			}
		}
		for (ll t = a + 1;; t++)
		{
			if (ispr(t))
			{
				ub = t;
				break;
			}
		}
		ll x = 2 * lb*ub;
		ll y = lb*ub + 2LL * (a - lb + 1 - ub);
		ll g = gcd(x, y);
		printf("%I64d/%I64d\n", y / g, x / g);
	}
}