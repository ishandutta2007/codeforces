#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[201][201][201];
int main()
{
	int num, atl, beg;
	scanf("%d%d%d", &num, &atl, &beg);
	vector<double>vec;
	for (int i = 0; i < num; i++)
	{
		double z;
		scanf("%lf", &z);
		vec.push_back(z / 100.0);
	}
	vector<int>dat;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat.push_back(z);
	}
	dp[0][0][beg] = 1;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k <= 200; k++)
			{
				if (dp[i][j][k] < 1e-100)dp[i][j][k] = 0;
				if (dat[i] == -1)
				{
					dp[i + 1][j + 1][k] += dp[i][j][k] * vec[i];
					dp[i + 1][j][k] += dp[i][j][k] * (1.0 - vec[i]);
				}
				else
				{
					dp[i + 1][j + 1][min(200, k + dat[i] + 1)] += dp[i][j][k] * vec[i];
					dp[i + 1][j][k] += dp[i][j][k] * (1.0 - vec[i]);
				}
			}
		}
	}
	double ans = 0;
	for (int i = atl; i <= num; i++)for (int j = i; j <= 200; j++)ans += dp[num][i][j];
	printf("%.10lf\n", ans);
}