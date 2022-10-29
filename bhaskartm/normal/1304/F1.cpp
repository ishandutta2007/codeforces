#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
const int MAX_M = 20000;
const int MAX_K = 20;

int animal[MAX_N + 5][MAX_M + 5];
int psum[MAX_N + 5][MAX_M + 5];
int lmax[MAX_N + 5][MAX_M + 5];
int rmax[MAX_N + 5][MAX_M + 5];
int dp[MAX_N + 5][MAX_M + 5];

inline int ps(int i, int j, int k)
{
	return psum[i][k] - psum[i][j - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;

	int n, m, k;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> animal[i][j];
			psum[i][j] = psum[i][j - 1] + animal[i][j];
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m - k + 1; j++)
		{
			int p = ps(i, j, j + k - 1) + ps(i + 1, j, j + k - 1);
			if (i == 1)
			{
				dp[i][j] = p;
				continue;
			}
			int mx = 0;
			for (int x = max(1, j - k + 1); x <= min(m - k + 1, j + k - 1); x++)
				mx = max(mx, dp[i - 1][x] + p - ps(i, max(x, j), min(x + k - 1, j + k - 1)));
			dp[i][j] = mx;
			if (j > k)
				dp[i][j] = max(dp[i][j], lmax[i - 1][j - k] + p);
			if (j + k - 1 <= m - k)
				dp[i][j] = max(dp[i][j], rmax[i - 1][j + k] + p);
		}
		for (j = 1; j <= m - k + 1; j++)
			lmax[i][j] = max(lmax[i][j - 1], dp[i][j]);
		for (j = m - k + 1; j >= 1; j--)
			rmax[i][j] = max(rmax[i][j + 1], dp[i][j]);
	}

	cout << *max_element(dp[n] + 1, dp[n] + m + 1) << '\n';
}