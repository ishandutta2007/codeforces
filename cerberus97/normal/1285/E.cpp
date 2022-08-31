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

const int N = 2e5 + 10, inf = 1e9 + 42;

int l[N], r[N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pii> events;
		for (int i = 1; i <= n; ++i) {
			cin >> l[i] >> r[i];
			events.pb({l[i], -1});
			events.pb({r[i], 1});
		}
		sort(events.begin(), events.end());
		vector<pii> gaps;
		int cur = 0, prv = -inf, gap_start = -inf, cnt = 0, mx = 0;
		for (auto& e : events) {
			e.second = -e.second;
			if (e.first > prv) {
				if (cur == 0) {
					++cnt;
				}
				prv = e.first;
			}
			if (cur == 1 and e.second == 1) {
				if (gap_start < e.first) {
					gaps.pb({gap_start, e.first});
				}
			} else if (cur == 2 and e.second == -1) {
				gap_start = e.first;
			}
			cur += e.second;
			mx = max(mx, cur);
		}
		if (mx <= 1) {
			cout << cnt - 1 << '\n';
			continue;
		}
		int ans = cnt;
		sort(gaps.begin(), gaps.end());
		for (int i = 1; i <= n; ++i) {
			auto it1 = lower_bound(gaps.begin(), gaps.end(), l[i], [&](const pii& p, int val) {
				return p.first < val;
			});
			auto it2 = upper_bound(gaps.begin(), gaps.end(), r[i], [&](int val, const pii& p) {
				return val < p.second;
			});
			if (it1 < it2) {
				ans = max(ans, cnt + int(it2 - it1));
			}
		}
		cout << ans << '\n';
	}
}