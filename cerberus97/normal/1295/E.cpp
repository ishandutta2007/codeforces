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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;
const ll inf = 1e18 + 42;

struct node {
	ll a_sum, b_sum, best;
};

int p[N], loc[N], a[N];
node tree[4 * N];

void build(int i, int l, int r);
void update(int i, int l, int r, int pos, ll va, ll vb);
void merge(int i, int lc, int rc);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		loc[p[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	ll best = inf;
	for (int x = 0; x <= n; ++x) {
		best = min(best, tree[1].best);
		if (x < n) {
			int j = loc[x + 1];
			update(1, 1, n, j, -a[j], a[j]);
		}
	}
	cout << best << '\n';
}

void build(int i, int l, int r) {
	if (l == r) {
		tree[i] = {a[l], 0, inf};
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		merge(i, lc, rc);
	}
}

void update(int i, int l, int r, int pos, ll va, ll vb) {
	if (pos < l or pos > r) {
		return;
	} else if (l == r) {
		tree[i].a_sum += va;
		tree[i].b_sum += vb;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, pos, va, vb);
		update(rc, mid + 1, r, pos, va, vb);
		merge(i, lc, rc);
	}
}

void merge(int i, int lc, int rc) {
	tree[i].a_sum = tree[lc].a_sum + tree[rc].a_sum;
	tree[i].b_sum = tree[lc].b_sum + tree[rc].b_sum;
	tree[i].best = min(tree[lc].best + tree[rc].b_sum, tree[lc].a_sum + tree[rc].best);
	tree[i].best = min(tree[i].best, tree[lc].a_sum + tree[rc].b_sum);
}