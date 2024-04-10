#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 2e18;

const int N = 1100000;

ll qx[N];

struct line{
	ll x, y;
	line (ll x = 0, ll y = 0) : x(x), y(y) {}
	ll getValue(int k) { return x * qx[k] + y; }
} L[N];

void add(int u, int l, int r, line li) {
	int m = l + r >> 1;
	bool mid = L[u].getValue(m) < li.getValue(m);
	bool lft = L[u].getValue(l) < li.getValue(l);
	if (mid) swap(L[u], li);
	if (r - l == 1) return;
	if (mid == lft) add(u+u+1, m, r, li);
	else add(u+u, l, m, li);
}

ll get(int u, int l, int r, int x) {
	int m = l + r >> 1;
	ll ret = L[u].getValue(x);
	if (r - l == 1) return ret;
	if (x < m) return max(ret, get(u+u, l, m, x));
	return max(ret, get(u+u+1, m, r, x));
}

ll a[N], s[N], t[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
		t[i] = t[i-1] + a[i] * i;
		qx[i-1] = s[i];
	}
	ll ans = 0;
	sort(qx, qx + n);
	int qn = unique(qx, qx + n) - qx;
	for (int i = 1; i <= n; i++) {
		add(1, 0, qn, line(-i, s[i]*i-t[i]));
		ans = max(ans, t[i] + get(1, 0, qn, lower_bound(qx, qx+qn, s[i]) - qx));
	}
	cout << ans << endl;
}