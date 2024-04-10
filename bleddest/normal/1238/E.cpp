#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>

using namespace std;

int cnt[20][20];

int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n - 1; i++)
	{
		int c1 = s[i] - 'a', c2 = s[i + 1] - 'a';
		cnt[c1][c2]++;
		cnt[c2][c1]++;
	}
	vector<int> dp(1 << m, int(1e9));
	dp[0] = 0;
	for (int i = 0; i < (1 << m); i++)
	{
		int len = 0;
		for (int j = 0; j < m; j++)
			if (i & (1 << j))
				len++;
		for (int j = 0; j < m; j++)
		{
			if (i & (1 << j))
				continue;
			int sum = 0;
			for (int k = 0; k < m; k++)
			{
				if (j == k) continue;
				if (i & (1 << k))
					sum += cnt[j][k] * len;
				else
					sum -= cnt[j][k] * len;
			}
			dp[i ^ (1 << j)] = min(dp[i ^ (1 << j)], dp[i] + sum);
		}
	}
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}