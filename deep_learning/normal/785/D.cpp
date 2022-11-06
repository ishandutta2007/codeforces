#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll;
ll fact[200005], inv[200005]; 
char str[200005]; 
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
	// cout << n << " " << m << endl; 
	if (n < m)
		return 0; 
	return fact[n] * inv[m] % MOD * inv[n - m] % MOD; 
}
int main()
{
	// freopen("785D.in", "r", stdin);
	inv[0] = fact[0] = 1; 
	for (int i = 1; i < 200005; i++)
	{
		fact[i] = fact[i - 1] * i % MOD; 
		inv[i] = quick_pow(fact[i], MOD - 2); 
	}
	scanf("%s", str); 
	int n = strlen(str), r = 0, lcnt = 0, rcnt = 0, ans = 0;
	for (int i = 0; i < n; i++)
		r += str[i] == ')'; 
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ')')
		{
			rcnt++; 
			continue; 
		}
		lcnt++; 
		ans = (ans + C(lcnt + r - rcnt - 1, lcnt)) % MOD; 
	}
	printf("%d\n", ans);
	return 0; 
}