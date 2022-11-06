#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int arr[100005]; 
ll x[100005]; 
int main()
{
	// freopen("812C.in", "r", stdin); 
	int n, s; 
	scanf("%d%d", &n, &s); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	int l = 0, r = n, ans; 
	ll mn; 
	while (l <= r)
	{
		int m = l + r >> 1; 
		for (int i = 0; i < n; i++)
			x[i] = arr[i] + (ll)(i + 1) * m; 
		sort(x, x + n); 
		ll tot = 0; 
		for (int i = 0; i < m; i++)
			tot += x[i]; 
		if (tot <= s)
		{
			ans = m; 
			mn = tot; 
			l = m + 1; 
		}
		else
			r = m - 1; 
	}
	printf("%d %lld\n", ans, mn);
	return 0; 
}