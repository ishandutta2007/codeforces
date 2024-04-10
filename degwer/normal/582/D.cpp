#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 3500LL
int dp1[SIZE][SIZE];
int dp2[SIZE][SIZE];
ll pr, gen;
vector<ll>nbp;
int memo[SIZE][SIZE][2];
ll calc(ll d, ll s, int type)
{
	if (d < 0)return 0LL;
	if (memo[d][s][type - 1] != -1)return memo[d][s][type - 1];
	if (type == 1)
	{
		ll p11 = ((ll)dp1[d][s] * ((nbp[d] * (nbp[d] + 1) / 2) % mod)) % mod;
		ll p12 = ((ll)dp2[d][s] * ((nbp[d] * (nbp[d] - 1) / 2) % mod)) % mod;
		memo[d][s][type - 1] = (p11 + p12 + calc(d - 1, s, 1)*(nbp[d] + 1) + calc(d - 1, s, 2)*(nbp[d])) % mod;
	}
	else
	{
		if (s == 0)s = 1;
		ll p21 = ((ll)dp1[d][s - 1] * ((pr*(pr - 1) / 2 + mod - ((pr - nbp[d])*(pr - nbp[d] - 1) / 2 % mod)) % mod)) % mod;
		ll p22 = ((ll)dp2[d][s - 1] * ((pr*(pr + 1) / 2 + mod - ((pr - nbp[d])*(pr - nbp[d] + 1) / 2 % mod)) % mod)) % mod;
		memo[d][s][type - 1] = (p21 + p22 + calc(d - 1, s - 1, 1)*(pr - nbp[d] - 1) + calc(d - 1, s - 1, 2)*(pr - nbp[d])) % mod;
	}
	return memo[d][s][type - 1];
}
int main()
{
	scanf("%I64d%I64d", &pr, &gen);
	gen = min(gen, SIZE - 1);
	string str;
	cin >> str;
	vector<ll>now;
	for (int i = 0; i < str.size(); i++)now.push_back(str[i] - '0');
	reverse(now.begin(), now.end());
	now.push_back(0);
	for (int i = 0; i < now.size(); i++)
	{
		if (now[i] != 9)
		{
			now[i]++;
			break;
		}
		else now[i] = 0;
	}
	reverse(now.begin(), now.end());
	for (;;)
	{
		ll n = 0;
		vector<ll>zn;
		bool f = false;
		for (int i = 0; i < now.size(); i++)
		{
			n *= 10;
			n += now[i];
			if (n / pr != 0)f = true;
			zn.push_back(n / pr);
			n %= pr;
		}
		nbp.push_back(n);
		now = zn;
		if (!f)break;
	}
	dp1[0][0] = 1;
	for (int i = 1; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			dp1[i][j] = ((ll)dp1[i - 1][j] * ((pr*(pr + 1)/2) % mod) + (ll)dp2[i - 1][j] * ((pr*(pr - 1)/2) % mod)) % mod;
		}
		for (int j = 1; j < SIZE; j++)
		{
			dp2[i][j]= ((ll)dp2[i - 1][j - 1] * ((pr*(pr + 1)/2) % mod) + (ll)dp1[i - 1][j - 1] * ((pr*(pr - 1)/2) % mod)) % mod;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 1; j >= 1; j--)
		{
			dp1[i][j - 1] = (dp1[i][j] + dp1[i][j - 1]) % mod;
			dp2[i][j - 1] = (dp2[i][j] + dp2[i][j - 1]) % mod;
		}
	}
	for (int i = 0; i < SIZE; i++)for (int j = 0; j < SIZE; j++)memo[i][j][0] = memo[i][j][1] = -1;
	printf("%I64d\n", calc(nbp.size() - 1, gen, 1));
}