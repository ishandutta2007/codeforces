#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double dp[18][262144];
double dat[18][18];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)scanf("%lf", &dat[i][j]);
	dp[0][(1 << num) - 1] = 1;
	for (int p = (1 << num) - 2; p >= 0; p--)
	{
		for (int i = 0; i < num; i++)
		{
			if ((p&(1 << i)) == 0)continue;
			double maxi = 0.0;
			for (int j = 0; j < num; j++)
			{
				if (p&(1 << j))continue;
				maxi = max(maxi, dp[i][p | (1 << j)] * dat[i][j] + dp[j][p | (1 << j)] * dat[j][i]);
			}
			dp[i][p] = maxi;
		}
	}
	double maxi = 0;
	for (int i = 0; i < num; i++)maxi = max(maxi, dp[i][1 << i]);
	printf("%.10lf\n", maxi);
}