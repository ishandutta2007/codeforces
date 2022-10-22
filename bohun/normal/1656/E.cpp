#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= int(b); i++)
#define per(i, a, b) for (int i = b; i >= int(a); i--)
#define cat(x) cerr << #x << ": " << x << "\n";
#define sz(x) int(x.size())
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int n, res[N];
vector<int> e[N];

ll dfs(int u, int p, int f) {
	ll s = 0;
	for (auto v : e[u])
		if (v != p)
			s += dfs(v, u, -f);
	ll x = (u == 1 ? 0 : f);
	res[u] = x - s;
	return x;
}

void solve() {
	cin >> n;
	rep(i, 1, n) e[i].clear();
	rep(i, 2, n) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, 0, 1);
	rep(i, 1, n) cout << res[i] << " ";
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

    return 0;
}