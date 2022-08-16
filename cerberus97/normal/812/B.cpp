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

const int N = 20;

int l[N], r[N], dp[N][2];
string s[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = n; i >= 1; --i)
		cin >> s[i];

	int last = 1;
	for (int i = 1; i <= n; ++i)
	{
		l[i] = m + 1;
		r[i] = 0;
		for (int j = 1; j <= m; ++j)
		{
			if (s[i][j] == '1')
			{
				l[i] = min(l[i], j);
				r[i] = max(r[i], j);
			}
		}

		if (l[i] < m + 1)
			last = i;
	}

	dp[1][0] = 2 * r[1];
	dp[1][1] = m + 1;
	for (int i = 2; i < last; ++i)
	{
		dp[i][0] = min(dp[i - 1][0] + 2 * r[i], dp[i - 1][1] + m + 1) + 1;
		dp[i][1] = min(dp[i - 1][1] + 2 * (m + 1 - l[i]), dp[i - 1][0] + m + 1) + 1;
	}	

	int ans = r[1];

	if (last > 1)
		ans = min(dp[last - 1][0] + r[last], dp[last - 1][1] + (m + 1 - l[last])) + 1;

	cout << ans;
}