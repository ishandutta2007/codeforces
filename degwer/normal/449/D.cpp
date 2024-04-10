#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[21][1048576];
ll p2[1048576];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dp[0][z]++;
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < (1 << 20); j++)
		{
			if (j&(1 << i))dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = dp[i][j] + dp[i][j + (1 << i)];
		}
	}
	ll ans = 0;
	p2[0] = 1;
	for (int i = 1; i < 1048576; i++)p2[i] = p2[i - 1] * 2 % mod;
	for (int i = 0; i < (1 << 20); i++)
	{
		int c = 0;
		for (int j = 0; j < 20; j++)if (i&(1 << j))c++;
		if (c & 1)ans = (ans + mod - p2[dp[20][i]]) % mod;
		else ans = (ans + p2[dp[20][i]]) % mod;
	}
	printf("%I64d\n", ans);
}