#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;
int n, par[N], deg[N];
vector<int> e[N], f[N][2];
queue<int> q;

void dfs(int u, int p) {
	int cnt[2] = {};
	for (auto v : e[u]) {
		if (v != p) {
			dfs(v, u);
			f[u][par[v]].push_back(v);
			cnt[par[v]]++;
		}
	}

	par[u] = cnt[0] >= cnt[1];
}

void add(int a, int b) {
	cout << a << " " << b << endl;
	deg[a]--;
	deg[b]--;
}

void solve(int u, int p) {
	assert(f[u][deg[u] % 2].size());
	int x = f[u][deg[u] % 2].back();
	f[u][deg[u] % 2].pop_back();
	q.push(x);

	auto add = [&]() {
		cout << u << " " << x << endl;
		deg[u]--;
		deg[x]--;
	};

	if (deg[x] % 2 == deg[u] % 2) {
		add();
	}
	else {
		solve(x, u);
		add();
	}
}

void solve() {
	cin >> n;

	rep(i, 1, n) {
		e[i].clear();
		deg[i] = 0;
		f[i][0].clear();
		f[i][1].clear();
	}

	rep(i, 2, n) {
		int a, b;
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfs(1, 0);
	rep(i, 1, n) {
		int c0 = f[i][0].size() + (i != 1 && par[i] == 0);
		int c1 = f[i][1].size() + (i != 1 && par[i] == 1);
		if (abs(c0 - c1) > 1 || c0 > c1) {
			cout << "NO\n";
			return;
		}
	}

	// rep(i, 1, n) {
	// 	cat(i);
	// 	cat(f[i][0].size());
	// 	cat(f[i][1].size());
	// }

	cout << "YES\n";
	q.push(1);

	while (!q.empty()) {
		auto u = q.front();
		if (deg[u] == 0) {
			q.pop();
			continue;
		}
		solve(u, 0);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}