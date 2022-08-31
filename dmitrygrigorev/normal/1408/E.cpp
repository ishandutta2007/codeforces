#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Edge {
	int w;
	int u;
	int v;
};

bool cmp(Edge &a, Edge &b) {
	return (a.w > b.w);
}

struct Vertex {
	int f;
	int r;
};
 
vector<Vertex> snm;
 
int get(int v) {
 
	if (snm[v].f != v) snm[v].f = get(snm[v].f);
	return snm[v].f;
}
 
void unite(int u, int v) {
 
	if (snm[u].r > snm[v].r) swap(u, v);
 
	snm[u].f = v;
	if (snm[u].r == snm[v].r) snm[v].r++;
 
}

main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<int> a(m);
	vector<int> b(n);

	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector<Edge> arr;
	for (int i = 0; i < m; ++i) {
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; ++j) {
			int x;
			cin >> x;
			x--;
			arr.pb({a[i] + b[x], i, x + m});
		}
	}

	sort(all(arr), cmp);
	int ans = 0;

	for (int i = 0; i < n+m; ++i) {
		snm.pb({i, 1});
	}

	for (auto x : arr) {
		int a = get(x.u);
		int b = get(x.v);

		if (a==b) {
			ans += x.w;
		}

		else unite(a, b);

	}

	cout << ans;


}