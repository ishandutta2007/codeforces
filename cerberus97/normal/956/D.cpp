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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

map<ld, int> mp;
int x[N], v[N], tree[4 * N];
pair<ld, ld> t[N];

void update(int i, int l, int r, int p);
int query(int i, int l, int r, int ql, int qr);

int main() {
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> v[i];
		t[i].first = abs(ld(x[i]) / (v[i] - w));
		t[i].second = -abs(ld(x[i]) / (v[i] + w));
		mp[-t[i].second];
	}
	sort(t + 1, t + 1 + n);
	int ctr = 0;
	for (auto &i : mp) {
		i.second = ++ctr;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cout.precision(5);
		ans += query(1, 1, ctr, mp[-t[i].second], ctr);
		update(1, 1, ctr, mp[-t[i].second]);
	}
	cout << ans;
}


void update(int i, int l, int r, int p) {
	++tree[i];
	if (l == r) {
		return;
	} else {
		int mid = (l + r) / 2;
		if (p <= mid) {
			update(2 * i, l, mid, p);
		} else {
			update(2 * i + 1, mid + 1, r, p);
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
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}