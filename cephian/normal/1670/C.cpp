#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

struct uf {
	vector<int> d;
	int components;

	uf(int n) : d(n), components(n) {
		for (int i = 0; i < n; ++i) {
			d[i] = i;
		}
	}

	int id(int u) {
		if (d[u] == u)
			return u;
		return d[u] = id(d[u]);
	}

	void merge(int u, int v) {
		u = id(u);
		v = id(v);
		if(u != v) {
			d[u] = v;
			--components;
		}
	}
};

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b%2 == 1) return a * pw(a, b-1) % mod;
	ll t = pw(a, b/2);
	return t * t % mod;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), a_inv(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		//cout << a[i] << " vs " << n << endl;
		a_inv[a[i]] = i;
	}
	for (int i = 0; i < n; ++i)
		cin >> b[i], --b[i];

	uf cc(n);
	for(int i = 0; i < n; ++i)
		cc.merge(i, a_inv[b[i]]);
	set<int> fixed_id;
	for (int i = 0; i < n; ++i) {
		int d;
		cin >> d;
		if(d || a[i] == b[i]) {
			fixed_id.insert(cc.id(i));
		}
	}
	cout << pw(2, cc.components - fixed_id.size()) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}