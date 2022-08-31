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

const int N = 1e2 + 5, inf = 1e9, MX = 510;

int a[N][N], c[N], r[N];

int solve(int n, int m, int s);
void play(int n, int m, int s);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	int ans = inf, x;
	for (int i = 0; i < MX; ++i)
	{
		int temp = solve(n, m, i);
		if (temp < ans)
		{
			ans = temp;
			x = i;
		}
	}

	if (ans >= inf)
		cout << -1;

	else
	{
		cout << ans << endl;
		play(n, m, x);
	}
}

int solve(int n, int m, int s)
{
	c[1] = s;
	int ans = s;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i][1] < c[1])
			return inf;

		r[i] = a[i][1] - c[1];
		ans += r[i];
	}

	for (int j = 2; j <= m; ++j)
	{
		if (a[1][j] < r[1])
			return inf;

		c[j] = a[1][j] - r[1];
		ans += c[j];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (r[i] + c[j] != a[i][j])
				return inf;
		}
	}

	return ans;
}

void play(int n, int m, int s)
{
	solve(n, m, s);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < r[i]; ++j)
			cout << "row " << i << '\n';

	for (int j = 1; j <= m; ++j)
		for (int i = 0; i < c[j]; ++i)
			cout << "col " << j << '\n';
}