#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000000;
const ll inf = 2e18;

ll qx[N], a[N], s[N];

struct line{
	ll a, b;
	line (ll a = 0, ll b = -inf) : a(a), b(b) {}
	ll getValue(int idx) {
		return a * qx[idx] + b;
	}
} L[N];

void add(int u, int l, int r, line li) {
	int m = l + r >> 1;
	bool mid = L[u].getValue(m) < li.getValue(m);
	bool lft = L[u].getValue(l) < li.getValue(l);
	if (mid) swap(L[u], li);
	if (r - l == 1) return;
	if (mid == lft) add(u + u + 1, m, r, li);
	else add(u + u, l, m, li);
}

ll get(int u, int l, int r, int i) {
	ll ret = L[u].getValue(i);
	if (r - l == 1) return ret;
	int m = l + r >> 1;
	if (i < m) return max(ret, get(u+u, l, m, i));
	return max(ret, get(u+u+1, m, r, i));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qx[i-1] = a[i];
	}
	sort(qx, qx+n);
	int qn = unique(qx, qx+n) - qx;
	ll normal = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
		normal += a[i] * i;
	}
	for (int i = n; i >= 1; i--) {
		add(1, 0, qn, line(i, -s[i]));
		ans = max(ans, get(1, 0, qn, lower_bound(qx, qx+qn, a[i]) - qx) + s[i] - i*a[i]);
	}
	for (int i = 0; i < N; i++) L[i] = line(0, -inf);
	for (int i = 1; i <= n; i++) {
		add(1, 0, qn, line(i, -s[i-1]));
		ans = max(ans, get(1, 0, qn, lower_bound(qx, qx+qn, a[i]) - qx) + s[i-1] - i*a[i]);
	}
	cout << ans + normal << endl;
}