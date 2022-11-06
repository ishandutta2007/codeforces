#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int dp[5005][5005], ans[5005], res[5005][5005]; 
char str[5005]; 
int calc(int l, int r)
{
	if (res[l][r] != -1)
		return res[l][r]; 
	if (!dp[l][r])
		return res[l][r] = 0; 
	if (l == r)
		return res[l][r] = 1; 
	if (l + 1 == r)
		return res[l][r] = 2; 
	return res[l][r] = calc(l, l + (r - l + 1 >> 1) - 1) + 1; 
}
int main()
{
	// freopen("835D.in", "r", stdin); 
	memset(res, -1, sizeof(res)); 
	scanf("%s", str); 
	int n = strlen(str); 
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1; 
		dp[i][i + 1] = str[i] == str[i + 1]; 
	}
	for (int l = 2; l < n; l++)
	{
		for (int i = 0; l + i < n; i++)
		{
			int j = l + i; 
			if (dp[i + 1][j - 1] && str[i] == str[j])
				dp[i][j] = 1; 
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		printf("%d", dp[i][j]);
	// 	printf("\n");
	// }
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			ans[calc(i, j)]++; 
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		printf("%d%c", res[i][j], " \n"[j + 1 == n]);
	// }
	for (int i = n; i >= 2; i--)
		ans[i - 1] += ans[i]; 
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0; 
}