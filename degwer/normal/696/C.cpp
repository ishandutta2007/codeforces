#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b % 2 == 1)z = z*a%mod;
	return z;
}
ll inv(ll a)
{
	return po(a, mod - 2);
}
int main()
{
	int num;
	scanf("%d", &num);
	ll t = 1;
	bool x = false;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%I64d", &z);
		t *= z % (mod - 1);
		t %= mod - 1;
		if (z % 2 == 0)x = true;
	}
	if (x)
	{
		printf("%I64d/%I64d\n", (po(2, t + mod - 1 - 1) + 1)*((mod + 1) / 3) % mod, po(2, t + mod - 1 - 1));
	}
	else
	{
		printf("%I64d/%I64d\n", (po(2, t + mod - 1 - 1) + mod - 1)*((mod + 1) / 3) % mod, po(2, t + mod - 1 - 1));
	}
}