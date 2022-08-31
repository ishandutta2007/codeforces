#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5;

string s[N], rev[N];
long long c[N], dp[2][N];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> c[i];

	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];

		rev[i] = s[i];
		reverse(rev[i].begin(), rev[i].end());

		dp[0][i] = dp[1][i] = 1e18;
	}

	dp[0][0] = 0;
	dp[1][0] = c[0];

	for (int i = 1; i < n; ++i)
	{
		if (s[i] >= s[i-1])
		{
			if (s[i] >= rev[i-1])
				dp[0][i] = min(dp[0][i-1], dp[1][i-1]);

			else
				dp[0][i] = dp[0][i-1];
		}

		else if (s[i] >= rev[i-1])
			dp[0][i] = dp[1][i-1];

		if (rev[i] >= s[i-1])
		{
			if (rev[i] >= rev[i-1])
				dp[1][i] = c[i] + min(dp[0][i-1], dp[1][i-1]);

			else
				dp[1][i] = c[i] + dp[0][i-1];
		}

		else if (rev[i] >= rev[i-1])
			dp[1][i] = c[i] + dp[1][i-1];

	}

	long long ans = min(dp[0][n-1], dp[1][n-1]);

	if (ans >= 1e18)
		cout << -1;

	else
		cout << ans;
}