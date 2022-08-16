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

const int N = 5e3 + 10, M = 25e2 + 10, inf = 1e9;

bool seen[N][M][2];
int dp[N][M][2], a[N], best[M];

int solve(int i, int j, int can);

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int m = (n + 1) / 2;
	best[m + 1] = inf;
	for (int i = m; i >= 1; --i) {
		best[i] = min(solve(n, i, 1), best[i + 1]);
	}
	for (int i = 1; i <= m; ++i) {
		cout << best[i] << ' ';
	}
}

int solve(int i, int j, int can) {
	if (j == 0) {
		return 0;
	} else if (i <= 0) {
		return inf;
	} else if (seen[i][j][can]) {
		return dp[i][j][can];
	} else {
		seen[i][j][can] = true;
		int ans = solve(i - 1, j, 0);
		ans = min(ans, solve(i - 1, j, 1) + max(0, a[i] - a[i - 1] + 1));
		if (can) {
			int cost = max(0, a[i - 1] - a[i] + 1), temp = a[i - 1] - cost;
			ans = min(ans, cost + solve(i - 2, j - 1, 0));
			if (i >= 2) {
				ans = min(ans, cost + solve(i - 2, j - 1, 1) + max(0, temp - a[i - 2] + 1));
			}
		}
		dp[i][j][can] = ans;
		return ans;
	}
}