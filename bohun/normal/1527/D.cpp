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
int t, n, in[N], out[N], Time, siz[N];
vector<int> e[N];

void dfs(int u, int p) {
	in[u] = ++Time;
	for (auto v : e[u])
		if (v != p)
			dfs(v, u);
	out[u] = Time;
	siz[u] = out[u] - in[u] + 1;
}

bool up(int x, int y) {
	return in[y] <= in[x] && in[x] <= out[y];
}

void solve() {
	cin >> n;

	FOR(i, n)
		e[i].clear();

	FOR(i, n - 1) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	dfs(0, 0);

	vector<ll> res(n + 1);
	res[0] = res[1] = ll(n) * (n - 1) / 2;

	int z;
	for (auto v : e[0]) {
		res[1] -= ll(siz[v]) * (siz[v] - 1) / 2;
		if (up(1, v))
			z = v;
	}

	int x = 0, y = 0;
	rep(i, 1, n) {
		bool ok = 1;
		if (up(i, z)) {
			if (up(i, x)) 
				x = i;
			else if (up(x, i))
				;
			else 
				ok = 0;
		}
		else {
			if (up(i, y))
				y = i;
			else if (up(y, i))
				;
			else
				ok = 0;
		}
		if (ok == 0)
			break;
		if (y != 0)
			res[i + 1] = ll(siz[x]) * siz[y];
		else
			res[i + 1] = ll(siz[x]) * (siz[0] - siz[z]);
	}

	FOR(i, n)
		res[i] -= res[i + 1];

	FOR(i, n + 1)
		cout << res[i] << ' ';
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--)
		solve();

	return 0;
}