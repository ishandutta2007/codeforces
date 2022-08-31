#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;

bool isSorted(int *a, int m)
{
	for (int i = 0; i < m; ++i)
		if (a[i] != i+1)
			return false;

	return true;
}

bool isPossible(int *a, int m, int x, int y)
{
	for (int i = 0; i < m-1; ++i)
	{
		for (int j = i+1; j < m; ++j)
		{
			swap(a[i], a[j]);
			swap(a[x], a[y]);

			if (isSorted(a, m))
			{
				swap(a[x], a[y]);
				swap(a[i], a[j]);
				return true;
			}

			swap(a[x], a[y]);
			swap(a[i], a[j]);
		}
	}

	swap(a[x], a[y]);

	if (isSorted(a, m))
		return true;

	for (int i = 0; i < m-1; ++i)
	{
		for (int j = i+1; j < m; ++j)
		{
			swap(a[i], a[j]);

			if (isSorted(a, m))
			{
				swap(a[i], a[j]);
				swap(a[x], a[y]);
				return true;
			}

			swap(a[i], a[j]);
		}
	}

	swap(a[x], a[y]);
	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int a[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	}

	bool ans = false;

	for (int x = 0; x < m; ++x)
	{
		for (int y = x; y < m; ++y)
		{
			bool temp = true;

			for (int i = 0; i < n; ++i)
			{
				if (!isPossible(a[i], m, x, y))
				{
					temp = false;
					break;
				}
			}

			if (temp)
			{
				ans = true;
				break;
			}

		}
	}

	if (ans)
		cout << "YES";

	else
		cout << "NO";
}