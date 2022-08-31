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

const int N = 2e5 + 10;

ll a[N], tree_sum[4 * N];
int tree_max[4 * N];

void update(int i, int l, int r, int p, ll x);
ll query(int i, int l, int r, int qr);
int step_sum(int i, int l, int r, ll val);
int step_max(int i, int l, int r, ll val);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	while (q--) {
		int p, x;
		cin >> p >> x;
		update(1, 1, n, p, x - a[p]);
		a[p] = x;
		if (a[1] == 0) {
			cout << 1 << '\n';
			continue;
		}
		ll sum = 0, val = a[1];
		int ans = -1, i = 1;
		int j = step_sum(1, 1, n, 2 * val);
		// cout << val << ' ' << j << endl;
		if (j <= n and a[j] == val) {
			ans = j;
			i = n;
		}
		while (i < n) {
			i = step_max(1, 1, n, val + max(0ll, sum - 1));
			sum = query(1, 1, n, i - 1);
			val = a[i];
			if (i <= n and sum == a[i]) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
}

void update(int i, int l, int r, int p, ll x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree_sum[i] += x;
		tree_max[i] += x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		tree_sum[i] += x;
		tree_max[i] = max(tree_max[lc], tree_max[rc]);
	}
}

ll query(int i, int l, int r, int qr) {
	if (qr < l) {
		return 0;
	} else if (qr >= r) {
		return tree_sum[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, qr) + query(rc, mid + 1, r, qr);
	}
}

int step_sum(int i, int l, int r, ll val) {
	if (l == r) {
		if (tree_sum[i] == val) {
			return l;
		} else {
			return N;
		}
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (tree_sum[lc] >= val) {
			return step_sum(lc, l, mid, val);
		} else {
			return step_sum(rc, mid + 1, r, val - tree_sum[lc]);
		}
	}
}

int step_max(int i, int l, int r, ll val) {
	if (l == r) {
		if (a[l] > val) {
			 return l;
		} else {
			return l + 1;
		}
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (tree_max[lc] > val) {
			return step_max(lc, l, mid, val);
		} else {
			return step_max(rc, mid + 1, r, val);
		}
	}
}