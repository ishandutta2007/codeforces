#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll fact[200005], inv[200005]; 
int arr[200005]; 
inline ll quick_pow(ll a, int n)
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
inline ll C(int n, int m)
{
	return fact[n] * inv[m] % MOD * inv[n - m] % MOD; 
}
int main()
{
	// freopen("B.in", "r", stdin); 
	fact[0] = inv[0] = 1; 
	for (int i = 1; i < 200005; i++)
	{
		fact[i] = fact[i - 1] * i % MOD; 
		inv[i] = quick_pow(fact[i], MOD - 2); 
	}
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	if (n == 1)
	{
		printf("%d\n", arr[0]);
		return 0; 
	}
	if (n & 1)
	{
		int cur = 0; 
		for (int i = 1; i < n; i++, cur ^= 1)
			arr[i - 1] = ((cur ? arr[i - 1] - arr[i] : arr[i - 1] + arr[i]) % MOD + MOD) % MOD; 
		n--; 
	}
	ll x = 0, y = 0; 
	for (int i = 0; i < n; i += 2)
		(x += C((n >> 1) - 1, i >> 1) * arr[i] % MOD) %= MOD; 
	for (int i = 1; i < n; i += 2)
		(y += C((n >> 1) - 1, i >> 1) * arr[i] % MOD) %= MOD; 
	printf("%d\n", ((((n >> 1) & 1) ? x + y : x - y) % MOD + MOD) % MOD);
	return 0; 
}