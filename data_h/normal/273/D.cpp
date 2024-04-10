#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 160;
const long long mod = 1000000007;

int n, m;
long long f[MAXN][MAXN][MAXN][2][2], ans;
long long sum[MAXN][MAXN][2][2];

long long calc(int x1, int x2, int y1, int y2, int c1, int c2)
{
	if (x1 < 0) x1 = 0;
	if (y1 < 0) y1 = 0;
	if (x2 > m) x2 = m;
	if (y2 > m) y2 = m;
	if (x1 > x2 || y1 > y2)
		return 0;
	return (sum[x2][y2][c1][c2] + sum[x1 - 1][y1 - 1][c1][c2] 
			- sum[x2][y1 - 1][c1][c2] - sum[x1 - 1][y2][c1][c2] + 2 * mod) % mod;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		memset(sum, 0, sizeof(sum));
		for(int l = 0; l < 2; l++)
			for(int r = 0; r < 2; r++)
			{
				for(int j = 1; j <= m; j++)
					for(int k = 1; k <= m; k++)
						sum[j][k][l][r] = (sum[j - 1][k][l][r] + sum[j][k - 1][l][r] - 
										  sum[j - 1][k - 1][l][r] + f[i - 1][j][k][l][r] + mod) % mod;
			}
		for(int j = 1; j <= m; j++)
			for(int k = j; k <= m; k++)
			{
				f[i][j][k][0][1] = (1 + calc(j, k, j, k, 0, 1)) % mod;
				
				f[i][j][k][0][0] = (calc(j, k, k, m, 0, 0) + calc(j, k, k + 1, m, 0, 1)) % mod; 
				
				f[i][j][k][1][1] = (calc(1, j, j, k, 1, 1) + calc(1, j - 1, j, k, 0, 1)) % mod;
				
				f[i][j][k][1][0] = (calc(1, j, k, m, 1, 0) + calc(1, j - 1, k + 1, m, 0, 1)
								+	calc(1, j - 1, k, m, 0, 0) + calc(1, j, k + 1, m, 1, 1)) % mod;
				
				for(int l = 0; l < 2; l++)
					for(int r = 0; r < 2; r++)
					{
						ans = (ans + f[i][j][k][l][r]) % mod;
						/*
						if (f[i][j][k][l][r])
						{
							printf("%d %d %d %d %d %d\n", f[i][j][k][l][r], i, j, k, l, r);
						}
						*/
					}
			}
	}
	printf("%I64d\n", ans);
	//printf("%I64d\n", f[2][1][2][0][1]);
	return 0;
}