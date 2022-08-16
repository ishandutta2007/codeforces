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
#include <cassert>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int kN = 3e5 + 10, kTree = kN << 2;

int x, ul;
int cost[kN], tree[32][kTree], lazy[32][kTree], l[kTree], r[kTree];
vector <int> t1, t2;

bool check(int t, int m);
void build_tree(int i, int _l, int _r);
void tree_update(int t, int i, int lz);

int main() {
	fast_cin();
	int n;
	cin >> n;
	build_tree(1, 1, n);
	for (ul = 1; ul <= n; ++ul) {
		cin >> cost[ul];
		if (cost[ul] == 1000) {
			cost[ul] += 100;
			t1.pb(ul);
			x = -1000;
			tree_update(0, 1, 0);
		} else {
			cost[ul] += 200;
			t2.pb(ul);
			x = 200;
			tree_update(0, 1, 0);
		}
	}
	int lo = 0, hi = n * 2000, t = 1;
	while (lo <= hi) {
		for (int j = 0; j < kTree; ++j) {
			tree[t][j] = tree[0][j];
			lazy[t][j] = lazy[0][j];
		}
		int mid = (lo + hi) >> 1;
		if (check(t++, mid)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << hi + 1 << endl;
}

bool check(int t, int m) {
	// cout << t << ' ' << m << endl;
	int s1 = t1.size(), s2 = t2.size(), p = s2 - 1, a_max = min(s1, m / 1000);
	for (int a = 0; a <= a_max; ++a, m -= 1000) {
		int b = min(s2, m / 2000);
		if (a) {
			ul = t1[a - 1];
			x = cost[ul];
			tree_update(t, 1, 0);
		}
		while (p >= b) {
			ul = t2[p];
			x = -cost[ul];
			tree_update(t, 1, 0);
			--p;
		}
		if (tree[t][1] + m >= 2000 * b) {
			// cout << a << " true " << tree[t][1] << endl;
			return true;
		}
	}
	return false;
}

void build_tree(int i, int _l, int _r) {
	l[i] = _l;
	r[i] = _r;
	if (_l == _r) {
		return;
	}
	int mid = (_l + _r) >> 1;
	build_tree(i << 1, _l, mid);
	build_tree(1 + (i << 1), mid + 1, _r);
}

void tree_update(int t, int i, int lz) {
	tree[t][i] += lz;
	lazy[t][i] += lz;
	if (ul > r[i]) {
		return;
	}
	if (ul <= l[i]) {
		tree[t][i] += x;
		lazy[t][i] += x;
		return;
	}
	int lc = i << 1, rc = lc + 1;
	tree_update(t, lc, lazy[t][i]);
	tree_update(t, rc, lazy[t][i]);
	tree[t][i] = min(tree[t][lc], tree[t][rc]);
	lazy[t][i] = 0;
}