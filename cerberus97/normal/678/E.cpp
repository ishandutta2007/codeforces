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
#include "bitset"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 19, M = (1 << N) + 10;

double p[N][N], dp[M][N] = {0};

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> p[i][j];

	dp[1][0] = 1.0;
	int subsets = (1 << n);
	for (int i = 2; i < subsets; ++i)
	{
		if ((i & 1) == 0)
			continue;

		for (int j = 0; j < n; ++j)
		{
			if ((i & (1 << j)) == 0)
				continue;

			for (int k = 0; k < n; ++k)
			{
				if ((i & (1 << k)) == 0)
					continue;

				dp[i][j] = max(dp[i][j], p[j][k] * dp[i - (1 << k)][j] + p[k][j] * dp[i - (1 << j)][k]);
			}
		}
	}

	// for (int i = 0; i < subsets; ++i)
	// 	for (int j = 0; j < n; ++j)
	// 		cout << bitset<4>(i) << ' ' << j + 1 << ' ' << dp[i][j] << endl;

	double ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, dp[subsets - 1][i]);

	cout << fixed << setprecision(8) << ans;
}