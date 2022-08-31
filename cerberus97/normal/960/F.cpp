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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, W = 1e5 + 10, X = 5e6;

int tree[N], u[N], v[N], w[N];
int val[X], lc[X], rc[X], nxt = 1;

void update(int cur, int l, int r, int p, int x);
int query(int cur, int l, int r, int x);
int get_node();

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		tree[i] = get_node();
	}
	for (int i = 1; i <= m; ++i) {
		cin >> u[i] >> v[i] >> w[i];
	}
	int best = 0;
	for (int i = 1; i <= m; ++i) {
		int temp = query(tree[u[i]], 0, W, w[i] - 1) + 1;
		best = max(best, temp);
		update(tree[v[i]], 0, W, w[i], temp);
	}
	cout << best;
}

void update(int cur, int l, int r, int p, int x) {
	val[cur] = max(val[cur], x);
	if (l < r) {
		int mid = (l + r) / 2;
		if (p <= mid) {
			if (!lc[cur]) {
				lc[cur] = get_node();
			}
			update(lc[cur], l, mid, p, x);
		} else {
			if (!rc[cur]) {
				rc[cur] = get_node();
			}
			update(rc[cur], mid + 1, r, p, x);
		}
	}
}

int query(int cur, int l, int r, int x) {
	if (l > x) {
		return 0;
	} else if (r <= x) {
		return val[cur];
	}
	int mid = (l + r) / 2, ans = 0;
	if (!lc[cur]) {
		lc[cur] = get_node();
	}
	if (!rc[cur]) {
		rc[cur] = get_node();
	}
	ans = max(ans, query(lc[cur], l, mid, x));
	ans = max(ans, query(rc[cur], mid + 1, r, x));
	return ans;
}

int get_node() {
	return nxt++;
}