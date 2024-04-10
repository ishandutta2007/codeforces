#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[1010][1010];
int dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < mx; i++)for (int j = 0; j < my; j++)scanf("%d", &map[i + 1][j + 1]);
	for (int i = 1; i <= mx; i++)for (int j = 1; j <= my; j++)dp1[i][j] = max(dp1[i][j - 1], dp1[i - 1][j]) + map[i][j];
	for (int i = mx; i >= 1; i--)for (int j = 1; j <= my; j++)dp2[i][j] = max(dp2[i][j - 1], dp2[i + 1][j]) + map[i][j];
	for (int i = 1; i <= mx; i++)for (int j = my; j >= 1; j--)dp3[i][j] = max(dp3[i][j + 1], dp3[i - 1][j]) + map[i][j];
	for (int i = mx; i >= 1; i--)for (int j = my; j >= 1; j--)dp4[i][j] = max(dp4[i][j + 1], dp4[i + 1][j]) + map[i][j];
	int maxi = 0;
	for (int i = 2; i <= mx - 1; i++)for (int j = 2; j <= my - 1; j++)maxi = max(maxi, dp1[i - 1][j] + dp2[i][j - 1] + dp3[i][j + 1] + dp4[i + 1][j]);
	for (int i = 2; i <= mx - 1; i++)for (int j = 2; j <= my - 1; j++)maxi = max(maxi, dp1[i][j - 1] + dp2[i + 1][j] + dp3[i - 1][j] + dp4[i][j + 1]);
	printf("%d\n", maxi);
}