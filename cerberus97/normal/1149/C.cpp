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

const int N = 1e5 + 10, inf = 1e9 + 42;

struct node_t {
	int mx, mn, to_right, to_left, lazy, ans;
};

node_t tree[8 * N];
int d[2 * N];

void update(int i, int l, int r, int ql, int qr, int x);
void add(int i, int x);
void combine(int i, int lc, int rc);
void propagate(int i, int lc, int rc);

int main() {
	fast_cin();
	int n, q; string s;
	cin >> n >> q >> s;
	s = "(" + s;
	n *= 2;
	--n;
	d[0] = 1;
	for (int i = 1; i < n; ++i) {
		d[i] = d[i - 1] + ((s[i] == '(') ? 1 : -1);
	}
	for (int i = 0; i < n; ++i) {
		update(1, 0, n - 1, i, i, d[i]);
	}
	cout << tree[1].ans << '\n';
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		update(1, 0, n - 1, a, b - 1, (s[a] == '(') ? -2 : 2);
		swap(s[a], s[b]);
		cout << tree[1].ans << '\n';
	}
}

void update(int i, int l, int r, int ql, int qr, int x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		add(i, x);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, x);
		update(rc, mid + 1, r, ql, qr, x);
		combine(i, lc, rc);
	}
}

void add(int i, int x) {
	tree[i].mx += x;
	tree[i].mn += x;
	tree[i].to_right -= x;
	tree[i].to_left -= x;
	tree[i].lazy += x;
}

void combine(int i, int lc, int rc) {
	tree[i].mx = max(tree[lc].mx, tree[rc].mx);
	tree[i].mn = min(tree[lc].mn, tree[rc].mn);
	tree[i].to_right = max(tree[lc].to_right, tree[rc].to_right);
	tree[i].to_right = max(tree[i].to_right, tree[rc].mx - 2 * tree[lc].mn);
	tree[i].to_left = max(tree[lc].to_left, tree[rc].to_left);
	tree[i].to_left = max(tree[i].to_left, tree[lc].mx - 2 * tree[rc].mn);
	tree[i].ans = max(tree[lc].ans, tree[rc].ans);
	tree[i].ans = max(tree[i].ans, max(tree[lc].mx + tree[rc].to_right, tree[lc].to_left + tree[rc].mx));
}

void propagate(int i, int lc, int rc) {
	add(lc, tree[i].lazy);
	add(rc, tree[i].lazy);
	tree[i].lazy = 0;
}