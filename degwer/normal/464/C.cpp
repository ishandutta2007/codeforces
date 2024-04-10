#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll po(ll a, ll b)
{
	if (b == 0)return 1LL;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b % 2 == 1)z = z*a%mod;
	return z;
}
ll dp[100002][10];
ll ket[100002][10];
typedef pair<int, string>pis;
int main()
{
	string str;
	cin >> str;
	int query;
	scanf("%d", &query);
	vector<pis>vec;
	vec.push_back(make_pair(0, str));
	for (int i = 0; i < query; i++)
	{
		string z;
		cin >> z;
		char za = z[0];
		string s;
		for (int i = 3; i < z.size(); i++)s.push_back(z[i]);
		vec.push_back(make_pair(za - '0', s));
	}
	for (int i = 0; i < 10; i++)dp[query + 1][i] = i, ket[query + 1][i] = 1;
	for (int i = query; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j != vec[i].first)
			{
				dp[i][j] = dp[i + 1][j];
				ket[i][j] = ket[i + 1][j];
			}
			else
			{
				ll now = 0;
				ll cnt = 0;
				for (int k = int(vec[i].second.size()) - 1; k >= 0; k--)
				{
					cnt += po(10LL, now)*dp[i + 1][vec[i].second[k] - '0'];
					cnt %= mod;
					now += ket[i + 1][vec[i].second[k] - '0'];
					now %= (mod - 1);
				}
				dp[i][j] = cnt;
				ket[i][j] = now;
			}
		}
	}
	printf("%I64d\n", dp[0][0]);
}