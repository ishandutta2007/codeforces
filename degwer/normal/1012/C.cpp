#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[5050];
int dp[5050][3030][3];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 2; i < num + 2; i++)scanf("%d", &dat[i]);
	for (int i = 0; i <= num + 10; i++)for (int j = 0; j <= num / 2 + 10; j++)for (int k = 0; k < 3; k++)dp[i][j][k] = 1000000000;
	dp[2][0][2] = 0;
	for (int i = 2; i < num + 2; i++)
	{
		for (int j = 0; j <= i / 2; j++)
		{
			if (dat[i - 1] <= dat[i])dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][0] + (dat[i] - dat[i - 1] + 1));
			else dp[i + 1][j][2] = min(dp[i + 1][j][2], dp[i][j][0]);
			dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], dp[i][j][1] + max(0, dat[i - 2] - dat[i]));
			dp[i + 1][j][2] = min(dp[i + 1][j][2], dp[i][j][1]);
			dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], dp[i][j][2] + max(0, dat[i - 1] - dat[i] + 1));
			dp[i + 1][j][2] = min(dp[i + 1][j][2], dp[i][j][2]);
		}
	}
	for (int i = 1; i <= (num + 1) / 2; i++)printf("%d ", min(min(dp[num + 2][i][0], dp[num + 2][i][1]), dp[num + 2][i][2]));
	printf("\n");
}