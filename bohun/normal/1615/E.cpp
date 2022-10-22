#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int N = 200200;

int n, k;
int vis[N], fa[N];
vector<int> e[N];

pair<int, int> dfs(int u, int p) {
	assert(vis[u] == 0);
	fa[u] = p;

	pair<int, int> best = {1, u};

	for (auto v : e[u]) {
		if (v != p && vis[v] == 0) {
			auto res = dfs(v, u);
			best = max(best, {res.first + 1, res.second});
		}
	}

	return best;
}

void solve() {
	cin >> n >> k;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	int leafs = 0;
	for (int i = 2; i <= n; i++) 
		leafs += int(e[i].size()) == 1;

	if (k >= leafs) {
		k = max(leafs, min(k, n / 2));
		cout << 1ll * (n - k) * k << '\n';
		return;
	}

	vis[0] = 1;

	set<pair<int, int>> s;
	s.insert(dfs(1, 0));

	ll A = n - k;
	ll B = k;

	int red = 0;
	while (k--) {
		auto [cnt, u] = *(--s.end());
		s.erase((--s.end()));

		red += cnt;

		for (int i = u; vis[i] == 0; i = fa[i]) {
			vis[i] = 1;
			for (auto v : e[i]) {
				if (vis[v] == 0 && fa[i] != v)
					s.insert(dfs(v, i));
			}
		}
	}

	int Free = n - red;

	while (Free > 0 && (A - 1) * (B - 1) < A * B) {
		Free--;
		A--;
		B--;
	}

	cout << A * B << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	solve();

	return 0;
}