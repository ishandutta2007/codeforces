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
#define dt(x) max((x), -(x))
#define edt(x, y) (dt(x) + (y) - 1) / (y)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ll inf = 1e18;

set<ll> st, el;

int main() {
	fast_cin();
	int n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;
	for (int i = 1; i <= cl; ++i) {
		int x; cin >> x;
		st.insert(x);
	}
	for (int i = 1; i <= ce; ++i) {
		int x; cin >> x;
		el.insert(x);
	}
	int q; cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			cout << max(y2 - y1, y1 - y2) << '\n';
		} else {
			ll ans = inf;
			auto s = st.lower_bound(y1);
			if (s != st.end()) {
				ans = min(ans, *s - y1 + dt(x1 - x2) + dt(*s - y2));
			}
			if (s != st.begin()) {
				--s;
				ans = min(ans, y1 - *s + dt(x1 - x2) + dt(*s - y2));
			}
			auto e = el.lower_bound(y1);
			if (e != el.end()) {
				ans = min(ans, *e - y1 + edt(x1 - x2, v) + dt(*e - y2));
			}
			if (e != el.begin()) {
				--e;
				ans = min(ans, y1 - *e + edt(x1 - x2, v) + dt(*e - y2));
			}
			cout << ans << '\n';
		}
	}
}