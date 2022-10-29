#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int dp[80][80][80][2];
int rv[80], rk[80], ro[80];
int ptv = 0, ptk = 0, pto = 0;
int nv[80], nk[80], no[80];
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	for (int i = 0; i <= num; i++)for (int j = 0; j <= num; j++)for (int k = 0; k <= num; k++)dp[i][j][k][0] = dp[i][j][k][1] = 1000000000;
	for (int i = 0; i < num; i++)rv[i + 1] = rv[i] + (s[i] == 'V'), rk[i + 1] = rk[i] + (s[i] == 'K'), ro[i + 1] = ro[i] + (s[i] != 'V'&&s[i] != 'K');
	for (int i = 0; i < num; i++)
	{
		if (s[i] == 'V')nv[ptv++] = i;
		else if (s[i] == 'K')nk[ptk++] = i;
		else no[pto++] = i;
	}
	dp[0][0][0][0] = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= ptv; j++)
		{
			for (int k = 0; k <= ptk; k++)
			{
				if (j + k > i)continue;
				if (i - j - k > pto)continue;
				int t = i - j - k;
				if (j != ptv)
				{
					dp[i + 1][j + 1][k][1] = min(dp[i + 1][j + 1][k][1], dp[i][j][k][0] + max(0, k - rk[nv[j]]) + max(0, t - ro[nv[j]]));
					dp[i + 1][j + 1][k][1] = min(dp[i + 1][j + 1][k][1], dp[i][j][k][1] + max(0, k - rk[nv[j]]) + max(0, t - ro[nv[j]]));
				}
				if (k != ptk)
				{
					dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], dp[i][j][k][0] + max(0, j - rv[nk[k]]) + max(0, t - ro[nk[k]]));
				}
				if (t != pto)
				{
					dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][0] + max(0, j - rv[no[t]]) + max(0, k - rk[no[t]]));
					dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][1] + max(0, j - rv[no[t]]) + max(0, k - rk[no[t]]));
				}
			}
		}
	}
	printf("%d\n", min(dp[num][rv[num]][rk[num]][0],dp[num][rv[num]][rk[num]][1]));
}