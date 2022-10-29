#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000009;
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b & 1)z = z*a%mod;
	return z;
}
ll inv(ll a)
{
	return po(a, mod - 2);
}
int main()
{
	ll num, gen, kai;
	scanf("%I64d%I64d%I64d", &num, &gen, &kai);
	if (num <= kai*(num - gen + 1) - 1)
	{
		printf("%I64d\n", gen);
		return 0;
	}
	else
	{
		ll s = kai*(num - gen);
		ll ans = (kai - 1)*(num - gen);
		ll t = num - s;
		ans += t%kai + kai*(po(2LL, t / kai + 1) + mod - 2);
		printf("%I64d\n", ans%mod);
	}
}