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

const int N = 1e6 + 10;
const ll inf = 1e18 + 42;

int main() {
	fast_cin();
	string s; cin >> s;
	ll x, y;
	cin >> x >> y;
	int n = s.length();
	if (x > y) {
		swap(x, y);
		for (auto& c : s) {
			if (c != '?') {
				c ^= '0' ^ '1';
			}
		}
	}
	s = " " + s;
	ll base = 0;
	vector<ll> c0(n + 1, 0), c1(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		c0[i] = c0[i - 1] + (s[i] == '0');
		c1[i] = c1[i - 1] + (s[i] == '1');
		if (s[i] == '0') {
			base += y * c1[i - 1];
		} else if (s[i] == '1') {
			base += x * c0[i - 1];
		}
	}
	vector<ll> pref = {0}, suff = {0};
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?') {
			ll cost = pref.back() + y * (c1[i - 1]) + x * (c1[n] - c1[i]);
			pref.pb(cost);
		}
	}
	for (int i = n; i >= 1; --i) {
		if (s[i] == '?') {
			ll cost = suff.back() + x * (c0[i - 1]) + y * (c0[n] - c0[i]);
			suff.pb(cost);
		}
	}
	ll ans = inf;
	int sz = pref.size() - 1;
	for (int i = 0; i <= sz; ++i) {
		int j = sz - i;
		ans = min(ans, base + pref[i] + suff[j] + (x * i) * j);
	}
	cout << ans << endl;
}