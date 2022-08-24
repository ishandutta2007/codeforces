#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> d;
vector<vector<int> > gr;

void dfs(int vertex, int last, int h) {
	d[vertex] = h;

	for (auto to : gr[vertex]) {
		if (to==last) continue;
		dfs(to, vertex, h+1);
	}

}

void solve() {

	int n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	a--, b--;

	gr.assign(n, {});
	d.assign(n, -1);

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].pb(v);
		gr[v].pb(u);
	}

	dfs(a, -1, 0);
	if (d[b] <= x) {
		cout << "Alice\n";
		return;
	}

	int mx = -1, wh = -1;
	for (int i = 0; i < n;++i) {
		if (d[i] > mx) {
			mx = d[i];
			wh = i;
		}
	}

	dfs(wh, -1, 0);
	mx = -1;

	for (auto res : d) mx = max(mx, res);

	y = min(y, mx);

	if (2*x < y) cout << "Bob\n";
	else cout << "Alice\n";

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}