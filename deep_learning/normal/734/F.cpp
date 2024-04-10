#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
ll a[200005], b[200005], c[200005]; 
int main()
{
	// freopen("734F.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%lld", b + i); 
	for (int i = 0; i < n; i++)
		scanf("%lld", c + i); 
	ll sum = 0; 
	for (int i = 0; i < n; i++)
		sum += b[i] + c[i]; 
	if (sum % (2 * n))
	{
		puts("-1"); 
		return 0; 
	}
	sum /= 2 * n; 
	for (int i = 0; i < n; i++)
	{
		if ((b[i] + c[i] - sum) % n)
		{
			puts("-1"); 
			return 0; 
		}
		a[i] = (b[i] + c[i] - sum) / n;
	}
	for (int i = 63; i >= 0; i--)
	{
		ll x = 0; 
		for (int j = 0; j < n; j++)
			x += a[j] & (1ll << i); 
		for (int j = 0; j < n; j++)
		{
			if (a[j] & (1ll << i))
			{
				b[j] -= x; 
				c[j] -= (ll)n << i; 
			}
			else
				c[j] -= x; 
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] || c[i])
		{
			puts("-1"); 
			return 0; 
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld%c", a[i], " \n"[i + 1 == n]);
	return 0; 
}