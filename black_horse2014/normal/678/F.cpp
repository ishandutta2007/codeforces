#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 2e18;
const int N = 1400000;

struct line{
	ll a, b;
	line(ll a = 0, ll b = -inf) : a(a), b(b) {}
	ll getValue(ll x) { return a * x + b; }
} L[N];

int qx[N];

void add(int u, int l, int r, line li) {
	int m = l + r >> 1;
	bool lef = L[u].getValue(qx[l]) < li.getValue(qx[l]);
	bool mid = L[u].getValue(qx[m]) < li.getValue(qx[m]);
	if (mid) swap(L[u], li);
	if (r - l == 1) return;
	if (lef == mid) add(u+u+1, m, r, li);
	else add(u+u, l, m, li);
}

ll get(int u, int l, int r, int i) {
	ll ret = L[u].getValue(qx[i]);
	int m = l + r >> 1;
	if (r - l == 1) return ret;
	if (i < m) return max(ret, get(u+u, l, m, i));
	return max(ret, get(u+u+1, m, r, i));
}

int type[N], a[N], b[N], nxt[N], prv[N];
ll ans[N];

void solve(int l, int r) {
	int m = l + r >> 1;
	if (r - l > 1) {
		solve(l, m);
		solve(m, r);
	}
	int qn = 0;
	for (int i = m; i < r; i++) {
		if (type[i] == 3) qx[qn++] = a[i];
	}
	if (!qn) return;
	sort(qx, qx + qn);
	qn = unique(qx, qx + qn) - qx;
	for (int i = 0; i <= (qn<<2); i++) L[i] = line(0, -inf);
	for (int i = l; i < m; i++) {
		if (type[i] == 1 && nxt[i] >= r) add(1, 0, qn, line(a[i], b[i]));
	}
	for (int i = r-1; i >= m; i--) {
		if (type[i] == 2 && l <= prv[i] && prv[i] < m) {
			add(1, 0, qn, line(a[prv[i]], b[prv[i]]));
		}
		if (type[i] == 3) {
			ans[i] = max(ans[i], get(1, 0, qn, lower_bound(qx, qx + qn, a[i]) - qx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) nxt[i] = n+1;
	for (int i = 1; i <= n; i++) {
		cin >> type[i];
		if (type[i] == 1) cin >> a[i] >> b[i];
		if (type[i] == 2) {
			cin >> prv[i];
			nxt[prv[i]] = i;
		}
		if (type[i] == 3) cin >> a[i];
		ans[i] = -inf;
	}
	solve(1, n+1);
	for (int i = 1; i <= n; i++) {
		if (type[i] == 3) {
			if (ans[i] == -inf) cout << "EMPTY SET" << endl;
			else cout << ans[i] << endl;
		}
	}
}