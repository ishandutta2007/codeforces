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

const int N = 2e5 + 10;

ll p[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			p[i] /= 100;
		}
		sort(p + 1, p + 1 + n, greater<ll>());
		int x, y, a, b;
		cin >> x >> a >> y >> b;
		if (x > y) {
			swap(x, y);
			swap(a, b);
		}
		ll k; cin >> k;
		int lo = 1, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			ll c0 = 0, c1 = 0, c2 = 0;
			for (int i = 1; i <= mid; ++i) {
				if (i % a == 0 and i % b == 0) {
					++c0;
				} else if (i % b == 0) {
					++c1;
				} else if (i % a == 0) {
					++c2;
				}
			}
			ll ans = 0;
			for (int i = 1; i <= mid; ++i) {
				if (c0) {
					ans += (x + y) * p[i];
					--c0;
				} else if (c1) {
					ans += y * p[i];
					--c1;
				} else if (c2) {
					ans += x * p[i];
					--c2;
				} else {
					break;
				}
			}
			if (ans >= k) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if (hi == n) {
			cout << -1 << '\n';
		} else {
			cout << hi + 1 << '\n';
		}
	}
}