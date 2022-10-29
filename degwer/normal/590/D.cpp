#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp1[2][151][20001];
int dp2[2][151][20001];
int main()
{
	int num, dv, gen;
	scanf("%d%d%d", &num, &dv, &gen);
	vector<int>v1, v2;
	int sum = 0;
	for (int i = 0; i < dv; i++)
	{
		int z;
		scanf("%d", &z);
		v1.push_back(z);
		sum += z;
	}
	for (int i = dv; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v2.push_back(z);
	}
	reverse(v1.begin(), v1.end());
	int cur = 0;
	int mk = min(v1.size(), v2.size());
	int mz1 = v1.size()*(v1.size() + 1) / 2;
	int mz2 = v2.size()*(v2.size() + 1) / 2;
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j <= mk; j++)
		{
			for (int k = 0; k <= mz1; k++)
			{
				dp1[1 - cur][j][k] = max(dp1[1 - cur][j][k], dp1[cur][j][k]);
				if (i + k <= mz1&&j < mk)
				{
					dp1[1 - cur][j + 1][k + i] = max(dp1[1 - cur][j + 1][k + i], dp1[cur][j][k] + v1[i]);
				}
			}
		}
		for (int j = 0; j <= mk; j++)for (int k = 0; k <= mz1; k++)dp1[cur][j][k] = 0;
		cur = 1 - cur;
	}
	cur = 0;
	for (int i = 0; i <= mk; i++)for (int j = 0; j <= mz2; j++)dp2[0][i][j] = dp2[1][i][j] = 1000000000;
	dp2[0][0][0] = 0;
	for (int i = 0; i < v2.size(); i++)
	{
		for (int j = 0; j <= mk; j++)
		{
			for (int k = 0; k <= mz2; k++)
			{
				dp2[1 - cur][j][k] = min(dp2[1 - cur][j][k], dp2[cur][j][k]);
				if (i + k <= mz2&&j < mk)
				{
					dp2[1 - cur][j + 1][k + i] = min(dp2[1 - cur][j + 1][k + i], dp2[cur][j][k] + v2[i]);
				}
			}
		}
		for (int j = 0; j <= mk; j++)for (int k = 0; k <= mz2; k++)dp2[cur][j][k] = 1000000000;
		cur = 1 - cur;
	}
	int maxi = 0;
	for (int i = 0; i <= mk; i++)
	{
		vector<int>r1, r2;
		int now = 0;
		for (int j = 0; j <= mz1; j++)
		{
			now = max(now, dp1[v1.size() % 2][i][j]);
			r1.push_back(now);
		}
		now = 1000000000;
		for (int j = 0; j <= mz2; j++)
		{
			now = min(now, dp2[v2.size() % 2][i][j]);
			r2.push_back(now);
		}
		/*printf("::%d\n", i);
		for (int j = 0; j <= mz1; j++)printf("%d ", r1[j]); printf("\n");
		for (int j = 0; j <= mz2; j++)printf("%d ", r2[j]); printf("\n");*/
		for (int j = 0; j <= mz1; j++)
		{
			if (gen - i - j >= 0)
			{
				maxi = max(maxi, r1[j] - r2[min(mz2, gen - i - j)]);
			}
		}
	}
	printf("%d\n", sum - maxi);
}