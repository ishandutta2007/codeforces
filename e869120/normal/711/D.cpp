#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
// ------ Class ------ //
class UnionFind {
private:
	unsigned size_; std::vector<unsigned> par, rank;
public:
	UnionFind() : size_(0), par(std::vector<unsigned>()), rank(std::vector<unsigned>()) {};
	UnionFind(unsigned size__) : size_(size__) {
		par.resize(size_); rank.resize(size_);
		for (unsigned i = 0; i < size_; i++) par[i] = i, rank[i] = 0;
	}
	unsigned size() { return size_; }
	unsigned root(unsigned x) { return par[x] == x ? x : par[x] = root(par[x]); }
	bool same(unsigned x, unsigned y) { return root(x) == root(y); }
	void unite(unsigned x, unsigned y) {
		x = root(x), y = root(y);
		if (x == y) return;
		if (rank[x] < rank[y]) par[x] = y;
		else if (rank[x] == rank[y]) par[y] = x, rank[x]++;
		else par[y] = x;
	}
	bool operator==(const UnionFind &u) { return par == u.par; }
	bool operator!=(const UnionFind &u) { return par != u.par; }
};
vector<int>X[300000]; int n, a, num[300000], dist[300000]; bool used[300000];
vector<int>V[300000];
vector<vector<int>>W[300000];
map<pair<int, int>, int>RW[300000];
int solve(int p, int size_) {
	UnionFind UF(size_);
	pair<int, int>ZS;
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < W[p][i].size(); j++) {
			if (i > W[p][i][j])continue;
			if (UF.same(i, W[p][i][j]) == false) { UF.unite(i, W[p][i][j]); }
			else { ZS = make_pair(i, W[p][i][j]); }
		}
	}
	for (int i = 0; i < size_; i++)dist[i] = 999999999;
	queue<int>Q; Q.push(ZS.first); dist[ZS.first] = 0;
	while (!Q.empty()) {
		int a1 = Q.front(); Q.pop();
		for (int i = 0; i < W[p][a1].size(); i++) {
			if (a1 == ZS.first && W[p][a1][i] == ZS.second)continue;
			if (a1 == ZS.second && W[p][a1][i] == ZS.first)continue;
			if (dist[W[p][a1][i]] > dist[a1] + 1) {
				dist[W[p][a1][i]] = dist[a1] + 1; Q.push(W[p][a1][i]);
			}
		}
	}
	if (dist[ZS.second] == 999999999 || dist[ZS.second] == 0)dist[ZS.second] = 1;
	return dist[ZS.second] + 1;
}
long long power(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; }
		q *= q; q %= m; p %= m;
	}
	return p;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a; X[a].push_back(i); X[i].push_back(a);
	}
	queue<int>Q; int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		if (used[i] == true)continue;
		Q.push(i); used[i] = true; V[cnt1].push_back(i); num[i] = cnt1;
		while (!Q.empty()) {
			int a1 = Q.front(); Q.pop();
			for (int j = 0; j < X[a1].size(); j++) {
				if (used[X[a1][j]] == false) {
					Q.push(X[a1][j]); V[cnt1].push_back(X[a1][j]);
					num[X[a1][j]] = cnt1; used[X[a1][j]] = true;
				}
			}
		}
		cnt1++;
	}
	for (int i = 0; i < cnt1; i++) { W[i].resize(V[i].size()); sort(V[i].begin(), V[i].end()); }
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < X[i].size(); j++) {
			int pos1 = lower_bound(V[num[i]].begin(), V[num[i]].end(), i) - V[num[i]].begin();
			int pos2 = lower_bound(V[num[i]].begin(), V[num[i]].end(), X[i][j]) - V[num[i]].begin();
			if (RW[num[i]][make_pair(pos1, pos2)] == 0) {
				W[num[i]][pos1].push_back(pos2);
				RW[num[i]][make_pair(pos1, pos2)] = 1;
			}
		}
	}
	long long ret = 1;
	for (int i = 0; i < cnt1; i++) {
		int R = solve(i, V[i].size());
		ret *= (power(2, V[i].size(), 1000000007) - power(2, V[i].size() - R + 1, 1000000007) + 1000000007);
		ret %= 1000000007;
	}
	cout << ret << endl;
	return 0;
}