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

const int N = 5e5 + 10, mod = 1e9 + 7;

int a[N], rev[N];
ll tree[4 * N];
map<int, int> mp;

void update(int i, int l, int r, int p, int x);
ll query(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]];
	}
	int id = 0;
	for (auto &i : mp) {
		i.second = ++id;
		rev[id] = i.first;
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = mp[a[i]];
	}
	ll ans = 0;
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= n; ++i) {
		update(1, 1, id, a[i], i);
		ll temp = query(1, 1, id, 1, a[i]) % mod;
		temp *= rev[a[i]];
		temp %= mod;
		temp *= (n - i + 1);
		temp %= mod;
		ans += temp;
	}
	memset(tree, 0, sizeof(tree));
	for (int i = n; i >= 1; --i) {
		ll temp = query(1, 1, id, 1, a[i] - 1) % mod;
		temp *= rev[a[i]];
		temp %= mod;
		temp *= i;
		temp %= mod;
		ans += temp;
		update(1, 1, id, a[i], n - i + 1);
	}
	cout << ans % mod << endl;
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	}
	tree[i] += x;
	if (l < r) {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
	}
}

ll query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}