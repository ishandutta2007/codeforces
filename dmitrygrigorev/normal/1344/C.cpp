#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > gr;
vector<vector<int> > trans;

int n;

void check_cycle() {

	vector<int> deg(n, 0);
	for (int i = 0; i < n; ++i) deg[i] = trans[i].size();

	queue<int> q;
	for (int i = 0; i < n; ++i) if (deg[i] == 0) q.push(i);
	int tot = 0;

	while (q.size()) {
		int W = q.front();
		q.pop();
		tot++;
		for (int i = 0; i < gr[W].size(); ++i) {
			int to = gr[W][i];
			deg[to]--;
			if (deg[to] == 0) q.push(to);
		}
	}

	if (tot != n) {
		cout << -1;
		exit(0);
	}

}

vector<bool> aused, bused;

void dfs(int vertex) {
	aused[vertex] = true;
	for (int i = 0; i < gr[vertex].size(); ++i) {
		int to = gr[vertex][i];
		if (aused[to]) continue;
		dfs(to);
	}
}

void dfs2(int vertex) {
	bused[vertex] = true;
	for (int i = 0; i < trans[vertex].size(); ++i) {
		int to = trans[vertex][i];
		if (bused[to]) continue;
		dfs2(to);
	}
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	gr.assign(n, {});
	trans.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].push_back(v);
		trans[v].push_back(u);
	}

	check_cycle();
	aused.assign(n, false);
	bused.assign(n, false);

	string ans;
	int res = 0;

	for (int i = 0;i < n; ++i) {
		if (aused[i] || bused[i]) {
			ans += 'E';
			dfs(i);
		dfs2(i);
			continue;
		}
		ans += 'A';
		res++;
		dfs(i);
		dfs2(i);
	}

	cout << res << "\n";
	cout << ans;





}