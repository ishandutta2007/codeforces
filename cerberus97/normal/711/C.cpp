#include <iostream>

using namespace std;

const int N = 105, M = 105;
const long long IMP = 1e12;

int a[N], m;
long long p[N][M], dp[N][M][N];
bool seen[N][M][N] = {0};

long long getAnswer(int i, int j, int k)
{
	if (seen[i][j][k])
		return dp[i][j][k];

	seen[i][j][k] = true;

	if (!i)
	{
		if (k == 0)
			dp[i][j][k] = 0;

		else
			dp[i][j][k] = IMP;

		return dp[i][j][k];
	}

	if (!k)
	{
		dp[i][j][k] = IMP;
		return IMP;
	}

	long long cost = 0;

	if (a[i] != 0 and a[i] != j)
	{
		dp[i][j][k] = IMP;
		return IMP;
	}

	if (a[i] == 0)
		cost += p[i][j];

	if (i == 1)
	{
		if (k == 1)
			dp[i][j][k] = cost;

		else
			dp[i][j][k] = IMP;

		return dp[i][j][k];
	}

	dp[i][j][k] = getAnswer(i-1, j, k);

	for (int l = 1; l <= m; ++l)
	{
		if (l == j)
			continue;

		dp[i][j][k] = min(dp[i][j][k], getAnswer(i-1, l, k-1));
	}

	dp[i][j][k] += cost;
	return dp[i][j][k];
}

int main()
{
	int n, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> p[i][j];

	long long ans = IMP;

	for (int i = 1; i <= m; ++i)
		ans = min(ans, getAnswer(n, i, k));


	
	/*for (int kk = 0; kk <= k; ++kk)
	{
		cout << "\nk = " << kk << endl;

		for (int ii = 0; ii <= n; ++ii)
		{
			for (int jj = 0; jj <= m; ++jj)
			{
				cout << getAnswer(ii, jj, kk) << ' ';
			}

			cout << endl;
		}
	}*/

	if (ans >= IMP)
		cout << -1;

	else
		cout << ans;
}