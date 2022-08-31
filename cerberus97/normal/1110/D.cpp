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

const int N = 1e6 + 10, inf = 1e7;

int a[N], ctr[N], dp[N][3][5];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++ctr[a[i]];
	}
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= 2; ++j) {
			for (int k = 0; k <= 4; ++k) {
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= 2; ++j) {
			for (int k = 0; k <= 4; ++k) {
				int cur = dp[i][j][k];
				int c = ctr[i + 1];
				for (int t = 0; t <= 2; ++t) {
					if (j < t or k < t or c < t) {
						break;
					}
					if (k - t > 2) {
						continue;
					}
					int left = c - t;
					for (int x = 0; x <= left and x <= 4; ++x) {
						int &st = dp[i + 1][k - t][x];
						st = max(st, cur + t + (left - x) / 3);
					}
				}
			}
		}
	}
	int best = -inf;
	for (int j = 0; j <= 2; ++j) {
		for (int k = 0; k <= 4; ++k) {
			best = max(best, dp[m][j][k]);
		}
	}
	cout << best << endl;
}