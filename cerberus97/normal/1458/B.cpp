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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 110, W = 1e4 + 10, inf = 1e9 + 42;

int dp[N][W];

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int j = 0; j <= n; ++j) {
		for (int w = 0; w < W; ++w) {
			dp[j][w] = -inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			for (int w = 0; w < W; ++w) {
				dp[j + 1][w + b[i]] = max(dp[j + 1][w + b[i]], dp[j][w] + a[i] - b[i]);
			}
		}
	}
	int tw = accumulate(b.begin(), b.end(), 0);
	cout << fixed << setprecision(15);
	for (int k = 1; k <= n; ++k) {
		int ans = -inf;
		for (int w = 0; w < W; ++w) {
			int wo = tw - w;
			ans = max(ans, 2 * w + min(wo, 2 * dp[k][w]));
		}
		cout << ld(ans) / 2 << ' ';
	}
	cout << endl;
}