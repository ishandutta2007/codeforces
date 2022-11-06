#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int arr[4005][4005];
ll sum[4005][4005], dp[4005][805]; 
void calc(int l, int r, int mn, int mx, int j)
{
	if (l > r)
		return; 
	int m = l + r >> 1, pos = 0; 
	for (int i = mn; i <= mx && i < m; i++)
	{
		if (dp[i][j - 1] + sum[i + 1][m] < dp[m][j])
		{
			dp[m][j] = dp[i][j - 1] + sum[i + 1][m];
			pos = i; 
		}
	}
	calc(l, m - 1, mn, pos, j); 
	calc(m + 1, r, pos, mx, j); 
}
int main()
{
	// freopen("321E.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			getchar(); 
			arr[i][j] = getchar() - '0' + arr[i][j - 1]; 
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
			sum[i][j] = sum[i][j - 1] + arr[j][j] - arr[j][i - 1]; 
	}
	memset(dp, 0x3f, sizeof(dp)); 
	dp[0][0] = 0; 
	for (int j = 1; j <= k; j++)
		calc(1, n, 0, n, j); 
	printf("%lld\n", dp[n][k]);
	return 0; 
}