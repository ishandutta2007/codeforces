#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[100001][301];
int a[100000], b[100000];
vector<int>v[200000];
int pt[200000];
int main()
{
	int na, nb, gen, en;
	scanf("%d%d%d%d", &na, &nb, &gen, &en);
	for (int i = 0; i < na; i++)scanf("%d", &a[i]);
	for (int i = 0; i < nb; i++)scanf("%d", &b[i]);
	for (int i = 0; i < nb; i++)v[b[i]].push_back(i);
	for (int i = 0; i <= na; i++)for (int j = 0; j <= 300; j++)dp[i][j] = 1000000000;
	for (int i = 0; i <= na; i++)dp[i][0] = -1;
	for (int i = 0; i < gen / en; i++)
	{
		for (int j = 0; j <= 100000; j++)pt[j] = int(v[j].size()) - 1;
		for (int j = 0; j < na; j++)
		{
			dp[j + 1][i + 1] = dp[j][i + 1];
			for (;;)
			{
				if (pt[a[j]] <= 0)break;
				if (dp[j][i] < v[a[j]][pt[a[j]] - 1])pt[a[j]]--;
				else break;
			}
			if (pt[a[j]] >= 0)if (dp[j][i] < v[a[j]][pt[a[j]]])dp[j + 1][i + 1] = min(dp[j + 1][i + 1], v[a[j]][pt[a[j]]]);
			//printf("%d ", dp[i + 1][j + 1]);
		}
		//printf("\n");
	}
	int maxi = 0;
	for (int i = 0; i <= gen / en; i++)for (int j = 1; j <= na; j++)if (j + dp[j][i] + 1 + i*en <= gen)maxi = max(maxi, i);
	printf("%d\n", maxi);
}