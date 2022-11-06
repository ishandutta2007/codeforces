// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> st;
	vector<bool> used(n);

	function<bool(int, int)> find_cycle = [&](int v, int p) {
		st.push_back(v);
		used[v] = true;
		for (int to : graph[v]) {
			if (to != p && used[to]) {
				reverse(st.begin(), st.end());
				while (st.back() != to) {
					st.pop_back();
				}
				return true;
			}
			if (!used[to]) {
				if (find_cycle(to, v)) {
					return true;
				}
			}
		}
		st.pop_back();
		return false;
	};

	assert(find_cycle(0, 0));
	auto cycle = st;

	// for (int v : cycle) {
	// 	cerr << v << " ";
	// }
	// cerr << endl;

	fill(used.begin(), used.end(), 0);
	for (int v : cycle) {
		used[v] = true;
	}

	vector<int> dp(n);
	vector<int> sz(n);

	function<void(int, int)> dfs = [&](int v, int p) {
		sz[v] = 1;
		for (int to : graph[v]) {
			if (!used[to] && to != p) {
				dfs(to, v);
				sz[v] += sz[to];
				dp[v] += dp[to];
			}
		}
		dp[v] += sz[v];
	};

	for (int v : cycle) {
		dfs(v, v);

		// cerr << dp[v] << " ";
	}
	// cerr << endl;

	vector<int> cur;
	vector<int> next(szof(cycle));
	vector<int> pref = {0};
	for (int v : cycle) {
		cur.push_back(dp[v]);
		pref.push_back(pref.back() + sz[v]);
	}

	for (int v : cycle) {
		pref.push_back(pref.back() + sz[v]);
	}


	auto get_sum = [&](int l, int r) {
		return pref[r] - pref[l];
	};

	// cerr << clock() * 1000 / CLOCKS_PER_SEC << endl;

	for (int l = 2; l < szof(cycle); ++l) {
		for (int i = 0; i < szof(cycle); ++i) {
			int fv = cycle[i];
			int lv = cycle[(i + l - 1) >= szof(cycle) ? (i + l - 1) - szof(cycle) : (i + l - 1)];
			int ni = i + 1;
			if (ni == szof(cycle)) {
				ni = 0;
			}
			next[i] = max(cur[i] + dp[lv] - sz[lv], cur[ni] + dp[fv] - sz[fv]) + get_sum(i, i + l);
		}
		swap(next, cur);
	}

	// cerr << clock() * 1000 / CLOCKS_PER_SEC << endl;

	// for (int num : cur) {
	// 	cerr << num << " ";
	// }
	// cerr << endl;

	int ans = 0;

	function<void(int, int, int)> calc_ans = [&](int v, int p, int val) {
		int sum_children = 0;
		for (int to : graph[v]) {
			if (!used[to] && to != p) {
				sum_children += dp[to];
			}
		}
		// cerr << v << " " << val + sum_children + n << endl;
		ans = max(ans, val + sum_children + n);
		for (int to : graph[v]) {
			if (!used[to] && to != p) {
				calc_ans(to, v, val + sum_children - dp[to] + n - sz[to]);
			}
		}
	};

	for (int i = 0; i < szof(cycle); ++i) {
		int v = cycle[i];
		calc_ans(v, v, cur[(i + 1) % szof(cycle)]);
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}