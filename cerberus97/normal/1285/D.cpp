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

const int N = 1e5 + 10, LOG = 30;

ll a[N];

ll solve(int l, int r, int b);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	cout << solve(1, n, LOG) << endl;
}

ll solve(int l, int r, int b) {
	if (l > r) {
		return 0;
	} else if (b < 0) {
		ll ans = 0;
		for (int i = l; i <= r; ++i) {
			ans = max(ans, a[i]);
		}
		return ans;
	}
	int mid = l;
	while (mid <= r and !((a[mid] >> b) & 1)) {
		++mid;
	}
	if (mid == r + 1) {
		return solve(l, r, b - 1);
	} else if (l == mid) {
		return solve(l, r, b - 1) ^ (1 << b);
	}
	ll mx1 = 0, mx2 = 0;
	for (int i = l; i < mid; ++i) {
		mx1 = max(mx1, a[i]);
	}
	for (int i = mid; i <= r; ++i) {
		mx2 = max(mx2, a[i]);
	}
	ll ans = max(mx2 ^ (1 << b), solve(l, mid - 1, b - 1) ^ (1 << b));
	ans = min(ans, max(mx1, solve(mid, r, b - 1)));
	return ans;
}