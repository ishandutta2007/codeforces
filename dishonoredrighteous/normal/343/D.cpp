#include <iostream>

#include <cmath>

#include <algorithm>

#include <vector>

using namespace std;

const int N = 5e5;

vector<vector<int>> g;
bool used[N];

int update_g(int v) {
	used[v] = true;

	int sz = 1, max_sz = 0, ind = 0;

	if (g[v].size() > 0) {
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v][i];
			if (!used[to]) {
				int sz_to = update_g(to);
				sz += sz_to;
				if (sz_to > max_sz) {
					max_sz = sz_to;
					ind = i;
				}
			}
		}

		swap(g[v][0], g[v][ind]);
	}

	return sz;
}

int pos[N];
int cur = 0;
int up[N];
int pred[N];

void build(int v, int p, int cur_up) {
	up[v] = cur_up;

	pos[v] = cur;
	cur++;

	if (g[v].size() > 0) {
		pred[v] = p;

		if (g[v][0] != p) {
			build(g[v][0], v, cur_up);
		}
		for (int i = 1; i < g[v].size(); i++) {
			int to = g[v][i];

			if (to != p) {
				build(to, v, to);
			}
		}
	}
}

int NULL_PUSH = 0;

struct segment1 {
	int val_min, l, r, push;

	segment1() : val_min(1e9), l(-1), r(-1), push(NULL_PUSH) {}
	segment1(int val_min, int l, int r) : val_min(val_min), l(l), r(r), push(NULL_PUSH) {}

	segment1 operator+(const segment1& s)const {
		return segment1(min(val_min, s.val_min), l, s.r);
	}
};
class segment_tree1 {
private:
	size_t N;
	vector<segment1> tree;

public:
	segment_tree1() = default;
	segment_tree1(const int n) : N(4 * n) {
		tree.resize(N);
		buildUp(1, 0, n - 1);
	}

	void buildUp(const int v, const int l, const int r) {
		if (l == r) {
			tree[v] = segment1(0, l, r);
			return;
		}

		int m = (l + r) / 2;
		buildUp(2 * v, l, m);
		buildUp(2 * v + 1, m + 1, r);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}

	void makePush(const int v) {
		if (tree[v].push == NULL_PUSH) {
			return;
		}

		if (v * 2 + 1 < N) {
			tree[v * 2].push = tree[v].push;
			tree[v * 2 + 1].push = tree[v].push;
		}

		tree[v].val_min = tree[v].push;
		tree[v].push = NULL_PUSH;
	}

	segment1 getUp(const int v, const int l, const int r) {
		makePush(v);

		if (tree[v].r < l || r < tree[v].l) {
			return segment1();
		}

		if (l <= tree[v].l && tree[v].r <= r) {
			return tree[v];
		}

		return getUp(v * 2, l, r) + getUp(2 * v + 1, l, r);
	}

	void updateUp(const int v, const int l, const int r, const int val) {
		makePush(v);
		if (tree[v].r < l || r < tree[v].l) {
			return;
		}

		if (l <= tree[v].l && tree[v].r <= r) {
			tree[v].push = val;
			makePush(v);
			return;
		}

		updateUp(2 * v, l, r, val);
		updateUp(2 * v + 1, l, r, val);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
};

struct segment2 {
	int val_max, l, r, push;

	segment2() : val_max(0), l(-1), r(-1), push(NULL_PUSH) {}
	segment2(int val_max, int l, int r) : val_max(val_max), l(l), r(r), push(NULL_PUSH) {}

	segment2 operator+(const segment2& s)const {
		return segment2(max(val_max, s.val_max), l, s.r);
	}
};
class segment_tree2 {
private:
	size_t N;
	vector<segment2> tree;

public:
	segment_tree2() = default;
	segment_tree2(const int n) : N(4 * n) {
		tree.resize(N);
		buildUp(1, 0, n - 1);
	}

	void buildUp(const int v, const int l, const int r) {
		if (l == r) {
			tree[v] = segment2(0, l, r);
			return;
		}

		int m = (l + r) / 2;
		buildUp(2 * v, l, m);
		buildUp(2 * v + 1, m + 1, r);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}

	void makePush(const int v) {
		if (tree[v].push == NULL_PUSH) {
			return;
		}

		if (v * 2 + 1 < N) {
			tree[v * 2].push = tree[v].push;
			tree[v * 2 + 1].push = tree[v].push;
		}

		tree[v].val_max = tree[v].push;
		tree[v].push = NULL_PUSH;
	}

	segment2 getUp(const int v, const int l, const int r) {
		makePush(v);

		if (tree[v].r < l || r < tree[v].l) {
			return segment2();
		}

		if (l <= tree[v].l && tree[v].r <= r) {
			return tree[v];
		}

		return getUp(v * 2, l, r) + getUp(2 * v + 1, l, r);
	}

	void updateUp(const int v, const int l, const int r, const int val) {
		makePush(v);
		if (tree[v].r < l || r < tree[v].l) {
			return;
		}

		if (l <= tree[v].l && tree[v].r <= r) {
			tree[v].push = val;
			makePush(v);
			return;
		}

		updateUp(2 * v, l, r, val);
		updateUp(2 * v + 1, l, r, val);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n; cin >> n;

	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int v, u; cin >> v >> u;
		v--; u--;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	update_g(0);

	build(0, 0, 0);

	segment_tree2 st1(n);
	segment_tree1 st2(n);

	int q; cin >> q;
	int time = 1;
	while (q--) {
		char c; cin >> c;

		if (c == '1') {
			int i; cin >> i;
			i--;

			st1.updateUp(1, pos[i], pos[i], time);
			time++;
		}
		else if (c == '2') {
			int v; cin >> v;
			v--;

			st2.updateUp(1, 0, 0, time);
			while (true) {
				if (pos[up[v]] > 0) {
					st2.updateUp(1, pos[up[v]], pos[v], time);
					v = pred[up[v]];
				}
				else {
					st2.updateUp(1, 0, pos[v], time);
					break;
				}
			}

			time++;
		}
		else {
			int i; cin >> i;
			i--;

			int res1 = st1.getUp(1, 0, 0).val_max;
			int res2 = st2.getUp(1, 0, 0).val_min;
			while (true) {
				if (pos[up[i]] > 0) {
					res1 = max(res1, st1.getUp(1, pos[up[i]], pos[i]).val_max);
					res2 = min(res2, st2.getUp(1, pos[up[i]], pos[i]).val_min);
					i = pred[up[i]];
				}
				else {
					res1 = max(res1, st1.getUp(1, 0, pos[i]).val_max);
					res2 = min(res2, st2.getUp(1, 0, pos[i]).val_min);
					break;
				}
			}

			if (res1 > res2) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}