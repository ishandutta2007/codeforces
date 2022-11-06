#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int main()
{
	// freopen("785C.in", "r", stdin); 
	ll n, m; 
	scanf("%lld%lld", &n, &m); 
	if (m >= n)
	{
		printf("%lld\n", n);
		return 0; 
	}
	ll l = 0, r = 1e10, ans; 
	while (l <= r)
	{
		ll mid = l + r >> 1; 
		ll sum = mid * (mid + 1) / 2; 
		if (sum + m >= n)
		{
			ans = mid; 
			r = mid - 1; 
		}
		else
			l = mid + 1; 
	}
	printf("%lld\n", ans + m);
	return 0; 
}