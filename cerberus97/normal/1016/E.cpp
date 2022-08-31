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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

ll l[N], r[N], sum_l[N], sum_r[N];

int main() {
	fast_cin();
	ll s, a, b;
	cin >> s >> a >> b;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	for (int i = 1; i <= n; ++i) {
		sum_l[i] = sum_l[i - 1] + l[i];
	}
	for (int i = n; i >= 1; --i) {
		sum_r[i] = sum_r[i + 1] + r[i];
	}
	int q; cin >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		ll c = y - s, d = x * s;
		int lo = 1, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (r[mid] * c + d >= a * y) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		int s1 = hi + 1;

		lo = 1; hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (l[mid] * c + d <= b * y) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		int s2 = lo - 1;

		ld ans = 0;
		if (s1 <= s2) {
			ans += min(b * y, r[s2] * c + d);
			ans -= max(a * y, l[s1] * c + d);
			// if (s1 + 1 <= s2 - 1) {
			ans += ld(s2 - s1) * d + ld(c) * (sum_r[s1] - sum_r[s2]);
			ans -= ld(s2 - s1) * d + ld(c) * (sum_l[s2] - sum_l[s1]);
			// }
		}

		cout << fixed << setprecision(10) << ans / y << '\n';
	}
}