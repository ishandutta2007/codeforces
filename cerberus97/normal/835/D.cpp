/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e3 + 10, K = 15;

int ans[K];
bool dp[2][N][N], pal[N][N];

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	ans[1] = n;
	for (int i = 0; i < n; ++i)
		pal[i][i] = true;

	for (int i = 1; i < n; ++i)
		pal[i][i - 1] = true;

	for (int len = 2; len <= n; ++len)
	{
		for (int i = 0; i + len - 1 < n; ++i)
		{
			pal[i][i + len - 1] = (s[i] == s[i + len - 1]) and pal[i + 1][i + len - 2];
			if (pal[i][i + len - 1])
				++ans[1];
		}
	}

	int prev = 0, cur = 1;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			dp[prev][i][j] = pal[i][j];

	for (int k = 2; ; ++k)
	{
		int len = (1 << (k - 1));
		if (len > n)
			break;

		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + len - 1; j < n; ++j)
			{
				if (pal[i][j] and dp[prev][i][i + ((j - i + 1) >> 1) - 1])
				{
					dp[cur][i][j] = true;
					++ans[k];
				}
			}
		}

		swap(cur, prev);
	}

	for (int k = 1; k <= n; ++k)
	{
		if (k >= K)
			cout << "0 ";

		else
			cout << ans[k] << ' ';
	}
}