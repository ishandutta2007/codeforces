#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

vector<int> tree[N << 2];
int h, w, n;

map<int, pair<int, pair<int, int> >> evts;
map<int, int> f;
unordered_set<int> del;

void build(int x, int l, int r) {
	if (l == r) {
		tree[x].push_back(0);
	} else {
		int m = (l + r) / 2;
		build(x << 1, l, m);
		build(x << 1 | 1, m + 1, r);
	}
}

int ask(int x, int l, int r, int pos) {
	int ret = 0;
	while (tree[x].size() && del.count(tree[x].back())) {
		tree[x].pop_back();
	}
	if (tree[x].size()) {
		ret = tree[x].back();
	}
	if (l == r) return ret;
	int m = (l + r) / 2;
	if (pos <= m) return max(ret, ask(x << 1, l, m, pos));
	return max(ret, ask(x << 1 | 1, m + 1, r, pos));
}

void insert(int x, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		tree[x].push_back(v);
	} else if (r < ql || qr < l) {
		return ;
	} else {
		int m = (l + r) / 2;
		insert(x << 1, l, m, ql, qr, v);
		insert(x << 1 | 1, m + 1, r, ql, qr, v);
	}
}

int main() {
	scanf("%d %d %d", &h, &w, &n);
	for (int i = 0; i < n; i++) {
		int row, l, r, v;
		scanf("%d %d %d %d", &row, &l, &r, &v);
		evts[row] = {v, {l, r}};
	}
	f[0] = 1;
	build(1, 1, w);
	set<pair<int, int> > wait;
	for (auto tt : evts) {
		int row = tt.first;
		while (wait.size() && wait.begin()->first < row) {
			del.insert(wait.begin()->second);
			wait.erase(wait.begin());
		}
		auto t = tt.second;
		int v = t.first, l = t.second.first, r = t.second.second;
		int whol = ask(1, 1, w, l == 1 ? r + 1 : l - 1),
			whor = ask(1, 1, w, r == w ? l - 1 : r + 1);
		f[row] = (f[whol] + f[whor]) % MOD;
		insert(1, 1, w, l, r, row);
		wait.insert({row + v, row});
	}
	while (wait.size() && wait.begin()->first < h + 1) {
		del.insert(wait.begin()->second);
		wait.erase(wait.begin());
	}
	int ans = 0;
	for (int c = 1; c <= w; c++) {
		int id = ask(1, 1, w, c);
		(ans += f[id]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}