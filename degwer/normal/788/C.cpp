#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
typedef bitset<2048>bi;
int main()
{
	int mok, num;
	scanf("%d%d", &mok, &num);
	bi now;
	int mini = 1000000000, maxi = -1;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		now[z] = 1;
		mini = min(mini, z), maxi = max(maxi, z);
	}
	if (mok < mini || maxi < mok)
	{
		printf("-1\n");
		return 0;
	}
	bi dp;
	dp[0] = 1;
	for (int t = 1;; t++)
	{
		bi z;
		for (int i = 0; i < 2048; i++)
		{
			if (dp[i])
			{
				z |= (now << i) >> mok;
			}
		}
		dp = z;
		if (dp[0])
		{
			printf("%d\n", t);
			break;
		}
	}
}