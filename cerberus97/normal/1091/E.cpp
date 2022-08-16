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

const int N = 5e5 + 10;
const ll inf = 1e18 + 42;

ll a[N], f[N], pref[N];
ll pref_limit[N], suff_limit[N];

int main() {
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n, greater<ll>());
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	int pos = n;
	for (int i = n; i >= 0; --i) {
		while (pos > i and a[pos] <= i) {
			--pos;
		}
		while (pos < n and a[pos + 1] > i) {
			++pos;
		}
		ll lhs = pref[i];
		ll rhs = pref[n] - pref[pos] + ll(pos - i) * i + ll(i) * (i - 1);
		f[i] = rhs - lhs;
		suff_limit[i] = (i >= -f[i] ? -f[i] : inf);
		pref_limit[i] = f[i] + 2 * i + (pos - i);
		// cout << i << ' ' << f[i] << ' ' << pref_limit[i] << ' ' << suff_limit[i] << ' ' << endl;
	}
	for (int i = 1; i <= n; ++i) {
		suff_limit[i] = max(suff_limit[i - 1], suff_limit[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		pref_limit[i] = min(pref_limit[i + 1], pref_limit[i]);
	}
	pos = 0;
	vector<int> ans;
	for (int d = n; d >= 0; --d) {
		if ((sum + d) % 2) {
			continue;
		}
		while (pos + 1 <= n and a[pos + 1] >= d) {
			++pos;
		}
		if (suff_limit[pos] <= d and d <= pref_limit[pos]) {
			ans.pb(d);
		}
	}
	reverse(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << -1;
	}
	for (auto &i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}