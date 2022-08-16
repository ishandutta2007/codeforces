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

const int N = 3e5 + 10;

int tree[4 * N], sum[4 * N];

void update(int i, int l, int r, int p, int x);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> p(n + 1), q(n + 1);
	vector<int> p_inv(n + 1), q_inv(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		p_inv[p[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
		q_inv[q[i]] = i;
	}
	vector<int> ans(n + 1, 0);
	ans[1] = n;
	int i = 1;
	for (int v = n; v >= 1; --v) {
		update(1, 1, n, p_inv[v], 1);
		while (i < n) {
			update(1, 1, n, q[i], -1);
			if (tree[1] > 0) {
				ans[i + 1] = v;
				++i;
			} else {
				update(1, 1, n, q[i], 1);
				break;
			}
		}
	}
	for (int j = 1; j <= n; ++j) {
		cout << ans[j] << ' ';
	}
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		sum[i] += x;
		tree[i] = max(0, sum[i]);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		sum[i] = sum[lc] + sum[rc];
		tree[i] = max(tree[rc], sum[rc] + tree[lc]);
	}
}