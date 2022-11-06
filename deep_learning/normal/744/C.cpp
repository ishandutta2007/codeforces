#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int dp[70005][305], r[25], b[25]; 
char c[25]; 
int main()
{
	// freopen("C.in", "r", stdin);
	int n, tot_r = 0, tot_b = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("\n%c%d%d", c + i, r + i, b + i); 
		tot_r += r[i]; 
		tot_b += b[i]; 
	}
	memset(dp, -1, sizeof(dp)); 
	dp[0][0] = 0; 
	for (int i = 0; i < 1 << n; i++)
	{
		int cnt_r = 0, cnt_b = 0; 
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				(c[j] == 'R' ? cnt_r : cnt_b)++; 
		}
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				continue; 
			for (int k = 0; k < 305; k++)
			{
				if (dp[i][k] == -1)
					continue; 
				dp[i | (1 << j)][k + min(cnt_r, r[j])] = max(dp[i | (1 << j)][k + min(cnt_r, r[j])]
					, dp[i][k] + min(cnt_b, b[j])); 
			}
		}
	}
	int ans = 1e9; 
	for (int i = 0; i < 305; i++)
	{
		if (dp[(1 << n) - 1][i] != -1)
			ans = min(ans, max(tot_r - i, tot_b - dp[(1 << n) - 1][i])); 
	}
	printf("%d\n", ans + n);
	return 0;
}