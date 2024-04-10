#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll dp[5001][5001];
ll mod = 1000000007;
int lcp[5000][5000];
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	for (int i = 0; i < num; i++)
	{
		int now = 0;
		for (int j = num - 1; j >= i; j--)
		{
			if (s[j] == s[j - i])now++;
			else now = 0;
			lcp[j - i][j] = lcp[j][j - i] = now;
		}
	}
	if(s[0]!='0')for (int i = 0; i < num; i++)dp[0][i] = 1;
	for (int i = 1; i < num; i++)
	{
		if (s[i] == '0')continue;
		ll now = 0;
		for (int j = 0; j < i; j++)
		{
			if (lcp[i - j - 1][i] < j + 1 && s[i - j - 1 + lcp[i - j - 1][i]] < s[i + lcp[i - j - 1][i]])
			{
				now += dp[i - j - 1][i - 1];
				now %= mod;
				dp[i][i + j] += now;
				dp[i][i + j] %= mod;
			}
			else
			{
				dp[i][i + j] += now;
				dp[i][i + j] %= mod;
				now += dp[i - j - 1][i - 1];
				now %= mod;
			}
		}
		for (int j = i; j < num; j++)
		{
			dp[i][i + j] += now;
			dp[i][i + j] %= mod;
		}
	}
	ll sum = 0;
	for (int i = 0; i < num; i++)sum += dp[i][num - 1];
	printf("%I64d\n", sum%mod);
}