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

const int N = 1e5 + 5, max_x = 110, max_y = 110, T = 15;

int x[N], y[N], s[N];
int a[T][max_x][max_y], sum[T][max_x][max_y];

int main()
{
	fast_cin();
	cin.tie(0);
	int n, q, c;
	cin >> n >> q >> c;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> s[i];

	for (int t = 0; t <= c; ++t)
	{
		for (int i = 1; i <= n; ++i)
			a[t][x[i]][y[i]] += ((s[i] + t) % (c + 1));

		for (int i = 1; i <= max_x; ++i)
			for (int j = 1; j <= max_y; ++j)
				sum[t][i][j] = a[t][i][j] + sum[t][i - 1][j] + sum[t][i][j - 1] - sum[t][i - 1][j - 1];
	}

	while (q--)
	{
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		t = t % (c + 1);
		cout << sum[t][x2][y2] - sum[t][x1 - 1][y2] - sum[t][x2][y1 - 1] + sum[t][x1 - 1][y1 - 1] << '\n';
	}
}