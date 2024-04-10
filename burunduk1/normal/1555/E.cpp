/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

struct RangeTree {
	vector<int> v, a;
	int n;
	RangeTree(int n) : v(2 * n), a(2 * n), n(n) { }
	int getmin() {
		return v[1];
	}
	void change(int i, int d) {
		a[i] += d, v[i] += d;
		for (i /= 2; i; i /= 2)
			v[i] = min(v[2 * i], v[2 * i + 1]) + a[i];
	}
	void add(tuple<int, int, int> t, int d) {
		auto [w, l0, r0] = t;
		for (int l = l0 + n, r = r0 + n; l < r; l /= 2, r /= 2) {
			if (l % 2 == 1) change(l++, d);
			if (r % 2 == 1) change(--r, d);
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> segs;
	forn(i, n) {
		int l, r, w;
		cin >> l >> r >> w, l--, r--;
		segs.push_back({w, l, r});
	}
	sort(all(segs));

	int r = 0, ans = INT_MAX;
	RangeTree t(m - 1);
	forn(l, n) {
		while (r < n && t.getmin() == 0)
			t.add(segs[r++], 1);
		if (t.getmin() == 0)
			break;
		// printf("l=%d r=%d\n", l, r);
		ans = min(ans, get<0>(segs[r - 1]) - get<0>(segs[l]));
		t.add(segs[l], -1);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn = 1;
	// cin >> tn;
	while (tn--)
		solve();
}