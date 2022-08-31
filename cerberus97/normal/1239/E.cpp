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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 26, A = 5e4 + 10, S = N * A;

int a[2 * N];
bitset<S> dp[2 * N][N];

int main() {
	fast_cin();
	int n; cin >> n;
	n *= 2;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater<int>());
	vector<int> a1, a2;
	a1.pb(a[n]);
	a2.pb(a[n - 1]);
	n -= 2;
	int sum = 0, h = n / 2;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
	}
	sum /= 2;
	dp[0][0][0] = true;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= h; ++j) {
			dp[i][j] = dp[i - 1][j] | (dp[i - 1][j - 1] << a[i]);
		}
	}
	int best_s = -1;
	for (int s = sum; s >= 0; --s) {
		if (dp[n][h][s]) {
			best_s = s;
			break;
		}
	}
	int s = best_s, i = n, j = h;
	while (i) {
		if (dp[i - 1][j][s]) {
			a2.pb(a[i]);
			--i;
		} else {
			a1.pb(a[i]);
			s -= a[i];
			--i;
			--j;
		}
	}
	reverse(a2.begin(), a2.end());
	for (auto &val : a1) {
		cout << val << ' ';
	}
	cout << '\n';
	for (auto &val : a2) {
		cout << val << ' ';
	}
	cout << '\n';
}