#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define int long long

const int N = (int)3e5 + 7;
const int INF = (int)1e18 + 7;
const int NOTHING = INF + 777;
int n, gain, d[N], c[N], gap[N], pref[N], nxt[N];

int getbig(int l, int r) {
	int big = 0;
	for (int i = l; i < r; i++) {
		big = max(big, gap[i]);
	}
	return big;
}

int amax[4 * N];
int smax[4 * N];
int lazy[4 * N];

void build(int v, int tl, int tr) {
	lazy[v] = NOTHING;
	if (tl == tr) {
		amax[v] = pref[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);
		amax[v] = max(amax[2 * v], amax[2 * v + 1]);
	}
}

void push(int v, int tl, int tr) {
	if (lazy[v] != NOTHING) {
		smax[v] = lazy[v] + amax[v];
		if (tl < tr) {
			lazy[2 * v] = lazy[2 * v + 1] = lazy[v];
		}
		lazy[v] = NOTHING;
	}
}

void replace(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (tr < l || r < tl) return;
	if (l <= tl && tr <= r) {
		lazy[v] = x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) / 2;
	replace(2 * v, tl, tm, l, r, x);
	replace(2 * v + 1, tm + 1, tr, l, r, x);
	smax[v] = max(smax[2 * v], smax[2 * v + 1]);
}

void replace(int l, int r, int x) {
	if (l > r) return;
	replace(1, 1, n, l, r, x);
}

int getmax() {
	push(1, 1, n);
	return smax[1];
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> gain;
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> c[i];
		pref[i] = pref[i - 1] - c[i] + gain;
	}
	for (int i = 1; i < n; i++) {
		gap[i] = d[i + 1] - d[i];
		gap[i] *= gap[i];
	}
	vector<int> stk;
	for (int i = n; i >= 1; i--) {
		while (!stk.empty() && gap[i] >= gap[stk.back()]) stk.pop_back();
		if (stk.empty()) {
			nxt[i] = -1;
		}
		else {
			nxt[i] = stk.back();
		}
		stk.push_back(i);
	}
	build(1, 1, n);
	replace(1, n, -INF);
	vector<pair<int, int>> segs;
	int print = 0;
	for (int l = n; l >= 1; l--) {
		replace(l + 1, nxt[l] == -1 ? n : nxt[l], -gap[l]);
		print = max(print, max(pref[l], getmax()) - pref[l - 1]);
	}
	cout << print << "\n";
}