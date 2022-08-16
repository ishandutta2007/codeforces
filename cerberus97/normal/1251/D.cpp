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
const ll inf = 1e15 + 42;

ll l[N], r[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; ll s;
		cin >> n >> s;
		for (int i = 1; i <= n; ++i) {
			cin >> l[i] >> r[i];
			s -= l[i];
		}
		int k = (n + 1) / 2;
		ll lo = 1, hi = inf;
		while (lo <= hi) {
			ll m = (lo + hi) / 2;
			priority_queue<ll> q;
			for (int i = 1; i <= n; ++i) {
				if (r[i] >= m) {
					q.push(l[i]);
				}
			}
			bool ok = false;
			if (q.size() >= k) {
				ll cost = 0;
				for (int i = 0; i < k; ++i) {
					cost += max(0ll, m - q.top());
					q.pop();
				}
				if (cost <= s) {
					ok = true;
				}
			}
			if (ok) {
				lo = m + 1;
			} else {
				hi = m - 1;
			}
		}
		cout << lo - 1 << '\n';
	}
}