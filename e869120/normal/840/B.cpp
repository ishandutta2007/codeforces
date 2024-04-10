#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class QuickUnionFind {
private:
	int size_; std::vector<int> g; std::vector<std::vector<int> > v;
public:
	QuickUnionFind() : size_(0), g(std::vector<int>()), v(std::vector<std::vector<int> >()) {};
	QuickUnionFind(int size__) : size_(size__) {
		g.resize(size_); v.resize(size_);
		for (int i = 0; i < size_; i++) g[i] = i, v[i] = { i };
	};
	int size() { return size_; }
	int root(int x) { return g[x]; }
	int size(int x) { return v[x].size(); }
	bool same(int x, int y) { return g[x] == g[y]; }
	void unite(int x, int y) {
		x = g[x], y = g[y];
		if (x == y) return;
		if (v[x].size() < v[y].size()) std::swap(x, y);
		v[x].insert(v[x].end(), v[y].begin(), v[y].end());
		for (auto &e : v[y]) g[e] = x;
		v[y].clear();
	}
	std::vector<int> connected(int x) { return v[g[x]]; }
	bool operator==(const QuickUnionFind& u) { return g == u.g; }
	bool operator!=(const QuickUnionFind& u) { return g != u.g; }
};
int n, m, a[310000], b[310000], c[310000]; vector<pair<int, int>>x[310000]; bool used[310000]; vector<int>I;
int dfs(int pos, int par) {
	used[pos] = true;
	int sum = 0;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i].first] == false)sum += dfs(x[pos][i].first, x[pos][i].second);
	}
	if (par == -1)return sum % 2;
	if (a[pos] == -1 || sum % 2 == a[pos])return 0;
	I.push_back(par);
	return 1;
}
int main() {
	cin >> n >> m; int Y = -1, s = 0;
	for (int i = 1; i <= n; i++) { cin >> a[i]; if (a[i] == -1) { Y = i; a[i] = 0; } else s += a[i]; }
	s %= 2;
	if (s == 1) {
		if (Y == -1) { cout << "-1" << endl; return 0; }
		else a[Y] = s;
	}
	for (int i = 0; i < m; i++) { cin >> b[i] >> c[i]; }
	bool flag = false;
	QuickUnionFind UF(n + 1);
	for (int i = 0; i < m; i++) {
		int T = i;
		if (UF.same(b[T], c[T]) == false) {
			UF.unite(b[T], c[T]);
			x[b[T]].push_back(make_pair(c[T], T)); x[c[T]].push_back(make_pair(b[T], T));
		}
	}
	int R = dfs(1, -1);
	sort(I.begin(), I.end());
	if (R == a[1]) {
		cout << I.size() << endl;
		for (int j = 0; j < I.size(); j++) { cout << I[j] + 1 << endl; }
		flag = true;
	}
	if (flag == false)cout << "-1" << endl;
	return 0;
}