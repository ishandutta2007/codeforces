#include <algorithm>
#include <cstdio>
#include <cmath>
#define MOD 1000000007
typedef long long ll; 
inline int quick_pow(int a, int n)
{
	int res = 1; 
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD; 
		a = (ll)a * a % MOD; 
		n >>= 1; 
	}
	return res; 
}
int arr[1000005], fact[1000005], inv[1000005]; 
int main()
{
	// freopen("938E.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	fact[0] = inv[0] = 1; 
	for (int i = 1; i < 1000005; i++)
	{
		fact[i] = (ll)fact[i - 1] * i % MOD; 
		inv[i] = quick_pow(fact[i], MOD - 2); 
	}
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	std::sort(arr, arr + n); 
	ll ans = 0; 
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[n - 1])
			break; 
		int pos = std::lower_bound(arr, arr + n, arr[i]) - arr, cnt = n - pos; 
		ans = (ans + (ll)arr[i] * fact[cnt - 1] % MOD * inv[cnt]) % MOD; 
	}
	printf("%lld\n", ans * fact[n] % MOD);
	return 0; 
}