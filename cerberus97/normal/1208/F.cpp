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

const int N = (1 << 21) + 10, LOG = 23;

int a[N], dp[N][LOG];

void update(int mask, int b);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = n; i >= 1; --i) {
		int cand = 0, mask = 0;
		for (int b = LOG - 2; b >= 0; --b) {
			if (a[i] & (1 << b)) {
				cand |= (1 << b);
			} else if (dp[mask | (1 << b)][0] >= 2) {
				cand |= (1 << b);
				mask |= (1 << b);
			}
		}
		if (i + 2 <= n) {
			ans = max(ans, cand);
		}
		update(a[i], LOG - 1);
	}
	cout << ans << endl;
}

void update(int mask, int b) {
	if (dp[mask][b] >= 2) {
		return;
	}
	++dp[mask][b];
	if (b == 0) {
		return;
	} else {
		update(mask, b - 1);
		if (mask & (1 << (b - 1))) {
			update(mask ^ (1 << (b - 1)), b - 1);
		}
	}
}