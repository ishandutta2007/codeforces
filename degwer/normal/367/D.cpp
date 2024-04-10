#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[100000];
int dp[1048576][21];
int main()
{
	int num, cl, dif;
	scanf("%d%d%d", &num, &cl, &dif);
	for (int i = 0; i < cl; i++)
	{
		int zn;
		scanf("%d", &zn);
		for (int j = 0; j < zn; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			d[z] = i;
		}
	}
	int now[20];
	fill(now, now + 20, 0);
	for (int i = 0; i < dif; i++)now[d[i]]++;
	for (int i = dif; i <= num; i++)
	{
		int r = 0;
		for (int j = 0; j < cl; j++)if (now[j] == 0)r += 1 << j;
		dp[r][0] = 1;
		if (i < num)now[d[i - dif]]--, now[d[i]]++;
	}
	for (int i = 0; i < cl; i++)
	{
		for (int j = 0; j < (1 << cl); j++)
		{
			if (dp[j][i])
			{
				dp[j][i + 1] = 1;
				if (j&(1 << i))dp[j - (1 << i)][i + 1] = 1;
			}
		}
	}
	int mini = 1000;
	for (int i = 0; i < (1 << cl); i++)
	{
		if (dp[i][cl])continue;
		int cnt = 0;
		for (int j = 0; j < cl; j++)if (i&(1 << j))cnt++;
		mini = min(mini, cnt);
	}
	printf("%d\n", mini);
}