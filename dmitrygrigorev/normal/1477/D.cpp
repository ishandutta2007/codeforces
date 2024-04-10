#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<set<int> > nei;

vector<int> unvisited;
vector<pair<int, int> > edges;

void dfs(int vertex) {

	int u = 0;

	vector<int> must_visit;

	while (u < unvisited.size()) {
		int W = unvisited[u];
		if (nei[vertex].count(W)) {
			u++;
			continue;
		}

		must_visit.pb(unvisited[u]);
		swap(unvisited[u], unvisited.back());
		unvisited.pop_back();
	}

	for (auto x : must_visit) {
		edges.pb(mp(vertex, x));
		dfs(x);
	}

}

vector<int> p, q;

int ptr;
int L;

vector<bool> used;
vector<vector<int> > gr;

void process(int vertex, vector<int> nei) {

	p[vertex] = ptr;
	q[vertex] = ptr + nei.size();
	int u = 0;

	for (auto x : nei) {
		p[x] = ptr + u + 1;
		q[x] = ptr + u;
		u++;
	}

	ptr += 1+nei.size();

}

int dfs2(int vertex, int root, int add_to) {

	used[vertex] = true;
	vector<int> remaining;

	for (auto to : gr[vertex]) {
		if (used[to]) continue;

		int A = -1;

		if (root && to == L && remaining.size() == 0) {
			A = vertex;
		}

		int R = dfs2(to, 0, A);
		if (R == 1) remaining.pb(to);
	}

	if (add_to != -1) remaining.pb(add_to);

	if (!remaining.size()) {
		return 1;
	}

	process(vertex, remaining);
	return 0;

}

void solve() {

	int n, m;
	cin >> n >> m;

	nei.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		nei[u].insert(v);
		nei[v].insert(u);

	}

	for (int i = 0; i < n; ++i) unvisited.pb(i);

	edges.clear();
	while (unvisited.size()) {
		int W = unvisited.back();
		unvisited.pop_back();

		dfs(W);

	}

	p.assign(n, -1);
	q.assign(n, -1);

	used.assign(n, false);
	gr.assign(n, {});

	for (auto p : edges) {
		gr[p.x].pb(p.y);
		gr[p.y].pb(p.x);
	}

	ptr = 0;

	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (gr[i].size() == 0) {
			p[i] = ptr;
			q[i] = ptr++;
			used[i] = true;
			continue;
		}

		L = gr[i].back();

		dfs2(i, 1, -1);

	}

	for (auto x : p) cout << x+1 << " ";
	cout << '\n';

	for (auto x : q) cout << x+1 << " ";
	cout << '\n';






}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}