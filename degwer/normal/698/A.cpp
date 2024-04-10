#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[101][3];
int main()
{
	int num;
	scanf("%d", &num);
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (z & 1)
		{
			dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
			dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + 1);
		}
		if (z & 2)
		{
			dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + 1);
			dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + 1);
		}
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][2]);
	}
	for (int i = 0; i < 3; i++)maxi = max(maxi, dp[num][i]);
	printf("%d\n", num - maxi);
}