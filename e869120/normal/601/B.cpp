#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class UnionFind {
private:
	unsigned size_; std::vector<unsigned> par, rank, sizes;
public:
	UnionFind() : size_(0), par(std::vector<unsigned>()), rank(std::vector<unsigned>()), sizes(std::vector<unsigned>()) {};
	UnionFind(unsigned size__) : size_(size__) {
		par.resize(size_); rank.resize(size_); sizes.resize(size_);
		for (unsigned i = 0; i < size_; i++) par[i] = i, rank[i] = 0, sizes[i] = 1;
	}
	unsigned size() { return size_; }
	unsigned root(unsigned x) { return par[x] == x ? x : par[x] = root(par[x]); }
	unsigned sizeq(unsigned x) { return sizes[x]; }
	bool same(unsigned x, unsigned y) { return root(x) == root(y); }
	void unite(unsigned x, unsigned y) {
		x = root(x), y = root(y); 
		if (x == y) return;
		unsigned G = sizes[x] + sizes[y]; sizes[x] = G; sizes[y] = G;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const UnionFind &u) { return par == u.par; }
	bool operator!=(const UnionFind &u) { return par != u.par; }
};
long long n, q, a[100009]; vector<pair<long long, long long>>Z; bool used[100009];
long long query(long long l, long long r) {
	UnionFind UF(n + 1); long long ans = 0;
	for (int i = 0; i <= n; i++)used[i] = false;
	for (int i = 0; i < Z.size(); i++) {
		if (!(l <= Z[i].first && Z[i].first < r))continue;
		used[Z[i].first] = true;
		long long C = 1;
		if (used[Z[i].first - 1] == true) {
			C *= (UF.sizeq(UF.root(Z[i].first - 1)) + 1);
			UF.unite(Z[i].first - 1, Z[i].first);
		}
		if (used[Z[i].first + 1] == true) {
			C *= (UF.sizeq(UF.root(Z[i].first + 1)) + 1);
			UF.unite(Z[i].first + 1, Z[i].first);
		}
		ans += Z[i].second*C;
	}
	return ans;
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i < n; i++)Z.push_back(make_pair(abs(a[i + 1] - a[i]), i));
	sort(Z.begin(), Z.end());
	for (int i = 0; i < Z.size(); i++)swap(Z[i].first, Z[i].second);
	for (int i = 0; i < q; i++) { int l, r; cin >> l >> r; cout << query(l, r) << endl; }
	return 0;
}