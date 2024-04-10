#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n, a[300000], b[300000], c[300000]; bool used[300000];
class QuickUnionFind {
private:
	long long size_; std::vector<long long> g; std::vector<std::vector<long long> > v; std::vector<long long> d;
public:
	QuickUnionFind() : size_(0), g(std::vector<long long>()), v(std::vector<std::vector<long long> >()), d(std::vector<long long>()) {};
	QuickUnionFind(long long size__) : size_(size__) {
		g.resize(size_); v.resize(size_); d.resize(size_);
		for (long long i = 0; i < size_; i++) { g[i] = i, v[i] = { i }; d[i] = 0; }
	};
	long long size() { return size_; }
	long long root(long long x) { return g[x]; }
	long long size(long long x) { return d[root(x)]; }
	bool same(long long x, long long y) { return g[x] == g[y]; }
	void unite(long long x, long long y) {
		x = g[x], y = g[y];
		if (x == y) return;
		if (v[x].size() < v[y].size()) std::swap(x, y);
		d[root(x)] += d[root(y)];
		v[x].insert(v[x].end(), v[y].begin(), v[y].end());
		for (auto &e : v[y]) g[e] = x;
		v[y].clear();
	}
	void repair(long long x) {
		d[x] += a[x];
		if (x - 1 >= 0 && used[x - 1] == true) { unite(x - 1, x); }
		if (x + 1 <= size_ && used[x + 1] == true) { unite(x, x + 1); }
		used[x] = true;
	}
	std::vector<long long> connected(long long x) { return v[g[x]]; }
	bool operator==(const QuickUnionFind& u) { return g == u.g; }
	bool operator!=(const QuickUnionFind& u) { return g != u.g; }
};
int main() {
	cin >> n;
	for (long long i = 0; i < n; i++)cin >> a[i];
	for (long long i = 0; i < n; i++) { cin >> b[i]; b[i]--; }
	QuickUnionFind UF(n);
	long long maxn = 0;
	for (long long i = n - 1; i >= 0; i--) {
		c[i] = maxn;
		UF.repair(b[i]); maxn = max(maxn, UF.size(b[i]));
	}
	for (long long i = 0; i < n; i++)cout << c[i] << endl;
	return 0;
}