#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[2001][2001][2];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	string str;
	cin >> str;
	dp[num][0][0] = 1;
	for (int i = num - 1; i >= 0; i--)
	{
		int ad = num - i;
		for (int j = 0; j <= gen; j++)
		{
			int now = i;
			for (int k = j + ad; k <= gen&&now >= 0; k += ad)
			{
				dp[now][k][1] += (dp[i + 1][j][0] + dp[i + 1][j][1]) * ('z' - str[i]);
				dp[now][k][1] %= mod;
				now--;
			}
			dp[i][j][0] = (dp[i + 1][j][0] * (str[i] - 'a' + 1) + dp[i + 1][j][1] * (str[i] - 'a')) % mod;
		}
	}
	ll ans = dp[0][gen][0] + dp[0][gen][1];
	printf("%I64d\n", ans%mod);
}