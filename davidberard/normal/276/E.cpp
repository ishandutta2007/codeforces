#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct BIT {
	vector<int> t;
	int n;
	void add(int x, int v) {
		for(; x<n; x+=x&-x) {
			t[x] += v;
		}
	}
	BIT(int sz) {
		t = vector<int>(sz);
		n = sz;
	}
	void add(int l, int r, int v) {
		add(l, v);
		add(r, -v);
	}
	int query(int x) {
		int ans = 0;
		for (; x; x-=x&-x) {
			ans += t[x];
		}
		return ans;
	}
};

const int N = 100100;
vector<BIT> bits;
vector<int> adj[N];
int my_bit[N], my_ind[N], n, q;

int dfs(int u, int p, int bit_ind, int ind) {
	my_bit[u] = bit_ind;
	my_ind[u] = ind;
	int res = ind;
	for (auto& v : adj[u]) {
		if (v == p) continue;
		res = dfs(v, u, bit_ind, ind+1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
  int u, v;
	for (int i=1; i<=n-1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bits.emplace_back(1);
	int mx = 5;
	for (int v : adj[1]) {
		int amt = dfs(v, 1, bits.size(), 2);
		bits.emplace_back(amt+5);
		mx = max(mx, amt+5);
	}

	BIT all(mx);
	my_ind[1] = 1;

	for (int qq=0; qq<q; ++qq) {
		int type;
		cin >> type;
		if (type == 0) {
			int x, d;
			cin >> u >> x >> d;
			if (u == 1) {
				all.add(1, 2+d, x);
			} else {
				int extra = 0;
				int lo = my_ind[u]-d;
				int hi = my_ind[u]+d+1;
				if (lo < 2) {
					extra = 2-lo;
					lo = extra+1;
				}
				bits[my_bit[u]].add(lo, hi, x);
				if (extra) {
					all.add(1, extra+1, x);
				}
			}
		} else if (type == 1) {
			cin >> u;
			int res = all.query(my_ind[u]);
			if (u != 1) {
				assert(my_ind[u] > 1);
				res += bits[my_bit[u]].query(my_ind[u]);
			}
			cout << res << "\n";
		}
	}
	return 0;
}