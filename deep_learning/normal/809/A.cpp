#include <algorithm>
#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std;
typedef long long ll;  
int arr[300005]; 
ll p[300005]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	const int inv = MOD + 1 >> 1; 
	p[0] = 1; 
	for (int i = 1; i < 300005; i++)
		p[i] = p[i - 1] * 2 % MOD; 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	sort(arr, arr + n); 
	ll sum = 0; 
	for (int i = 1; i < n; i++)
		sum = (sum + p[i - 1] * arr[i] % MOD) % MOD; 
	ll ans = (sum - arr[0] * (p[n - 1] - 1 + MOD) % MOD + MOD) % MOD; 
	for (int i = 1; i < n; i++)
	{
		sum = ((sum - arr[i] + MOD) % MOD * inv) % MOD; 
		ans = ((ans + sum - arr[i] * (p[n - i - 1] - 1 + MOD) % MOD) % MOD + MOD) % MOD; 
	}
	printf("%d\n", ans);
	return 0; 
}