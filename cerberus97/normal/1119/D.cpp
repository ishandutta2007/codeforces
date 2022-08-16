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

ll s[N], pref[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	sort(s + 1, s + 1 + n);
	s[n + 1] = 2e18 + 1;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i + 1] - s[i];
	}
	sort(s + 1, s + 1 + n);
	for (int i = 1; i <= n; ++i) {
		pref[i] = s[i] + pref[i - 1];
	}
	int q; cin >> q;
	while (q--) {
		ll l, r;
		cin >> l >> r;
		int lo = 1, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (s[mid] > r - l + 1) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		ll ans = pref[hi] + (n - hi) * (r - l + 1);
		cout << ans << ' ';
	}
}