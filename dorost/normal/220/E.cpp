/*    In the name of GOD */

#include <bits/stdc++.h>

#define F first
#define S second
typedef long long ll;
using namespace std;
const int N = 100123, SegN = (1 << 18);
vector <int> seg[SegN];
int n, a[N], l, r;
long long inv, k;

void build (int v = 1, int tl = 0, int tr = n - 1) {
	seg[v].reserve(tr - tl + 1);
	if (tl == tr) {
		seg[v].push_back(a[tl]);
		return;
	}
	int mid = (tl + tr) >> 1;
	build(v << 1, tl, mid);
	build(v << 1 | 1, mid + 1, tr);
	int in1 = tl;
	int in2 = mid + 1;
	for (int i = 0; i < (tr - tl + 1); i++) {
		if (in1 == mid + 1) {
			seg[v].push_back(seg[v << 1 | 1][in2 - mid - 1]);
			in2++;
		} else if (in2 == tr + 1) {
			seg[v].push_back(seg[v << 1][in1 - tl]);
			in1++;
			inv += in2 - mid - 1;
		} else if (seg[v << 1][in1 - tl] <= seg[v << 1 | 1][in2 - mid - 1]) {
			seg[v].push_back(seg[v << 1][in1 - tl]);
			in1++;
			inv += in2 - mid - 1;
		} else {
			seg[v].push_back(seg[v << 1 | 1][in2 - mid - 1]);
			in2++;
		}
	}
}

int get (int l, int r, int x, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > tr || r < tl) 
		return 0;
	if (l <= tl && r >= tr) {
		return upper_bound(seg[v].begin(), seg[v].end(), x) - seg[v].begin();
	}
	int mid = (tl + tr) >> 1;
	return get (l, r, x, v << 1, tl, mid) + get (l, r, x, v << 1 | 1, mid + 1, tr);
}

bool goR() {
	if (r == n - 1)
		return false;
	if (l > r + 1) {
		r++;
		return true;
	}
	r++;
	if (r != n - 1) {
		inv -= get(r + 1, n - 1, a[r] - 1);	
	}
	if (l) {
		inv -= (l - get(0, l - 1, a[r]));
	}
	if (inv <= k) {
		if (r != n - 1)
			inv += get(r + 1, n - 1, a[r] - 1);	
		if (l)
			inv += (l - get(0, l - 1, a[r]));
		r--;
		return false;
	} else {
		return true;
	}
}

void goL() {
	if (l > r) {
		l++;
		return;
	}
	if (r != n - 1)
		inv += get(r + 1, n - 1, a[l] - 1);
	if (l)
		inv += (l - get(0, l - 1, a[l]));
	l++;
}

int32_t main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build();
	if (inv <= k) {
		cout << (ll)n * (ll)(n - 1) / 2LL;
		return 0;
	}
	ll ans = (ll)(n - 2) * (ll)(n - 1) / 2LL;
	l = 0, r = -1;
	for (int i = 0; i < n; i++) {
		while (goR()) {}
		if (l) {
			if (r == n - 1)
				ans++;
			ans -= (r - l + 1);
		}
		goL();
	}
	cout << ans;
}