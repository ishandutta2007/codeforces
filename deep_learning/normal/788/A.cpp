#include <iostream>
#include <cstdio>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
ll arr[100005]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i); 
	for (int i = 0; i < n - 1; i++)
		arr[i] = my_abs(arr[i] - arr[i + 1]); 
	ll cur = 0, ans = -1e18; 
	for (int i = 0; i < n - 1; i += 2)
	{
		cur += arr[i]; 
		ans = max(ans, cur); 
		cur -= arr[i + 1]; 
		if (cur < 0)
			cur = 0; 
	}
	cur = 0; 
	for (int i = 1; i < n - 1; i += 2)
	{
		cur += arr[i]; 
		ans = max(ans, cur); 
		cur -= arr[i + 1]; 
		if (cur < 0)
			cur = 0; 
	}
	printf("%lld\n", ans);
	return 0; 
}