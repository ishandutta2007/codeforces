#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll dat[1 << 16][20];
ll rui[100000][20];
ll dp[20][20][2];
ll get(vector<int>v)
{
	//for (int i = 0; i < v.size(); i++)printf("%d ", v[i]); printf("\n");
	for (int i = 0; i < 20; i++)for (int j = 0; j < 20; j++)dp[i][j][0] = dp[i][j][1] = 0;
	int maxi = 0;
	for (int i = 0; i<int(v.size()) - 4; i++)maxi = max(maxi, v[i]);
	int now = 0;
	for (int i = v.size() - 4; i < v.size(); i++)now *= 16, now += v[i];
	ll ans = rui[now + 1][maxi];
	for (int i = 0; i < 4; i++)v.pop_back();
	dp[0][0][0] = 1;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				if (v[i] > k)dp[i + 1][max(j, k)][1] += dp[i][j][0] + dp[i][j][1];
				else if (v[i] == k)dp[i + 1][max(j, k)][1] += dp[i][j][1], dp[i + 1][max(j, k)][0] += dp[i][j][0];
				else dp[i + 1][max(j, k)][1] += dp[i][j][1];
			}
		}
	}
	for (int i = 0; i < 16; i++)ans += dp[v.size()][i][1] * rui[1 << 16][i];
	return ans;
}
vector<int>conv(string s)
{
	vector<int>v;
	for (int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')v.push_back(s[i] - '0');
		else v.push_back(s[i] - 'a' + 10);
	}
	reverse(v.begin(), v.end());
	for (;;)
	{
		if (v.size() >= 18)break;
		v.push_back(0);
	}
	reverse(v.begin(), v.end());
	return v;
}
int main()
{
	for (int p = 0; p < (1 << 16); p++)
	{
		int maxi = 0;
		int x = p;
		for (int i = 0; i < 4; i++)
		{
			maxi = max(maxi, x % 16);
			x /= 16;
		}
		for (int i = 0; i < 16; i++)
		{
			if (maxi >= i)
			{
				if (p&(1 << maxi))dat[p][i] = 1;
				else dat[p][i] = 0;
			}
			else
			{
				if (p&(1 << i))dat[p][i] = 1;
				else dat[p][i] = 0;
			}
		}
	}
	for (int i = 0; i < (1 << 16); i++)for (int j = 0; j < 16; j++)rui[i + 1][j] = rui[i][j] + dat[i][j];
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		string sa, sb;
		cin >> sa >> sb;
		vector<int>a = conv(sa), b = conv(sb);
		if (sa != "0")a[a.size() - 1]--;
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (a[i] < 0)a[i] = 15, a[i - 1]--;
			else break;
		}
		printf("%I64d\n", get(b) - get(a));
	}
}