#include <iostream>
#include <cstdio>
using namespace std; 
int arr[15][105][105], sum[15][105][105]; 
int main()
{
	// freopen("835C.in", "r", stdin); 
	int n, q, c; 
	scanf("%d%d%d", &n, &q, &c); 
	for (int i = 0; i < n; i++)
	{
		int x, y, s; 
		scanf("%d%d%d", &x, &y, &s); 
		arr[s][x][y]++; 
	}
	for (int s = 0; s <= 10; s++)
	{
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 1; j <= 100; j++)
				sum[s][i][j] = sum[s][i - 1][j] + sum[s][i][j - 1] - sum[s][i - 1][j - 1] + arr[s][i][j]; 
		}
	}
	while (q--)
	{
		int t, l, d, r, u, ans = 0; 
		scanf("%d%d%d%d%d", &t, &l, &u, &r, &d); 
		for (int i = 0; i <= 10; i++)
			ans += (sum[i][r][d] - sum[i][l - 1][d] - sum[i][r][u - 1] + sum[i][l - 1][u - 1]) * ((i + t) % (c + 1)); 
		printf("%d\n", ans);
	}
	return 0; 
}