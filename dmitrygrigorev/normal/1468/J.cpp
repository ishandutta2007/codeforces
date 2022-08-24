#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
	int f;
	int r;
};

vector<Vertex> snm;

int get(int v) {
	if (snm[v].f != v) {
		snm[v].f = get(snm[v].f);
	}
	return snm[v].f;
}

void unite(int u, int v) {
	if (snm[u].r > snm[v].r) swap(u, v);
	snm[u].f = v;

	if (snm[u].r == snm[v].r) snm[v].r++;

}

void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	snm.clear();
	for (int i = 0; i < n; ++i) snm.pb({i, 1});

	vector<tuple<int, int, int> > edges(m);	

	for (auto &x : edges) cin >> get<2>(x) >> get<1>(x) >> get<0>(x);

	sort(all(edges));

	vector<int> weights;

	for (auto x : edges) {
		int u = get<1>(x) - 1, v = get<2>(x) - 1;
		int p1 = get(u), p2 = get(v);

		if (p1==p2) continue;
		weights.pb(get<0>(x));

		unite(p1, p2);

	}

	if (weights.back() >= k) {
		int ans = 0;
		for (auto x : weights) ans += max(0LL, x - k);

		cout << ans << '\n';
	}

	else {
		int ans = 1e18;
		for (auto x : edges) {
			ans = min(ans, abs(k - get<0>(x)));
		}
		cout << ans << '\n';
	}

}

main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}