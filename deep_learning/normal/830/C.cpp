#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int arr[105], part[10000005], tot; 
inline int calc(int x, int y)
{
	return (x + y - 1) / y; 
}
int main()
{
	// freopen("C.in", "r", stdin); 
	int n; 
	ll k; 
	scanf("%d%lld", &n, &k); 
	ll sum = k; 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		for (int j = 1; j * j <= arr[i]; j++)
		{
			part[tot++] = j; 
			part[tot++] = calc(arr[i], j); 
		}
		sum += arr[i]; 
	}
	sort(part, part + tot); 
	tot = unique(part, part + tot) - part; 
	ll ans = 0; 
	for (int i = 0; i < tot; i++)
	{
		ll cur = 0; 
		for (int j = 0; j < n; j++)
			cur += calc(arr[j], part[i]); 
		if (part[i] * cur <= sum)
			ans = max(ans, sum / cur); 
	}
	printf("%lld\n", ans);
	return 0; 
}