/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 55;

char a[N][N];
bool seen[N][N][N][N];
int dp[N][N][N][N];

int solve(int x1, int x2, int y1, int y2);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> (a[i] + 1);
	}
	cout << solve(1, n, 1, n);
}

int solve(int x1, int x2, int y1, int y2) {
	if (x1 == x2 and y1 == y2) {
		return (a[x1][y1] == '#');
	} else if (seen[x1][x2][y1][y2]) {
		return dp[x1][x2][y1][y2];
	} else {
		seen[x1][x2][y1][y2] = true;
		int &ans = dp[x1][x2][y1][y2];
		ans = max(x2 - x1, y2 - y1) + 1;
		for (int x = x1; x < x2; ++x) {
			ans = min(ans, solve(x1, x, y1, y2) + solve(x + 1, x2, y1, y2));
		}
		for (int y = y1; y < y2; ++y) {
			ans = min(ans, solve(x1, x2, y1, y) + solve(x1, x2, y + 1, y2));
		}
		return ans;
	}
}