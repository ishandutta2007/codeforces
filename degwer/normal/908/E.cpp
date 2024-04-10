#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[1010][1010];
ll d[1010];
int main()
{
	int len, num;
	scanf("%d%d", &len, &num);
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < len; j++)d[j] += (ll)(s[j] - '0') << i;
	}
	map<ll,int>ma;
	for (int i = 0; i < len; i++)ma[d[i]]++;
	dp[0][0] = 1;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j) % mod;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
		}
	}
	ll ans = 1;
	map<ll, int>::iterator it = ma.begin();
	for (;;)
	{
		if (it == ma.end())break;
		int z = (*it).second;
		it++;
		ll s = 0;
		for (int i = 1; i <= z; i++)s += dp[z][i];
		s %= mod;
		ans = ans * s%mod;
	}
	printf("%I64d\n", ans);
}