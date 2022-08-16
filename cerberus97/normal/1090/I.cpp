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

const int N = 1e7 + 10;
const ll mod = (1ll << 32), inf = 4e18 + 42, inf2 = 2e9 + 42;

ll a[N];
unsigned int b[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		ll n, l, r;
		unsigned int x, y, z;
		cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
		for (int i = 3; i <= n; ++i) {
			b[i] = (b[i - 2] * x + b[i - 1] * y + z);
		}
		for (int i = 1; i <= n; ++i) {
			a[i] = (b[i] % (r - l + 1)) + l;
			// cout << a[i] << ' ';
		}
		// cout << endl;
		stack<ll> pos;
		pos.push(-inf);
		ll best = inf, mx = -inf2;
		for (int i = n; i >= 1; --i) {
			if (a[i] < 0) {
				if (mx > a[i]) {
					best = min(best, a[i] * mx);
				}
			} else if (a[i] > 0) {
				while (pos.top() > a[i]) {
					best = min(best, a[i] * pos.top());
					pos.pop();
				}
				pos.push(a[i]);
			} else if (mx > 0) {
				best = min(best, 0ll);
			}
			mx = max(mx, a[i]);
		}
		if (best == inf) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << best << '\n';
		}
	}
}