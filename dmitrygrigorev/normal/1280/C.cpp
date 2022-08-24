#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<pair<int, int> > > data;

int a = 0, b = 0;
int n;

int dfs(int vertex, int last) {
	int q = 1;
	for (int i=0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i].first, w = data[vertex][i].second;
		if (to==last) continue;
		int sz = dfs(to, vertex);
		q += sz;

		a += (sz%2) * w;
		b += min(sz, 2*n-sz) * w;

	}

	return q;
}

void solve() {
	
	cin >> n;
	data.assign(2*n, {});
	for (int i=0; i < 2*n-1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		data[u-1].push_back({v-1, w});
		data[v-1].push_back({u-1, w});
	}


	a=0, b=0;
	dfs(0, -1);
	cout << a << " " << b << "\n";

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i=0; i < t; ++i) solve();

}