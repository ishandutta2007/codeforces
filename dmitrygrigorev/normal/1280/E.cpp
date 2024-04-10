#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<bool> parallel;
vector<int> father;
vector<int> spec;
vector<int> opt;
vector<ll> ans;

void dfs(int vertex) {
	if (parallel[vertex]) {
		int tot = 0;
		for (int i=0; i < data[vertex].size(); ++i) {
			int to = data[vertex][i];
			dfs(to);
			tot += opt[to];
		}

		opt[vertex] = tot;
	}
	else {
		if (spec[vertex] != -1) {
			opt[vertex] = 1;
			return;
		}
		int mn = 1e9;
		for (int i=0; i < data[vertex].size(); ++i) {
			int to = data[vertex][i];
			dfs(to);
			mn = min(mn, opt[to]);
		}
		opt[vertex] = mn;
	}

}

void dfs2(int vertex, ll need) {
	if (parallel[vertex]) {
		for (int i=0; i < data[vertex].size(); ++i) {
			int to = data[vertex][i];
			dfs2(to, need);
		}
	}
	else {
		if (spec[vertex] != -1) {
			ans[spec[vertex]] = need;
			return;
		}
		for (int i=0; i < data[vertex].size(); ++i) {
			int to = data[vertex][i];
			if (opt[to] == opt[vertex]) {
				dfs2(to, need);
				return;
			}
		}
	}
}

void solve() {

	int x;
	cin >> x;

	data = {{}}, father = {-1}, spec = {-1}, parallel = {false};
	int cur = 0, u=0;

	while (true) {
		char ch = ' ';
		while (ch == ' ') cin >> ch;
		if (ch == '(') {
			data.push_back({});
			father.push_back(cur), parallel.push_back(false), spec.push_back(-1);
			int index = data.size() - 1;

			data[cur].push_back(index);
			cur = index;
		}

		if (ch == '*') {
			data.push_back({});
			father.push_back(cur), parallel.push_back(false), spec.push_back(u++);
			int index = data.size() - 1;

			data[cur].push_back(index);
		}

		if (ch == 'P') parallel[cur] = true;
		if (ch == ')') {
			cur = father[cur];
		}
		if (cur==0) break;
	}

	ans.assign(u, 0);
	opt.assign(data.size(), -1);


	dfs(1);
	ll need = (ll) x * opt[1];
	dfs2(1, need);
	cout << "REVOLTING ";
	for (int i=0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << "\n";

}


main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i=0; i < t; ++i) solve();

}