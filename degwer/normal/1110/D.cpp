#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[1010101];
int dp[1010101][3][3];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		d[z]++;
	}
	for (int i = 1; i <= gen + 10; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int k = 0; k <= 2; k++)
			{
				for (int l = 0; l <= 2; l++)
				{
					if (j + k + l <= d[i])dp[i + 1][k][l] = max(dp[i + 1][k][l], dp[i][j][k] + l + (d[i] - j - k - l) / 3);
				}
			}
		}
	}
	printf("%d\n", dp[gen + 10][0][0]);
}