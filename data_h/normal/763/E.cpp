#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int N = 1e5 + 7;
const int K = 5;

int n, m, k;

vector<int> adj[N];

struct State {
	vector<int> s;
	int tot;
	void reduce() {
		static int visit[N], tag = 0, mp[N];
		//assert(s.size() == 2 * k);
		++tag;
		int mc = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == -1) continue;
			if (visit[s[i]] != tag) {
				visit[s[i]] = tag;
				mp[s[i]] = mc++;
			}
			s[i] = mp[s[i]];
		}
	}
};

State tree[N << 2];

int f[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

State mergy(const State &a, const State &b, int l, int mid, int r) {
	// cout << "merge " << l << " " << mid << " " << r << endl;
	// cout << a.tot << " " << b.tot << endl << endl;
	State ret;
	ret.tot = a.tot + b.tot;
	int mc = 0;
	for (int i = 0; i < a.s.size(); i++) {
		mc = max(mc, a.s[i]);
		f[a.s[i]] = a.s[i];
	}
	++mc;
	for (int i = 0; i < b.s.size(); i++) {
		// b.s[i] += mc + 1;
		f[b.s[i] + mc] = b.s[i] + mc;
	}
	for (int u = max(l, mid - k + 1); u <= mid; u++) {
		for (int v : adj[u]) {
			if (mid < v && v <= r) {
				int uid = a.s.size() - 1 - (mid - u);
				int vid = v - mid - 1;
				int as = find(a.s[uid]), bs = find(b.s[vid] + mc);
				if (as != bs) {
					ret.tot--;
					f[as] = bs;
				}

			}
		}
	}
	for (int i = 0; i < k; i++) {
		if (i < a.s.size() / 2) {
			ret.s.push_back(find(a.s[i]));
		} else {
			int ii = i - a.s.size() / 2;
			if (ii < b.s.size() / 2) {
				ret.s.push_back(find(b.s[ii] + mc));
			}
		}
	}
	int rem = min(k - (int)b.s.size() / 2, (int)a.s.size() / 2);
	for (int i = rem - 1; i >= 0; i--) {
		ret.s.push_back(find(a.s[(int)a.s.size() - i - 1]));
	}
	for (int i = b.s.size() / 2; i < b.s.size(); i++) {
		ret.s.push_back(find(b.s[i] + mc));
	}
	ret.reduce();
	return ret;
}

void build(int x, int l, int r) {
	if (l == r) {
		tree[x].tot = 1;
		tree[x].s.push_back(0);
		tree[x].s.push_back(0);
	} else {
		int mid = (l + r) / 2;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		tree[x] = mergy(tree[x << 1], tree[x << 1 | 1], l, mid, r);
	}
}

State ask(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return tree[x];
	}
	int mid = (l + r) / 2;
	State ret;
	if (qr <= mid) {
		return ask(x << 1, l, mid, ql, qr);
	} else if (ql > mid) {
		return ask(x << 1 | 1, mid + 1, r, ql, qr);
	} else {
		ret = mergy(ask(x << 1, l, mid, ql, mid), ask(x << 1 | 1, mid + 1, r, mid + 1, qr), ql, mid, qr);
		return ret;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%d", &m);
	// n = 1000, k = 5;
	// m = 500;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);
		adj[u].push_back(v);
	}
	build(1, 1, n);
	int q;
	// puts("");
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		State s = ask(1, 1, n, l, r);
		printf("%d\n", s.tot);
	}
	return 0;
}