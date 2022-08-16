/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5, inf = 100;

bool seen[N][N][4] = {0};
int dp[N][N][4], ch[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char s[N][N];

void f(int i, int j, int n, int m, int dir, int turns);

int main()
{
	fast_cin();
	int n, m, x1, y1, x2, y2;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int d = 0; d < 4; ++d)
				dp[i][j][d] = inf;

			cin >> s[i][j];
			if (s[i][j] == 'S')
			{
				x1 = i;
				y1 = j;
			}

			if (s[i][j] == 'T')
			{
				x2 = i;
				y2 = j;
			}
		}
	}

	for (int d = 0; d < 4; ++d)
		f(x1, y1, n, m, d, 0);

	int ans = inf;
	for (int d = 0; d < 4; ++d)
		ans = min(ans, dp[x2][y2][d]);

	if (ans <= 2)
		cout << "YES";

	else
		cout << "NO";
}

void f(int i, int j, int n, int m, int dir, int turns)
{
	if (i < 1 or i > n or j < 1 or j > m or s[i][j] == '*')
		return;

	if (dp[i][j][dir] <= turns or turns > 2)
		return;

	dp[i][j][dir] = turns;
	for (int d = 0; d < 4; ++d)
	{
		int temp = (d + 2) % 4;
		int x = i + ch[temp][0], y = j + ch[temp][1];
		if (d == dir)
			f(x, y, n, m, d, turns);
		else
			f(x, y, n, m, d, turns + 1);
	}
}