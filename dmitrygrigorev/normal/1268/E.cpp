#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
	int r; int f;
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

vector<vector<pair<int, int> > > data;
vector<bool> good;
vector<int> father, tin, tout;
vector<int> gof;
int cur = 0;

void dfs(int vertex, int last) {
	father[vertex] = last;
	tin[vertex] = cur++;

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i].first, num = data[vertex][i].second;
		if (!good[num] || last == to) continue;
		gof[to] = num;
		dfs(to, vertex);
	}

	tout[vertex] = cur++;

}

bool isf(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

vector<int> get_path(int u, int v) {
	vector<int> ed;
	int t = u;
	while (!isf(u, v)) {
		ed.push_back(gof[u]);
		u = father[u];
	}

	vector<int> ted;
	while (!isf(v, t)) {
		ted.push_back(gof[v]);
		v = father[v];
	}

	reverse(ted.begin(), ted.end());
	for (int i = 0; i < ted.size(); ++i) ed.push_back(ted[i]);
	return ed;
}

int get_min(vector<int> v) {
	int index = min_element(v.begin(), v.end()) - v.begin();
	bool good = true;
	for (int i = 0; i + 1 <= index; ++i) {
		if (v[i] < v[i+1]) good = false;
	}
	for (int i = index; i + 1 < v.size();++i) {
		if (v[i] > v[i+1]) good = false;
	}
	if (!good) return -1;
	return v[index];
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	father.assign(n, -1), tin.assign(n, -1), tout.assign(n, -1), gof.assign(n, -1);

	for (int i = 0; i < n; ++i) {
		snm.push_back({1, i});
	}

	vector<pair<int, int> > edges;

	data.assign(n, {}), good.assign(m, false);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges.push_back({u, v});
	}

	reverse(edges.begin(), edges.end());

	for (int i = 0; i < m; ++i) {
		int u = edges[i].first, v = edges[i].second;
		data[u].push_back({v, i});
		data[v].push_back({u, i});
		int A = get(u), B = get(v);
		good[i] = (A!=B);
		if (A!=B) unite(A, B);
	}


	dfs(0, -1);

	vector<int> ans(n, 1);
	vector<int> edans(m);

	for (int i = 0; i < m; ++i) {
		int u = edges[i].first, v = edges[i].second;
		if (good[i]) {
			int sum = ans[u] + ans[v];
			ans[u] = sum, ans[v] = sum, edans[i] = sum;
		}
		else{
			vector<int> P = get_path(u, v);
			int W = get_min(P);
			int sum = ans[u] + ans[v];
			if (W!=-1) sum = ans[u] + ans[v] - edans[W];
			ans[u] = sum, ans[v] = sum, edans[i] = sum;
		}
	}

	for (int i = 0; i < n; ++i) cout << ans[i] - 1 << " ";



}