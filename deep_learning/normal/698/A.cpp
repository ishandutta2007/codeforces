#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int arr[105], dp[105][5]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	memset(dp, 0x3f, sizeof(dp)); 
	dp[0][0] = 0; 
	for (int i = 0; i < n; i++)
	{
		dp[i + 1][0] = min(dp[i + 1][0], min(dp[i][0], min(dp[i][1], dp[i][2])) + 1); 
		if (arr[i] & 1)
			dp[i + 1][1] = min(dp[i + 1][1], min(dp[i][0], dp[i][2])); 
		if (arr[i] & 2)
			dp[i + 1][2] = min(dp[i + 1][2], min(dp[i][0], dp[i][1])); 
	}
	printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
 	return 0; 
}