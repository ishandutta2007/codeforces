#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[1002][1002][12][2];
int main()
{
	int na, nb, gen;
	scanf("%d%d%d", &na, &nb, &gen);
	string sa, sb;
	cin >> sa >> sb;
	sa.push_back('&');
	sb.push_back('$');
	int maxi = 0;
	for (int i = 0; i <= na; i++)
	{
		for (int j = 0; j <= nb; j++)
		{
			if (sa[i] == sb[j])
			{
				for (int k = 0; k <= gen + 1; k++)
				{
					dp[i + 1][j + 1][k][1] = max(dp[i + 1][j + 1][k][1], dp[i][j][k][1] + 1);
					dp[i + 1][j + 1][k][1] = max(dp[i + 1][j + 1][k][1], dp[i][j][k][0] + 1);
				}
			}
			for (int k = 0; k <= gen + 1; k++)
			{
				dp[i + 1][j][k][0] = max(dp[i + 1][j][k][0], dp[i][j][k][0]);
				dp[i][j + 1][k][0] = max(dp[i][j + 1][k][0], dp[i][j][k][0]);
			}
			for (int k = 0; k <= gen; k++)
			{
				dp[i + 1][j][k + 1][0] = max(dp[i + 1][j][k + 1][0], dp[i][j][k][1]);
				dp[i][j + 1][k + 1][0] = max(dp[i][j + 1][k + 1][0], dp[i][j][k][1]);
			}
			for (int k = 0; k < gen; k++)maxi = max(maxi, dp[i][j][k][1]);
		}
	}
	printf("%d\n", maxi);
}