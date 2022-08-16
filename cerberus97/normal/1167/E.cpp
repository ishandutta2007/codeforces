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

const int N = 1e6 + 10, inf = 1e9 + 42;

int mn[N], mx[N];
bool pref_ok[N], suff_ok[N];

int main() {
	fast_cin();
	int n, x;
	cin >> n >> x;
	for (int i = 0; i <= x + 1; ++i) {
		mn[i] = inf;
		mx[i] = -inf;
	}
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a;
		mx[a] = i;
		mn[a] = min(mn[a], i);
	}
	pref_ok[0] = true;
	int p = -inf;
	for (int i = 1; i <= x; ++i) {
		if (p <= mn[i]) {
			pref_ok[i] = true;
			p = max(p, mx[i]);
		} else {
			break;
		}
	}
	suff_ok[x + 1] = true;
	p = inf;
	for (int i = x; i >= 1; --i) {
		if (mx[i] <= p) {
			suff_ok[i] = true;
			p = min(p, mn[i]);
		} else {
			break;
		}
	}
	for (int i = 1; i <= x + 1; ++i) {
		mx[i] = max(mx[i], mx[i - 1]);
	}
	for (int i = x; i >= 0; --i) {
		mn[i] = min(mn[i], mn[i + 1]);
	}
	ll ans = 0;
	int r = 1;
	for (int l = 1; l <= x; ++l) {
		if (!pref_ok[l - 1]) {
			break;
		}
		while (!suff_ok[r + 1] or mx[l - 1] > mn[r + 1] or r < l) {
			++r;
		}
		// cout << l << ' ' << r << endl;
		ans += x - r + 1;
	}
	cout << ans << endl;
}