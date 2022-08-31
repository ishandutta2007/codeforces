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

const int N = 2e5 + 10, X = 5e5 + 10, LOG = log2(X) + 10;

ll mx[X], go[X][LOG];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		mx[l] = max(mx[l], ll(r));
	}
	for (int i = 1; i < X; ++i) {
		mx[i] = max(mx[i], mx[i - 1]);
	}
	for (int i = X - 2; i >= 0; --i) {
		go[i][0] = mx[i];
		for (int j = 1; j < LOG; ++j) {
			go[i][j] = go[go[i][j - 1]][j - 1];
		}
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (int j = LOG - 1; j >= 0; --j) {
			if (go[x][j] < y) {
				ans += (1 << j);
				x = go[x][j];
			}
		}
		if (go[x][0] >= y) {
			cout << ans + 1 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}