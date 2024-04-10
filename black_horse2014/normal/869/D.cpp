#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

vector<pair<int, int> > vec;
int dap, n, m;
unordered_map<int, bool> H;
int x[5], y[5], vis[5], a[5], b[5];

inline bool pre(int x, int y) {
	if (x > y) return false;
	int lx = 32 - __builtin_clz(x);
	int ly = 32 - __builtin_clz(y);
	return x == (y >> (ly - lx));
}

inline void add_path(int u, int v) {
	if (u == v) {
		vec.push_back(make_pair(u, u));
		return;
	}
	int f = u;
	while (!pre(f, v)) f /= 2;
	vec.push_back(make_pair(f, u));
	int lf = 32 - __builtin_clz(f), lv = 32 - __builtin_clz(v);
	if (f != v) vec.push_back(make_pair(v >> (lv - lf - 1), v));
}

inline int get(int f, int n) {
	int lf = 32 - __builtin_clz(f), ln = 32 - __builtin_clz(n);
	int ret = (1 << (ln - lf)) - 1;
	if (f < (n >> (ln - lf))) ret += (1 << (ln - lf));
	else if (f == (n >> (ln - lf))) ret += (n & ((1 << (ln - lf)) - 1)) + 1;
	int cur = 0;
	for (int i = 1; i <= n; i++) if (pre(f, i)) cur++;
	return ret;
}

inline int get(int f) {
	int ret = get(f, n);
	vector<int> cand;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].first == f) {
			int u = vec[i].first, v = vec[i].second;
			if (u != v) {
				int lu = 32 - __builtin_clz(u);
				int lv = 32 - __builtin_clz(v);
				int ff = v >> (lv - lu - 1);
				cand.push_back(ff);
			}
		}
		else if (pre(f, vec[i].first)) cand.push_back(vec[i].first);
	}
	H.clear();
	for (int x : cand) H[x] = 1;
	for (int x : cand) {
		int y = x, flg = 1;
		for (y /= 2; y != f; y /= 2) if (H[y]) {
			flg = 0;
			break;
		}
		if (flg) ret -= get(x, n);  	
	}
	return ret;
}

inline bool inter(pair<int, int> X, pair<int, int> Y) {
	return pre(X.first, Y.first) && pre(Y.first, X.second) || pre(Y.first, X.first) && pre(X.first, Y.second);
}

inline int calc(int s, int t) {
	int sz = vec.size(), ret = 0;
	for (int i = 0; i < sz; i++)
		for (int j = i + 1; j < sz; j++) if (inter(vec[i], vec[j])) return 0;
	for (int fs = s; fs; fs /= 2) 
		for (int ft = t; ft; ft /= 2) {
			vec.resize(sz);
			int flg = 1;
			for (int i = 0; i < vec.size(); i++) {
				if (inter(vec[i], make_pair(fs, s))) {
					flg = 0;
					break;
				}
			}
			if (!flg) continue;
			vec.push_back(make_pair(fs, s));
			for (int i = 0; i < vec.size(); i++) {
				if (inter(vec[i], make_pair(ft, t))) {
					flg = 0;
					break;
				}
			}
			if (!flg) continue;
			vec.push_back(make_pair(ft, t));
			ret = (ret + 1LL * get(fs) * get(ft)) % MOD;	
		}
	return ret;	
}
void dfs(int p) {
	if (p) {
		vec.clear();
		for (int i = 0; i < p - 1; i++) {
			int j = i + 1;
			int u = y[i], v = x[j];
			add_path(u, v);
		}
		int s = x[0], t = y[p - 1];
		dap = (dap + calc(s, t)) % MOD;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++) {
			if (vis[i]) continue;
			vis[i] = 1;
			x[p] = a[i], y[p] = b[i];
			if (j) swap(x[p], y[p]);
			dfs(p + 1);
			vis[i] = 0;
		}
}

int main() {
#ifndef ONLINE_JUDGE	
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i]) swap(a[i], b[i]);
	}
	dap = 1LL * n * n % MOD;
	dfs(0);
	cout << dap << endl;
	return 0;
}