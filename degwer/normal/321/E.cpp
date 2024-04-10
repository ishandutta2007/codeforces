#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[801][4011];
int rui[4011][4011];
int get(int a, int b)
{
	return rui[b][b] - rui[a - 1][b] - rui[b][a - 1] + rui[a - 1][a - 1];
}
void calc(int beg, int end, int k, int lb, int ub)
{
	if (beg > end)return;
	int med = (beg + end) / 2;
	int mini = 2000000000, rr = -1;
	for (int i = lb; i <= ub; i++)
	{
		if (mini > dp[k][i] + get(i + 1, med))mini = dp[k][i] + get(i + 1, med), rr = i;
	}
	dp[k + 1][med] = dp[k][rr] + get(rr + 1, med);
	calc(beg, med - 1, k, lb, rr);
	calc(med + 1, end, k, rr, ub);
}
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			char c = getchar();
			c = getchar();
			rui[i + 1][j + 1] = rui[i + 1][j] + rui[i][j + 1] - rui[i][j] + c - '0';
		}
	}
	for (int j = 0; j <= gen; j++)for (int i = 0; i <= num + 5; i++)dp[j][i] = 1000000000;
	dp[0][0] = 0;
	for (int i = 0; i < gen; i++)calc(0, num, i, 0, num);
	printf("%d\n", dp[gen][num] /2);
}