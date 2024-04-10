#include <algorithm>
#include <iostream>
#include <cstdio>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
ll dp[3005][3005], pre[3005][3005], arr[3005], app[3005]; 
int main()
{
	// freopen("C.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", arr + i); 
		arr[i] -= i; 
		app[i] = arr[i]; 
	}
	sort(app, app + n); 
	int tot = unique(app, app + n) - app; 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < tot; j++)
		{
			dp[i][j] = my_abs(arr[i - 1] - app[j]) + pre[i - 1][j]; 
			pre[i][j] = min(j ? pre[i][j - 1] : (ll)1e18, dp[i][j]); 
		}
	}
	printf("%lld\n", pre[n][tot - 1]);
	return 0; 
}