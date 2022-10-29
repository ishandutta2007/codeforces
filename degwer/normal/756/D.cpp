#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[5011][5011];
int nxt[6000][27];
ll cnt[5011];
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
int main()
{
	int num;
	scanf("%d", &num);
	string str;
	cin >> str;
	str.push_back('z' + 1);
	for (int i = 0; i < 27; i++)
	{
		int now = 5005;
		for (int j = num; j >= 0; j--)
		{
			nxt[j][i] = now;
			if (str[j] == i + 'a')now = j;
		}
	}
	for (int i = 0; i <= num; i++)dp[i][0] = 1;
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j <= num; j++)
		{
			dp[i][j + 1] = (dp[i + 1][j + 1] + dp[i + 1][j] + mod - dp[nxt[i][str[i] - 'a']][j]) % mod;
			cnt[j + 1] += dp[i][j + 1] - dp[i + 1][j + 1] + mod;
		}
	}
	for (int i = 1; i <= num; i++)cnt[i] %= mod;
	invinit();
	ll ans = 0;
	for (int i = 1; i <= num; i++)
	{
		ans += cnt[i] * com(num - 1, i - 1);
		ans %= mod;
	}
	printf("%I64d\n", ans);
}