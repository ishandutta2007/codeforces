#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 300100;
const int M = 4;
const int MOD = 998244353;
array<int, M> ID;

int binpow(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}   
	return res % MOD;
}

void debug(array<int, M> x) {
	for(int i = 0; i < M; i++) cout << x[i] << ',';
	cout << '\n';
}

template <typename T>
class SegTree {
public:
	vector <T> tree;
	

	SegTree(int size) {
		tree.resize(4*size, ID);
	}

	T func(T a, T b) {
		if(a[0] == MOD) return b;
		if(b[0] == MOD) return a;
		T x = ID;
		x[0] = (a[0]*b[0]) + (a[1]*b[2]);
		x[1] = (a[0]*b[1]) + (a[1]*b[3]);
		x[2] = (a[2]*b[0]) + (a[3]*b[2]);
		x[3] = (a[2]*b[1]) + (a[3]*b[3]);
		for(int i = 0; i < 4; i++) x[i] %= MOD;
		// debug(a); debug(b); debug(x);
		return x;
	}

	void assign(int node, int val) {
		if(val == 0) {
			tree[node][0] = 3;
			tree[node][1] = 0;
			tree[node][2] = 1;
			tree[node][3] = 2;
		} else {
			tree[node][0] = 1;
			tree[node][1] = 2;
			tree[node][2] = 1;
			tree[node][3] = 2;
		}
	}

	void build(int node, int start, int end, vector <int> &v) {
		if(start == end) {
			assign(node, v[start]);
		} else {
			int mid = (start + end)/2;
			build(2*node, start, mid, v);
			build(2*node + 1, mid + 1, end, v);
			tree[node] = func(tree[node*2], tree[node*2 + 1]);
		}
	}

	void update(int node, int start, int end, int pos, int val) {
		if(start == end) {
			assign(node, val);
		} else {
			int mid = (start + end)/2;
			if(pos <= mid) {
				update(node*2, start, mid, pos, val);
			} else {
				update(node*2 + 1, mid + 1, end, pos, val);
			}
			tree[node] = func(tree[node*2], tree[node*2 + 1]);
		}
	}

	T query(int node, int start, int end, int l, int r) {
		if(l > r) {
			return ID; // Return appropriate value, for example INF for minimum.
		}
		if(l == start && r == end) {
			return tree[node];
		}
		int mid = (start + end)/2;
		return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
	}
};

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ID[0] = ID[1] = ID[2] = ID[3] = MOD;

	int t = 1;
	#ifdef LOCAL
		cin >> t;
	#endif
	while(t--) {
		int n;
		cin >> n;
		SegTree<array<int, 4>> st(N);
		vector<vector<int>> add(N);
		vector<vector<int>> rem(N);
		for(int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			add[l].push_back(i + 1);
			rem[r].push_back(i + 1);
		}
		for(int i = 0; i < N; i++) st.update(1, 0, N - 1, i, 0);
		int ans = 0;
		vector<int> z(N, 0);
		for(int i = 0; i < N; i++) {
			for(auto j : add[i]) {
				st.update(1, 0, N - 1, j, 1);
				z[j]++;
			}
			auto x = st.query(1, 0, N - 1, 2, n);
			// cout << i << ' ' << x[1] << '\n';
			if(z[1] == 1) ans = (ans + x[3]) % MOD;
			else ans = (ans + x[1]) % MOD;
			for(auto j : rem[i]) {
				st.update(1, 0, N - 1, j, 0);
				z[j]--;
			}
		}
		// ans = (ans * binpow(3, MOD - 2)) % MOD;
		cout << ans << '\n';
		// cout << "F\n\n";
		// for(auto j : add[1]) st.update(1, 0, N - 1, j, 1);
		// cout << "F\n\n";
		// // cout << st.query(1, 0, N - 1, 1, 4)[0] << '\n';
		// debug(st.query(1, 0, N - 1, 2, 3));
		// debug(st.query(1, 0, N - 1, 4, 4));
		// debug(st.query(1, 0, N - 1, 1, 1));
	}
	
	return 0;
}