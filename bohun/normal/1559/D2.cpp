#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
 
int n, sz[2];
vector<pair<int, int>> res;
 
struct uf {
	int p[200200];
	set<pair<int, int>> s;
	vector<int> G[200200];
	void build() {
		rep(i, 1, n + 1) {
			G[i].push_back(i);
			p[i] = -1;
			s.insert({1, i});
		}
	}
	int find(int x) {
		return p[x] < 0 ? x : p[x] = find(p[x]);
	}
	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return;
		if (-p[x] > -p[y])
			swap(x, y);
		s.erase({-p[x], x});
		s.erase({-p[y], y});
		p[y] += p[x];
		p[x] = y;
		s.insert({-p[y], y});
		for (auto z : G[x])
			G[y].push_back(z);
	}
	void print() {
		for (auto [a, b] : s) {
			cat(a);
			cat(b);
		}
	}
} U[2];
 
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	cin >> n >> sz[0] >> sz[1];

	U[0].build();
	U[1].build();
	rep(j, 0, 2) {
		rep(i, 0, sz[j]) {
			int a, b;
			cin >> a >> b;
			U[j].join(a, b);
		}
	}

	while (res.size() + max(sz[0], sz[1]) < n - 1) {
		auto u = U[0].s.rbegin()->second;
		auto v = U[1].s.rbegin()->second;
		int a, b, id;
		if (U[0].G[u].size() < U[1].G[v].size()) {
			id = 1;
			a = v;
			b = prev(prev(U[1].s.end()))->second;
		}
		else {
			id = 0;
			a = u;
			b = prev(prev(U[0].s.end()))->second;
		}
		for (auto e : U[id].G[a]) {
			if (U[!id].find(e) != U[!id].find(b)) {
				res.emplace_back(e, b);
				U[0].join(e, b);
				U[1].join(e, b);
				break;
			}
		}
	}
 
	assert(res.size() + max(sz[0], sz[1]) == n - 1);
	cout << res.size() << "\n";
	for (auto [a, b] : res)
		cout << a << " " << b << "\n";
 
	return 0;
}