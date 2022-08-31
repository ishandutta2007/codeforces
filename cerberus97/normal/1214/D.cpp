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

const int N = 1e5 + 10;

vector<string> a;
vector<vector<bool>> dp;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	a.resize(n);
	dp.resize(n + 1, vector<bool>(m + 1, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dp[n - 1][m - 1] = true;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (dp[i][j] or a[i][j] == '#') {
				continue;
			}
			dp[i][j] = dp[i + 1][j] or dp[i][j + 1];
		}
	}
	if (!dp[0][0]) {
		cout << 0 << endl;
		return 0;
	}
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	for (int i = 0; i < n + m - 3; ++i) {
		if (dp[r1 + 1][c1]) {
			++r1;
		} else {
			++c1;
		}
		if (dp[r2][c2 + 1]) {
			++c2;
		} else {
			++r2;
		}
		if (tie(r1, c1) == tie(r2, c2)) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
}