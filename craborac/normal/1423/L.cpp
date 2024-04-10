// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
	int n, s, d;
	cin >> n >> s >> d;

	vector<ull> val(n);
	for (int i = 0; i < n; ++i) {
		val[i] = rnd(0, 1ll << 60);
	}

	vector<ull> switches(s);
	for (int i = 0; i < s; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int ind;
			cin >> ind;
			--ind;
			switches[i] ^= val[ind];
		}
	}

	int part1 = s / 2;
	int part2 = s - part1;

	gp_hash_table<ull, int> best_part1, best_part2;

	for (int mask = 0; mask < 1 << part1; ++mask) {
		ull cur_val = 0;
		for (int i = 0; i < part1; ++i) {
			if (mask & (1 << i)) {
				cur_val ^= switches[i];
			}
		}
		auto it = best_part1.find(cur_val);
		if (it == best_part1.end()) {
			best_part1[cur_val] = __builtin_popcount(mask);
		} else {
			it->ss = min(it->ss, __builtin_popcount(mask));
		}
	}

	for (int mask = 0; mask < 1 << part2; ++mask) {
		ull cur_val = 0;
		for (int i = 0; i < part2; ++i) {
			if (mask & (1 << i)) {
				cur_val ^= switches[part1 + i];
			}
		}
		auto it = best_part2.find(cur_val);
		if (it == best_part2.end()) {
			best_part2[cur_val] = __builtin_popcount(mask);
		} else {
			it->ss = min(it->ss, __builtin_popcount(mask));
		}
	}

	for (int i = 0; i < d; ++i) {
		int k;
		cin >> k;
		ull cur_val = 0;
		for (int j = 0; j < k; ++j) {
			int ind;
			cin >> ind;
			--ind;
			cur_val ^= val[ind];
		}
		int ans = INF;
		for (auto& p : best_part1) {
			auto it = best_part2.find(cur_val ^ p.ff);
			if (it != best_part2.end()) {
				// cerr << p.ff << " " << p.ss << " " << it->ff << " " << it->ss << endl;
				ans = min(ans, p.ss + it->ss);
			}
		}

		if (ans == INF) {
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}
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