#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std; 
bitset<505> dp[505][505]; 
int arr[505]; 
int main()
{
	// freopen("C.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	dp[0][0].set(0); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i + 1][j] |= dp[i][j]; 
			if (j + arr[i] <= k)
			{
				dp[i + 1][j + arr[i]] |= dp[i][j]; 
				dp[i + 1][j + arr[i]] |= dp[i][j] << arr[i]; 
			}
		}
	}
	int cnt = 0; 
	for (int i = 0; i <= k; i++)
	{
		if (dp[n][k].test(i))
			cnt++; 
	}
	printf("%d\n", cnt);
	for (int i = 0; i <= k; i++)
	{
		if (dp[n][k].test(i))
			printf("%d%c", i, " \n"[!--cnt]);
	}
	return 0;
}