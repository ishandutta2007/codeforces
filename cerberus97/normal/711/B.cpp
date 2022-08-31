#include <iostream>

using namespace std;

long long a[505][505], rowSum[505] = {0}, colSum[505] = {0};

int main()
{
	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];

			rowSum[i] += a[i][j];
			colSum[j] += a[i][j];

			if (a[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	long long rS = (x == 0) ? rowSum[1] : rowSum[0];
	long long cS = (y == 0) ? colSum[1] : colSum[0];

	if (rS != cS)
	{
		cout << -1;
		return 0;
	}

	long long dS1 = 0, dS2 = 0;

	for (int i = 0; i < n; ++i)
		dS1 += a[i][i];

	for (int i = 0, j = n-1; i < n; ++i, --j)
		dS2 += a[i][j];

	int ans = 1;

	for (int i = 0; i < n; ++i)
	{
		if (i != x and rowSum[i] != rS)
		{
			ans = -1;
			break;
		}

		if (i != y and colSum[i] != cS)
		{
			ans = -2;
			break;
		}
	}

	if (x != y and dS1 != rS)
	{
		ans = -3;
	}

	if (x + y != n-1 and dS2 != rS)
	{
		ans = -4;
	}

	long long curSum = rowSum[x];

	if (curSum != colSum[y])
		ans = -5;

	if (x == y and curSum != dS1)
		ans = -6;

	if (x + y == n-1 and curSum != dS2)
		ans = -7;

	if (curSum >= rS)
		ans = -8;

	if (ans <= 0)
	{
		cout << -1;
		return 0;
	}

	cout << rS - curSum;
}