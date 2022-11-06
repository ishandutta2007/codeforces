#include <iostream>
#include <cstdio>
#define MOD 1000000007
#define inv_2 500000004
#define inv_3 333333336
using namespace std; 
typedef long long ll; 
ll arr[100005]; 
inline ll quick_pow(ll a, ll n)
{
	ll res = 1; 
	while (n)
	{
		if (n & 1)
			res = res * a % MOD; 
		a = a * a % MOD; 
		n >>= 1; 
	}
	return res; 
}
int main()
{
	// freopen("C.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	bool f = true, g = true; 
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", arr + i); 
		f &= arr[i] & 1; 
		g &= arr[i] == 1; 
	}
	if (g)
	{
		printf("0/1\n");
		return 0; 
	}
	ll x = quick_pow(2, arr[0]); 
	for (int i = 1; i < n; i++)
		x = quick_pow(x, arr[i]); 
	if (!f)
		printf("%lld/%lld\n", (x * inv_2 % MOD + 1) * inv_3 % MOD, x * inv_2 % MOD);
	else
		printf("%lld/%lld\n", (x * inv_2 % MOD - 1 + MOD) % MOD * inv_3 % MOD, x * inv_2 % MOD);
	return 0; 
}