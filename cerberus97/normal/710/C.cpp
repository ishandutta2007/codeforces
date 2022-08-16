#include <iostream>

using namespace std;

int g[50][50] = {0};

void makeGrid(int n)
{
	int cur = 1;

	for (int i = 1; i <= (n+1)/2; ++i, cur += 2)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (j <= cur)
				g[i][j] = 1;
		}
	}

	cur = n-2;

	for (int i = (n + 1)/2 + 1; i <= n; ++i, cur -= 2)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (j <= cur)
				g[i][j] = 1;
		}
	}

	if (n % 6 == 3)
	{
		g[n][1] = 0;
		g[n][n-1] = 1;
		g[1][1] = 0;
		g[1][n-1] = 1;
	}
}

int main()
{
	int n, odd = 1, even = 2;
	cin >> n;

	makeGrid(n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			
			if (g[i][j])
			{
				cout << odd << ' ';
				odd += 2;
			}

			else
			{
				cout << even << ' ';
				even += 2;
			}
		}

		cout << '\n';
	}
}