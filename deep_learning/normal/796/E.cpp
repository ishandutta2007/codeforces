#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
inline void upd(int &x, int y)
{
	if (x < y)
		x = y; 
}
int dp[2][1005][55][55], a[1005], b[1005]; 
int main()
{
	// freopen("796E.in", "r", stdin); 
	int n, p, k; 
	scanf("%d%d%d", &n, &p, &k); 
	if (p > 2 * (n + k - 1) / k)
		p = 2 * (n + k - 1) / k; 
	int r, s; 
	scanf("%d", &r); 
	for (int i = 0; i < r; i++)
	{
		int x; 
		scanf("%d", &x); 
		a[x] = 1; 
	}
	scanf("%d", &s); 
	for (int i = 0; i < s; i++)
	{
		int x; 
		scanf("%d", &x); 
		b[x] = 1; 
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0][0][0] = 0; 
	for (int i = 0; i < n; i++)
	{
		memset(dp[i & 1 ^ 1], -0x3f, sizeof(dp[i & 1 ^ 1])); 
		for (int j = 0; j <= p; j++)
		{
			for (int x = 0; x <= k; x++)
			{
				for (int y = 0; y <= k; y++)
				{
					upd(dp[i & 1 ^ 1][j][max(x - 1, 0)][max(y - 1, 0)]
						, dp[i & 1][j][x][y] + max((x ? a[i + 1] : 0), (y ? b[i + 1] : 0))); 
					upd(dp[i & 1 ^ 1][j + 1][k - 1][max(y - 1, 0)], dp[i & 1][j][x][y] + max(a[i + 1], (y ? b[i + 1] : 0))); 
					upd(dp[i & 1 ^ 1][j + 1][max(x - 1, 0)][k - 1], dp[i & 1][j][x][y] + max((x ? a[i + 1] : 0), b[i + 1])); 
				}
			}
		}
	}
	int ans = 0; 
	for (int i = 0; i <= p; i++)
	{
		for (int x = 0; x <= k; x++)
		{
			for (int y = 0; y <= k; y++)
				upd(ans, dp[n & 1][i][x][y]); 
		}
	}
	printf("%d\n", ans);
	return 0; 
}