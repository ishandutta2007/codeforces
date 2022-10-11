#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<functional>
using namespace std;
#pragma warning(disable:4996)
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
long long n, m, k, a[1000][1000], group[1000000], pre = 0, pre1 = 0, pre2 = 0; vector<tuple<long long, long long, long long>>vec; bool used[1000][1000];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }, cnt = 0, col[1000][1000], ans[1000][1000]; vector<pair<int, int>>x[1000][1000], U[1000009];
int col2[1000][1000]; vector<pair<int, int>>ansD;
void dfs(int p1, int p2) {
	if (col[p1][p2] >= 1)return;
	col[p1][p2] = cnt;
	if (ansD.size() < (k / pre))ansD.push_back(make_pair(p1, p2));
	for (int i = 0; i < x[p1][p2].size(); i++) {
		dfs(x[p1][p2][i].first, x[p1][p2][i].second);
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { scanf("%lld", &a[i][j]); vec.push_back(make_tuple(a[i][j], i, j)); } }
	sort(vec.begin(), vec.end(), greater<tuple<long long, long long, long long>>());
	UnionFind UF(n * m); for (int i = 0; i < n*m; i++) { group[i] = 1; }
	for (int i = 0; i < vec.size(); i++) {
		used[get<1>(vec[i])][get<2>(vec[i])] = true;
		for (int j = 0; j < 4; j++) {
			int cx = get<1>(vec[i]) + dx[j], cy = get<2>(vec[i]) + dy[j];
			if (cx < 0 || cy < 0 || cx >= n || cy >= m || used[cx][cy] == false)continue;

			long long B1 = UF.root(get<1>(vec[i])*m + get<2>(vec[i])), B2 = UF.root(cx*m + cy);
			UF.unite(get<1>(vec[i])*m + get<2>(vec[i]), cx*m + cy);
			if (B1 != B2) {
				long long I = group[B1] + group[B2];
				group[B1] = 0; group[B2] = 0;
				group[UF.root(get<1>(vec[i])*m + get<2>(vec[i]))] = I;
			}
		}
		if (group[UF.root(get<1>(vec[i])*m + get<2>(vec[i]))] >= (k / get<0>(vec[i])) && (k%get<0>(vec[i])) == 0) {
			pre = get<0>(vec[i]); pre1 = get<1>(vec[i]); pre2 = get<2>(vec[i]); break;
		}
	}
	if (pre == 0) { cout << "NO" << endl; }
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					int cx = i + dx[k], cy = j + dy[k];
					if (cx < 0 || cx >= n || cy < 0 || cy >= m)continue;
					if (a[i][j] >= pre && a[cx][cy] >= pre)x[i][j].push_back(make_pair(cx, cy));
				}
			}
		}
		cnt = 1; dfs(pre1, pre2);
		for (int i = 0; i < ansD.size(); i++)ans[ansD[i].first][ansD[i].second] = pre;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j >= 1)cout << ' ';
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}