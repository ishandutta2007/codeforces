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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10, S = 100, M = 5;

bool acute(int i, int j, int k);

int a[N][M];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> a[i][j];
	}

	if (n >= S)
	{
		cout << 0;
		return 0;
	}

	vector <int> ans;
	for (int i = 1; i <= n; ++i)
	{
		bool good = true;
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if (i == j or i == k or j == k or j > k)
					continue;

				if (acute(i, j, k))
				{
					good = false;
					break;
				}
			}

			if (!good)
				break;
		}

		if (good)
			ans.pb(i);
	}

	cout << ans.size() << endl;
	for (auto &i : ans)
		cout << i << endl;
}

bool acute(int i, int j, int k)
{
	int x[M], y[M];
	for (int d = 0; d < M; ++d)
	{
		x[d] = a[j][d] - a[i][d];
		y[d] = a[k][d] - a[i][d];
	}

	int num = 0;
	for (int d = 0; d < M; ++d)
		num += x[d] * y[d];


	return (num > 0);
}