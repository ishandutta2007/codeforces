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

const int N = 5e5 + 10, inf = 1e9 + 42;

struct friend_t {
	int t, a, b;
	bool operator<(const friend_t &o) const {
		return t < o.t;
	}
};

friend_t f[N];

int main() {
	fast_cin();
	int tc; cin >> tc;
	while (tc--) {
		int n, m, c, c0;
		cin >> n >> m >> c >> c0;
		for (int i = 1; i <= n; ++i) {
			cin >> f[i].t >> f[i].a >> f[i].b;
		}
		sort(f + 1, f + 1 + n);
		f[++n] = {m, 0, 0};
		int t = 0, cur = c0;
		map<int, int> have;
		bool ok = true;
		ll ans = 0, tot_have = 0;
		for (int i = 1; i <= n; ++i) {
			cur -= (f[i].t - t);
			while (cur < 0) {
				if (have.empty()) {
					ok = false;
					break;
				}
				auto it = have.begin();
				ll cost = it->first;
				int take = min(it->second, -cur);
				cur += take;
				ans += cost * take;
				it->second -= take;
				tot_have -= take;
				if (it->second == 0) {
					have.erase(it);
				}
			}
			have[f[i].b] += f[i].a;
			tot_have += f[i].a;
			int extra = tot_have - (c - cur);
			while (extra > 0) {
				auto it = have.end();
				--it;
				int del = min(extra, it->second);
				extra -= del;
				tot_have -= del;
				it->second -= del;
				if (it->second == 0) {
					have.erase(it);
				}
			}
			t = f[i].t;
		}
		if (ok) {
			cout << ans << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}