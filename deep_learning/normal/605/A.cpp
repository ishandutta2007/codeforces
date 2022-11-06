#include <iostream>
#include <cstdio>
using namespace std; 
int arr[1024000], dp[1024000]; 
int main()
{
	// freopen("605A.in", "r", stdin); 
	int n, ans = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = n - 1; i >= 0; i--)
	{
		dp[arr[i]] = dp[arr[i] + 1] + 1; 
		ans = max(ans, dp[arr[i]]); 
	}
	printf("%d\n", n - ans);
	return 0; 
}