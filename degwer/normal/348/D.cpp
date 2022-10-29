#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp1[3001][3001], dp2[3001][3001];
int map[3001][3001];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 1; i <= mx; i++)
	{
		char s[3001];
		scanf("%s", &s);
		for (int j = 1; j <= my; j++)
		{
			if (s[j - 1] == '.')map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	dp1[1][2] = 1;
	dp2[2][1] = 1;
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 1; j <= my; j++)
		{
			dp1[i][j] += dp1[i - 1][j] + dp1[i][j - 1];
			dp2[i][j] += dp2[i - 1][j] + dp2[i][j - 1];
			if (dp1[i][j] >= mod)dp1[i][j] -= mod;
			if (dp2[i][j] >= mod)dp2[i][j] -= mod;
			if (map[i][j])dp1[i][j] = dp2[i][j] = 0;
		}
	}
	printf("%I64d\n", (dp1[mx - 1][my] * dp2[mx][my - 1] % mod - dp1[mx][my - 1] * dp2[mx - 1][my] % mod + mod) % mod);
}