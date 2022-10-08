/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

// #define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 3e5 + 10, K = 20;

int p[N][K];
vector<int> g[N];

int64_t solve() {
	int n;
	cin >> n;
	forn(i, n - 1) {
		int a, b;
		cin >> a >> b, a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> t_in(n), t_out(n), d(n);
	int T = 0;
	function<void(int, int, int)> dfs = [&](int v, int pa, int dep) {
		t_in[v] = T++, d[v] = dep;
		p[v][0] = pa;
		for (int k = 1; k < K; k++)
			p[v][k] = p[p[v][k-1]][k-1];
		for (int x : g[v])
			if (x != pa)
				dfs(x, v, dep + 1);
		t_out[v] = T;
	};
	dfs(0, 0, 0);

	auto ancestor = [&](int a, int b) {
		return t_in[a] <= t_in[b] && t_out[b] <= t_out[a];
	};
	auto lca = [&](int a, int b) {
		for (int k = K - 1; k >= 0; k--)
			if (!ancestor(p[a][k], b))
				a = p[a][k];
		return ancestor(a, b) ? a : p[a][0];
	};
	auto jump = [&](int a, int d) {
		forn(k, K)
			if ((d >> k) & 1)
				a = p[a][k];
		return a;
	};

	vector<int> cnt(n), cntp(n);
	vector<map<pair<int, int>, int>> v2(n);
	vector<map<int, int>> v1(n);

	int m, cc = n;
	cin >> m;
	vector<pair<int, int>> ps;
	forn(i, m) {
		int a, b;
		cin >> a >> b, a--, b--;
		if (d[a] < d[b])
			swap(a, b);
		int c = lca(a, b);
		ps.push_back({a, c});
		ps.push_back({b, c});
		int a1 = (c == a ? cc++ : jump(a, d[a] - d[c] - 1));
		int b1 = (c == b ? cc++ : jump(b, d[b] - d[c] - 1));
		// printf("%d, %d -> %d [%d,%d]\n", a, b, c, a1, b1);
		// printf("c = %d, a = %d, b = %d : %d %d [%d,%d]\n", c, a, b, a1, b1, d[c] - d[a] - 1, d[c] - d[b] - 1);
		if (a1 > b1)
			swap(a1, b1);
		assert(a1 != b1);
		v2[c][{a1, b1}]++;
		v1[c][a1]++;
		v1[c][b1]++;
		cnt[c]++;
	}

	int64_t ans = 0;
	forn(lca, n) {
		int pa = p[lca][0];
		cntp[lca] = (pa == lca ? 0 : v1[pa][lca]);
		// printf("cnt[%d] = %d | %d\n", lca, cnt[lca], cntp[lca]);

		// ans = 0;
		auto f = [&](int64_t k) { return k * (k - 1) / 2; };
		// printf("%d : cnt = %d : %d\n", lca, (int)cnt[lca], (int)f(cnt[lca]));
		ans += f(cnt[lca]);
		// printf("ans = %d\n", (int)ans);
		// printf("ans[%d] = %d\n", lca + 1, (int)ans);
		for (auto [v, c] : v1[lca]) ans -= f(c);//, printf("%d, %d : cnt = %d : %d\n", lca, v, (int)c, (int)f(c));
		for (auto [p, c] : v2[lca])	ans += f(c);
		// printf("ans[%d] = %d\n", lca + 1, (int)ans);
	}
	// printf("ans = %d\n", (int)ans);

	struct MakeSum {
		vector<int> c;
		vector<int64_t> sc;
		void go(int v, int pa) {
			sc[v] += c[v];
			for (int x : g[v])
				if (x != pa)
					sc[x] += sc[v], go(x, v);
		}
		MakeSum(const vector<int> &_c) : c(_c), sc(_c.size()) {
			go(0, 0);
		};
		int64_t sum(int down, int up) { // [down, up)
			return sc[down] - sc[up];
		}
	} sc(cnt), scp(cntp);

	for (auto [a, c] : ps) {
		if (a == c) continue;
		int a1 = jump(a, d[a] - d[c] - 1);
		ans += sc.sum(a, c);
		ans -= scp.sum(a, a1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cout << solve() << "\n";
}