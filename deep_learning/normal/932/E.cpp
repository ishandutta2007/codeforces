#include <cstdio>
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
int arr[5005]; 
int main()
{
	// freopen("932E.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i <= k; i++)
		arr[i] = quick_pow(i, k); 
	int ans = 0, cur = 1; 
	for (int i = 0; i <= k && i <= n; i++)
	{
		ans = (ans + (ll)arr[0] * quick_pow(2, n - i) % MOD * cur) % MOD; 
		cur = (ll)cur * (n - i) % MOD * quick_pow(i + 1, MOD - 2) % MOD; 
		for (int j = 0; j < k - i; j++)
			arr[j] = (arr[j + 1] - arr[j] + MOD) % MOD; 
	}
	printf("%d\n", ans);
	return 0; 
}