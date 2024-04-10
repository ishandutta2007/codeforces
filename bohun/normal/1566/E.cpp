//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 200200;

int n, leafs, buds, extra;
vector<int> e[N];

bool dfs(int u, int p) {
	int cnt = 0;
	for (auto v : e[u])
		if (v != p)
			cnt += dfs(v, u);
	if (cnt != 0) {
		leafs += cnt;
		buds += (u != 1);
		extra += u == 1;
		return 0;
	}
	return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		FOR(i, n - 1) {
			int a, b;
			cin >> a >> b;
			e[a].push_back(b);
			e[b].push_back(a);
		}

		leafs = buds = extra = 0;
		dfs(1, 0);

		cout << leafs - (buds - !extra) << '\n';

		rep(i, 1, n + 1)
			e[i].clear();
	}
	return 0;
}