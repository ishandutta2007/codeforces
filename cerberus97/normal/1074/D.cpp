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

int sz[N], par[N], up[N];
map<int, int> mp;

pii get_root(int i);
void merge(int u, int v, int val);

int main() {
	fast_cin();
	int q; cin >> q;
	for (int i = 0; i <= 2 * q + 10; ++i) {
		sz[i] = 1;
		par[i] = i;
	}
	int last = 0, nxt_idx = 1;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l = l ^ last;
			r = r ^ last;
			x = x ^ last;
			++l; ++r;
			if (l > r) {
				swap(l, r);
			}
			if (mp.find(l - 1) == mp.end()) {
				mp[l - 1] = nxt_idx++;
			}
			if (mp.find(r) == mp.end()) {
				mp[r] = nxt_idx++;
			}
			merge(mp[l - 1], mp[r], x);
		} else {
			int l, r;
			cin >> l >> r;
			l = l ^ last;
			r = r ^ last;
			++l; ++r;
			if (l > r) {
				swap(l, r);
			}
			if (mp.find(l - 1) == mp.end()) {
				mp[l - 1] = nxt_idx++;
			}
			if (mp.find(r) == mp.end()) {
				mp[r] = nxt_idx++;
			}
			pii p1 = get_root(mp[l - 1]);
			pii p2 = get_root(mp[r]);
			int ans = -1;
			if (p1.first == p2.first) {
				ans = p2.second ^ p1.second;
			}
			cout << ans << '\n';
			last = ans;
			if (last == -1) {
				last = 1;
			}
		}
	}
}

pii get_root(int i) {
	int val = 0;
	while (i != par[i]) {
		val ^= up[i];
		i = par[i];
	}
	return {i, val};
}

void merge(int u, int v, int val) {
	pii p1 = get_root(u);
	pii p2 = get_root(v);
	u = p1.first;
	v = p2.first;
	val ^= (p1.second ^ p2.second);
	if (u == v) {
		return;
	}
	if (sz[u] < sz[v]) {
		swap(u, v);
	}
	par[v] = u;
	up[v] = val;
	sz[u] += sz[v];
}