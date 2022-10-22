#include<bits/stdc++.h>

using namespace std;

const int N = 200200;

int n, m, s, f[N], d[N];
vector<int> e[N];

vector<int> getPath(vector<int> res, int u) {
	while (u != s) {
		res.push_back(u);
		u = f[u];
	}
	res.push_back(s);
	reverse(res.begin(), res.end());
	return res;
}

void print(vector<int> res) {
	cout << int(res.size()) << "\n";
	for (auto x : res) {
		cout << x << " ";
	}
	cout << "\n";
}

void dfs(int u, int p, int cur) {
	if (d[u] > 0) {
		assert(d[u] != cur);
		auto a = getPath({}, u);
		auto b = getPath({u}, p);

		cout << "Possible\n";
		print(a);
		print(b);
		exit(0);
	}

	f[u] = p;
	d[u] = cur;
	for (auto v : e[u]) {
		if (d[v] != cur && v != s) {
			dfs(v, u, cur);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m >> s;
	while (m--) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
	}

	for (auto u : e[s]) {
		dfs(u, s, u);
	}

	cout << "Impossible\n";

	return 0;
}