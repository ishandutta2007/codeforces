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
#include <unordered_map>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10;

ll val[N], v1[N], v2[N];
vector<pll> g[N];

void dfs(int u);
void custom_sort(ll *a, int n, int b);

int main() {
	fast_cin();
	int n; ll k;
	// cin >> n >> k;
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n - 1; ++i) {
		int p; ll w;
		// cin >> p >> w;
		scanf("%d%lld", &p, &w);
		g[p].pb({i + 1, w});
	}
	dfs(1);
	ll ans = 0;
	sort(val + 1, val + 1 + n);
	v1[n + 1] = v2[n + 1] = -1;
	for (int b = 61; b >= 0; --b) {
		// ll pref = (ans >> b);
		// unordered_map<ll, ll> mp;
		for (int i = 1; i <= n; ++i) {
			v1[i] = val[i] >> b;
			v2[i] = (val[i] ^ ans) >> b;
		}
		sort(v2 + 1, v2 + 1 + n);
		// custom_sort(v1, n, b);
		// custom_sort(v2, n, b);
		ll ctr = 0;
		int i = 1, j = 1;
		while (i <= n and j <= n) {
			if (v1[i] < v2[j]) {
				++i;
			} else if (v1[i] > v2[j]) {
				++j;
			} else {
				ll c = 1;
				++i;
				while (v1[i] == v1[i - 1]) {
					++i; ++c;
				}
				while (v2[j] == v1[i - 1]) {
					++j; ctr += c;
				}
				// ctr += c1 * c2;
			}
		}
		if (ctr < k) {
			k -= ctr;
			ans |= (1ll << b);
			// for (int t = 1; t <= n; ++t) {
			// 	v2[t] ^= (1ll << b);
			// }
			// custom_sort(v2, n, b);
		}
	}
	// cout << ans;
	printf("%lld", ans);
}

void dfs(int u) {
	for (auto &v : g[u]) {
		val[v.first] = v.second ^ val[u];
		v1[v.first] = v1[v.first];
		dfs(v.first);
	}
}

void custom_sort(ll *a, int n, int b) {
	int l = 1;
	for (int i = 2; i <= n + 1; ++i) {
		if (i == n + 1 or (a[i] >> (b + 1)) != (a[i - 1] >> (b + 1))) {
			int r = i - 1;
			while (l < r) {
				if (!((a[r] >> b) & 1) and (a[l] >> b) & 1) {
					swap(a[l], a[r]);
					++l;
					--r;
				} else if ((a[r] >> b) & 1) {
					--r;
				} else {
					++l;
				}
			}
			l = i;
		}
	}
}