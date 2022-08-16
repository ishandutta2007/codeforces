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

const int N = 45, H = 20, S = (1 << H) + 10;
const ll one = 1;

vector<int> g[N];
bool seen[N], color[N];
ll nb[N];

bool has_odd_cycle(int u, bool c);
vector<int> get_masks(vector<int> nb);
vector<int> sos_dp(vector<int> v, int n);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	if (m < 3) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].pb(v);
		g[v].pb(u);
		nb[u] |= (one << v);
		nb[v] |= (one << u);
	}
	int components = 0, size_one_components = 0;
	bool bipartite = true;
	for (int i = 0; i < n; ++i) {
		if (!nb[i]) {
			++size_one_components;
		}
		if (!seen[i]) {
			++components;
			if (has_odd_cycle(i, 0)) {
				bipartite = false;
			}
		}
	}
	ll ans = (one << n) - (one << components) + 2 * (one << size_one_components);
	if (bipartite) {
		ans += (one << components);
	}
	int h = n / 2;
	vector<int> nb1(h), nb2(n - h);
	for (int i = 0; i < h; ++i) {
		nb1[i] = nb[i] & ((one << h) - 1);
		// cout << nb1[i] << endl;
	}
	for (int i = h; i < n; ++i) {
		nb2[i - h] = (nb[i] >> h);
	}
	auto isets1 = get_masks(nb1);
	auto isets2 = get_masks(nb2);
	// for (auto &i : isets1) {
	// 	cout << i << endl;
	// }
	// for (auto &i : isets2) {
	// 	cout << i << endl;
	// }
	isets2 = sos_dp(isets2, n - h);
	ll ind_sets = 0;
	for (int m1 = 0; m1 < (one << h); ++m1) {
		if (!isets1[m1]) {
			continue;
		}
		ll avoid = 0;
		for (int i = 0; i < h; ++i) {
			if (m1 & (1 << i)) {
				avoid |= (nb[i] >> h);
			}
		}
		ll complement = (one << (n - h)) - 1 - avoid;
		ind_sets += isets2[complement];
	}
	// cout << ind_sets << endl;
	ans -= 2 * ind_sets;
	cout << ans << endl;
}

bool has_odd_cycle(int u, bool c) {
	seen[u] = true;
	color[u] = c;
	bool ans = false;
	for (auto &v : g[u]) {
		if (seen[v]) {
			if (color[v] == color[u]) {
				ans = true;
			}
		} else {
			ans |= has_odd_cycle(v, !c);
		}
	}
	return ans;
}


vector<int> get_masks(vector<int> v) {
	int n = v.size(), tot = (1 << n);
	vector<int> ans(tot, 0);
	for (int mask = 0; mask < tot; ++mask) {
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				if (v[i] & mask) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			ans[mask] = 1;
		}
	}
	return ans;
}

vector<int> sos_dp(vector<int> v, int n) {
	int tot = (1 << n);
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < tot; ++mask) {
			if (mask & (1 << i)) {
				v[mask] += v[mask ^ (1 << i)];
			}
		}
	}
	return v;
}