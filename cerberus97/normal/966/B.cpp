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

const int N = 3e5 + 10;

struct server {
	ll c, num, den;
	int ind;
	bool operator<(const server &other) {
		return c < other.c;
	}
} s[N];

void update(int i, int l, int r, int p);
int query(int i, int l, int r, int ql, int qr);
bool lt(int i, int j);

int tree[4 * N];

int main() {
	fast_cin();
	int n; ll x1, x2;
	cin >> n >> x1 >> x2;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].c;
		s[i].ind = i;
	}
	sort(s + 1, s + 1 + n);
	for (int i = 1; i <= n; ++i) {
		s[i].num = s[i].c * (n - i) - x2;
		s[i].den = s[i].c;
	}
	int good = 0;
	for (int i = n; i >= 1; --i) {
		if (x2 <= s[i].c * (n - i + 1)) {
			good = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		update(1, 1, n, i);
	}
	int l = n + 1, r = l, ans = n + 1;
	for (int k1 = 1; k1 < n; ++k1) {
		while (l > 1 and (x1 <= s[l - 1].c * k1)) {
			--l;
		}
		r = l + k1 - 1;
		if (r <= n) {
			if (good > r) {
				ans = good;
				break;
			} else if (l > 1) {
				int i = query(1, 1, n, 1, l - 1);
				if (s[i].num >= (r - l) * s[i].den) {
					ans = i;
					break;
				}
			}
		}
	}
	if (ans == n + 1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		int k1 = r - l + 1;
		int k2 = n - ans + 1;
		if (ans < l) {
			k2 -= k1;
		}
		cout << k1 << ' ' << k2 << endl;
		for (int i = l; i <= r; ++i) {
			cout << s[i].ind << ' ';
		}
		cout << endl;
		for (int i = ans; i <= n; ++i) {
			if (i == l) {
				i = r + 1;
				if (i > n) {
					break;
				}
			}
			cout << s[i].ind << ' ';
		}
		cout << endl;
	}
}

void update(int i, int l, int r, int p) {
	if (l == r) {
		tree[i] = p;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (p <= mid) {
			update(lc, l, mid, p);
			if (lt(tree[i], tree[lc])) {
				tree[i] = tree[lc];
			}
		} else {
			update(rc, mid + 1, r, p);
			if (lt(tree[i], tree[rc])) {
				tree[i] = tree[rc];
			}
		}
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		int p1 = query(lc, l, mid, ql, qr);
		int p2 = query(rc, mid + 1, r, ql, qr);
		if (lt(p1, p2)) {
			return p2;
		} else {
			return p1;
		}
	}
}

bool lt(int i, int j) {
	if (i == 0) {
		return true;
	} else if (j == 0) {
		return false;
	} else {
		return (s[i].num * s[j].den < s[j].num * s[i].den);
	}
}