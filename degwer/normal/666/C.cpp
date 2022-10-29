#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define B 330
typedef long long ll;
int dp[B + 10][100001];
ll mod = 1000000007;
#define SIZE 100000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
ll ans[100001];
int main()
{
	dp[0][0] = 1;
	for (int i = 1; i <= 100000; i++)
	{
		for (int j = 0; j <= B + 5; j++)
		{
			dp[j][i] += ((ll)dp[j][i - 1] * 25LL)%mod;
			dp[j][i] %= mod;
		}
		for (int j = 0; j <= B + 4; j++)
		{
			dp[j + 1][i] += dp[j][i - 1];
			dp[j + 1][i] %= mod;
		}
		dp[B + 5][i] += dp[B + 5][i - 1];
		dp[B + 5][i] %= mod;
	}
	for (int i = B + 4; i >= 0; i--)
	{
		for (int j = 1; j <= 100000; j++)
		{
			dp[i][j] += (dp[i + 1][j]);
			dp[i][j] %= mod;
		}
	}
	invinit();
	int query;
	scanf("%d", &query);
	int num;
	for (int p = 0; p <= query; p++)
	{
		int za = 1;
		if (p != 0)scanf("%d", &za);
		if (za == 1)
		{
			string s;
			cin >> s;
			num = s.size();
			if (num > B)
			{
				ll now = 0;
				ll x = (25 * inv[26]) % mod;
				ll tim = 1;
				for (int i = 0; i < num; i++)ans[i] = 0;
				ll t26 = 1;
				for (int i = num; i <= 100000; i++)
				{
					now += com(i - 1, num - 1)*tim;
					now %= mod;
					ans[i] = (now*t26) % mod;
					tim *= x;
					tim %= mod;
					t26 *= 26;
					t26 %= mod;
				}
			}
		}
		else
		{
			int z;
			scanf("%d", &z);
			if (num > B)printf("%I64d\n", ans[z]);
			else printf("%d\n", dp[num][z]);
		}
	}
}