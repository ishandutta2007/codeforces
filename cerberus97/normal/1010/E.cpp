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

const int N = 1e5 + 10, inf = 1e5 + 10;

struct Query {
	int x, y, z, ind;
	bool operator<(const Query &o) const {
		return x < o.x;
	}
} q[N];

vector<pii> pts[N];
multiset<int> tree[4 * N];
string ans[N];

bool good(int x, int x1, int x2);
void insert(int i, int l, int r, int x, int y);
void del(int i, int l, int r, int x, int y);
bool query(int i, int l, int r, int x1, int x2, int y1, int y2);

int main() {
	fast_cin();
	int X, Y, Z, n, m, k;
	cin >> X >> Y >> Z >> n >> m >> k;
	int x1, x2, y1, y2, z1, z2;
	x1 = y1 = z1 = inf;
	x2 = y2 = z2 = -1;
	for (int i = 1; i <= n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		x1 = min(x1, x);
		x2 = max(x2, x);
		y1 = min(y1, y);
		y2 = max(y2, y);
		z1 = min(z1, z);
		z2 = max(z2, z);
	}
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (good(x, x1, x2) and good(y, y1, y2) and good(z, z1, z2)) {
			cout << "INCORRECT";
			return 0;
		}
		pts[x].pb({y, z});
	}
	cout << "CORRECT\n";
	for (int i = 1; i <= k; ++i) {
		cin >> q[i].x >> q[i].y >> q[i].z;
		q[i].ind = i;
	}
	sort(q + 1, q + 1 + k);
	for (int x = 1; x <= x2; ++x) {
		for (auto &p : pts[x]) {
			insert(1, 1, Y, p.first, p.second);
		}
	}
	int j = 1, r = x2;
	for (int i = 1; i <= k; ++i) {
		if (good(q[i].x, x1, x2) and good(q[i].y, y1, y2) and good(q[i].z, z1, z2)) {
			ans[q[i].ind] = "OPEN";
			continue;
		}
		while (j < q[i].x and j < x1) {
			for (auto &p : pts[j]) {
				del(1, 1, Y, p.first, p.second);
			}
			++j;
		}
		while (r < q[i].x) {
			++r;
			for (auto &p : pts[r]) {
				insert(1, 1, Y, p.first, p.second);
			}
		}
		if (query(1, 1, Y, min(q[i].y, y1), max(q[i].y, y2), min(q[i].z, z1), max(q[i].z, z2))) {
			ans[q[i].ind] = "CLOSED";
		} else {
			ans[q[i].ind] = "UNKNOWN";
		}
	}
	for (int i = 1; i <= k; ++i) {
		cout << ans[i] << '\n';
	}
}

bool good(int x, int x1, int x2) {
	return x1 <= x and x <= x2;
}

void insert(int i, int l, int r, int x, int y) {
	tree[i].insert(y);
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	if (x <= mid) {
		insert(lc, l, mid, x, y);
	} else {
		insert(rc, mid + 1, r, x, y);
	}
}

void del(int i, int l, int r, int x, int y) {
	tree[i].erase(tree[i].find(y));
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	if (x <= mid) {
		del(lc, l, mid, x, y);
	} else {
		del(rc, mid + 1, r, x, y);
	}
}

bool query(int i, int l, int r, int x1, int x2, int y1, int y2) {
	if (l > x2 or r < x1) {
		return false;
	} else if (x1 <= l and r <= x2) {
		return tree[i].lower_bound(y1) != tree[i].end() and (*(tree[i].lower_bound(y1))) <= y2;
	}
	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	return query(lc, l, mid, x1, x2, y1, y2) or query(rc, mid + 1, r, x1, x2, y1, y2);
}