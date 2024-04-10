//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

struct UF {
	vector<int> p;
	UF(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = -1;
	}
	int find(int x) {
		return p[x] < 0 ? x : p[x] = find(p[x]);
	}
	bool join(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		p[y] += p[x];
		p[x] = y;
		return true;
	}
};

const int N = 1 << 20;
int n, q, s, d, a[N], dis[N], ans[N];
vector<pair<int, int>> qu[N], ed[N];
UF U(N);

void add_edge(int a, int b, int c) {
	if (max(a, b) < n)
		ed[c].emplace_back(a, b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> q >> s >> d;
	s--;

	FOR(i, n) {
		cin >> a[i];
		dis[i] = 1e9;
	}

	FOR(i, q) {
		int u, k;
		cin >> u >> k;
		u--;
		qu[k].emplace_back(u, i);
	}

	auto upd = [&](int p, int x) {
		dis[p] = min(dis[p], x);
	};

	FOR(i, n) {
		int id = lower_bound(a, a + n, a[i] + d) - a;
		int d1 = a[i] + d - a[id - 1];
		int d2 = a[id] - (a[i] + d);
		add_edge(i, id - 1, d1);
		add_edge(i, id, d2);
		upd(id - 1, d1);
		upd(id, d2);
	}

	FOR(i, n - 1)
		upd(i + 1, dis[i] + a[i + 1] - a[i]);

	per(i, 1, n)
		upd(i - 1, dis[i] + a[i] - a[i - 1]);

	FOR(i, n - 1)
		add_edge(i, i + 1, min(dis[i], dis[i + 1]) + a[i + 1] - a[i]);

	FOR(i, N) {
		for (auto [a, b] : ed[i])
			U.join(a, b);
		for (auto [u, id] : qu[i])
			ans[id] = U.find(s) == U.find(u);
	}

	FOR(i, q)
		cout << (ans[i] ? "Yes\n" : "No\n");
	return 0;
}