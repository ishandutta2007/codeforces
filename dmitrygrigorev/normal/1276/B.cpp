#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

vector<bool> deleted, used;

int n, tmp, a, b, ans;

vector<pair<int, int> > pos;

int lol;

void dfs(int vertex, bool kek) {
	if (kek) pos[vertex].first = tmp;
	else pos[vertex].second = tmp;
	used[vertex] = true;
	if (vertex != a && vertex != b) lol++;
	for (int i=0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (used[to] || deleted[to] || deleted[vertex]) continue;
		dfs(to, kek);
	}
}

void calc(bool gw) {
	used.assign(n, false);

	tmp = 0;
	for (int i=0; i < n; ++i) {
		tmp++;
		lol = 0;
		if (!used[i]){
			dfs(i, gw);
			//cout << "==== " << lol << endl;
			ans -= lol*(lol-1)/2;
		}
	}

}

void solve() {
	int m;
	cin >> n >> m >> a >> b;
	a--, b--;
	deleted.assign(n, false);
	data.assign(n, {});
	pos.assign(n, make_pair(-1, -1));

	for (int i=0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v), data[v].push_back(u);
	}

	ans = (n-2)*(n-3)/2;

	deleted[a] = true;
	calc(true);
	deleted[b] = true, deleted[a] = false;
	calc(false);
	//cout << kek << " " << tet << " " << sas << endl;
	map<pair<int, int>, int> tet;
	for (int i=0; i < n; ++i) {
		if (i != a && i != b) tet[pos[i]]++;
	}

	for (auto it = tet.begin(); it != tet.end(); it++){
		int q = (*it).second;
		ans += q*(q-1)/2;
	}

	cout << ans << "\n";



}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}