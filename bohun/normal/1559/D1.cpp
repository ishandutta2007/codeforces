#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n, sz[2];
vector<pair<int, int>> res;

struct uf {
	int p[1010];
	uf() {
		iota(p, p + 1010, 0);
	}
	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}
	void join(int x, int y) {
		p[find(x)] = find(y);
	}
} U[2];


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> sz[0] >> sz[1];
	rep(j, 0, 2) {
		rep(i, 0, sz[j]) {
			int a, b;
			cin >> a >> b;
			U[j].join(a, b);
		}
	}

	rep(i, 1, n + 1)
		rep(j, 1, n + 1) 
			if (U[0].find(i) != U[0].find(j) &&
				 U[1].find(i) != U[1].find(j)) {
				res.emplace_back(i, j);
				U[0].join(i, j);
				U[1].join(i, j);
			}

	assert(res.size() + max(sz[0], sz[1]) == n - 1);
	cout << res.size() << "\n";
	for (auto [a, b] : res)
		cout << a << " " << b << "\n";

	return 0;
}