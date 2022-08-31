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

const int N = 30;

ll a[N][N], mn[N][N], mx[N][N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = n - 1; i >= 1; --i) {
		a[i][n] = mx[i + 1][n - 1] - mn[i + 1][n] + 1;
		mx[i][n] = mn[i][n] = a[i][n] + mx[i + 1][n];
		for (int j = n - 1; j >= 1; --j) {
			if (j > 1) {
				a[i][j] = mx[i + 1][j - 1] - min(mn[i + 1][j], mn[i][j + 1]) + 1;
			}
			mx[i][j] = a[i][j] + max(mx[i + 1][j], mx[i][j + 1]);
			mn[i][j] = a[i][j] + min(mn[i + 1][j], mn[i][j + 1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	int q; cin >> q;
	while (q--) {
		ll sum; cin >> sum;
		int x = 1, y = 1;
		cout << x << ' ' << y << '\n';
		while (x < n or y < n) {
			sum -= a[x][y];
			if (x == n) {
				++y;
			} else if (y == n) {
				++x;
			} else {
				if (sum > mx[x + 1][y]) {
					++y;
				} else {
					++x;
				}
			}
			cout << x << ' ' << y << '\n';
		}
		cout << endl;
	}
}