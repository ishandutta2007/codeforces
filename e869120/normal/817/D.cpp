#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
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
int n, a[1000009]; vector<pair<int, int>>Y; long long l, r; bool used[1000009];
int main() {
	cin >> n; for (int i = 1; i <= n; i++)scanf("%d", &a[i]), Y.push_back(make_pair(a[i], i));
	sort(Y.begin(), Y.end());
	QuickUnionFind U1(n + 2), U2(n + 2);
	for (int i = 0; i < Y.size(); i++) {
		long long B = Y[i].first;
		if (used[Y[i].second - 1] == true)B *= (U1.size(U1.root(Y[i].second - 1)) + 1), U1.unite(Y[i].second - 1, Y[i].second);
		if (used[Y[i].second + 1] == true)B *= (U1.size(U1.root(Y[i].second + 1)) + 1), U1.unite(Y[i].second + 1, Y[i].second);
		used[Y[i].second] = true;
		r += B;
	}
	reverse(Y.begin(), Y.end());
	for (int i = 1; i <= n; i++)used[i] = false;
	for (int i = 0; i < Y.size(); i++) {
		long long B = Y[i].first;
		if (used[Y[i].second - 1] == true)B *= (U2.size(U2.root(Y[i].second - 1)) + 1), U2.unite(Y[i].second - 1, Y[i].second);
		if (used[Y[i].second + 1] == true)B *= (U2.size(U2.root(Y[i].second + 1)) + 1), U2.unite(Y[i].second + 1, Y[i].second);
		used[Y[i].second] = true;
		l += B;
	}
	cout << r - l << endl;
	return 0;
}