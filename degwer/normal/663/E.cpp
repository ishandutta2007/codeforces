#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[100000];
int dp[2][21][1048576];
int main()
{
	int len, num;
	scanf("%d%d", &len, &num);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < num; j++)
		{
			char z;
			scanf(" %c", &z);
			dat[j] += (1 << i)*(z - '0');
		}
	}
	for (int i = 0; i < num; i++)
	{
		dp[0][0][dat[i]]++;
	}
	int cur = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= len; j++)
		{
			for (int k = 0; k < (1 << len); k++)
			{
				dp[1 - cur][j][k] += dp[cur][j][k];
			}
		}
		for (int j = 1; j <= len; j++)
		{
			for (int k = 0; k < (1 << len); k++)
			{
				dp[1 - cur][j][k] += dp[cur][j - 1][k ^ (1 << i)];
			}
		}
		for (int j = 0; j <= len; j++)
		{
			for (int k = 0; k < (1 << len); k++)
			{
				dp[cur][j][k] = 0;
			}
		}
		cur = 1 - cur;
	}
	int mini = 1000000000;
	for (int i = 0; i < (1 << len); i++)
	{
		int cnt = 0;
		for (int j = 0; j <= len; j++)
		{
			cnt += (min(j, len - j)*dp[cur][j][i]);
		}
		mini = min(mini, cnt);
	}
	printf("%d\n", mini);
}