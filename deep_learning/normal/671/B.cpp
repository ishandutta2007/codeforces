#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int arr[500005]; 
int main()
{
	// freopen("B.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	ll l = 0, r = 2e9, ans; 
	while (l <= r)
	{
		ll m = l + r >> 1, tot = 0; 
		for (int i = 0; i < n; i++)
			tot += max(0ll, m - arr[i]); 
		if (tot <= k)
		{
			ans = m; 
			l = m + 1; 
		}
		else
			r = m - 1; 
	}
	int tot = k; 
	for (int i = 0; i < n; i++)
	{
		tot -= max(0ll, ans - arr[i]); 
		arr[i] += max(0ll, ans - arr[i]); 
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == ans && tot)
		{
			tot--; 
			arr[i]++; 
		}
	}
	l = 0;
	r = 2e9;
	while (l <= r)
	{
		ll m = l + r >> 1, tot = 0; 
		for (int i = 0; i < n; i++)
			tot += max(0ll, arr[i] - m); 
		if (tot <= k)
		{
			ans = m; 
			r = m - 1; 
		}
		else
			l = m + 1; 
	}
	tot = k; 
	for (int i = 0; i < n; i++)
	{
		tot -= max(0ll, arr[i] - ans); 
		arr[i] -= max(0ll, arr[i] - ans); 
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == ans && tot)
		{
			tot--; 
			arr[i]--; 
		}
	}
	int mn = 1e9, mx = -1e9; 
	for (int i = 0; i < n; i++)
	{
		mn = min(mn, arr[i]); 
		mx = max(mx, arr[i]); 
	}
	printf("%d\n", mx - mn);
	return 0; 
}