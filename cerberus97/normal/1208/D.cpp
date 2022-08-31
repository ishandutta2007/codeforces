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

ll p[N], s[N], tree[4 * N];

void update(int i, int l, int r, int p, int x);
int query(int i, int l, int r, ll val);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		update(1, 1, n, i, i);
	}
	for (int i = n; i >= 1; --i) {
		p[i] = query(1, 1, n, s[i]);
		update(1, 1, n, p[i], 0);
	}
	for (int i = 1; i <= n; ++i) {
		cout << p[i] << ' ';
	}
	cout << '\n';
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree[i] = x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		tree[i] = tree[lc] + tree[rc];
	}
}

int query(int i, int l, int r, ll val) {
	if (l == r) {
		return l;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (tree[lc] > val) {
			return query(lc, l, mid, val);
		} else {
			return query(rc, mid + 1, r, val - tree[lc]);
		}
	}
}