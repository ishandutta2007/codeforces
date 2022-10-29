#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[101][1001];
vector<int>dat[101];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		dat[gen - za].push_back(zb);
	}
	for (int i = 0; i <= gen; i++)
	{
		sort(dat[i].begin(), dat[i].end());
		reverse(dat[i].begin(), dat[i].end());
	}
	for (int i = 0; i <= gen; i++)for (int j = 0; j <= num; j++)dp[i][j] = -1000000000;
	dp[0][1] = 0;
	for (int i = 0; i < gen; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			int s = 0;
			for (int k = 0; k <= dat[i].size(); k++)
			{
				if (j >= k)dp[i + 1][min(num, j + j - k - k)] = max(dp[i + 1][min(num, j + j - k - k)], dp[i][j] + s);
				if (k != dat[i].size())s += dat[i][k];
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i <= num; i++)maxi = max(maxi, dp[gen][i]);
	printf("%d\n", maxi);
}