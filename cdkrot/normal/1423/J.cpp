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

const int MOD = 1'000'000'007;
const ll MOD2 = (ll) MOD * MOD;

void add2(ll& a, ll b) {
	a += b;
	if (a >= MOD2) {
		a -= MOD2;
	}
}

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

const int C = 7;
const int L = 8;

vector<vector<int>> mult(vector<vector<int>> const& a, vector<vector<int>> const& b) {
	vector<vector<ll>> ret(C, vector<ll>(C));
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			for (int k = 0; k < C; ++k) {
				add2(ret[i][k], (ll) a[i][j] * b[j][k]);
			}
		}
	}
	vector<vector<int>> int_ret(C, vector<int>(C));
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			int_ret[i][j] = ret[i][j] % MOD;
		}
	}
	return int_ret;
}

void solve() {
	vector<vector<vector<int>>> matr(2, vector<vector<int>>(C, vector<int>(C)));
	vector<vector<int>> matr1(C, vector<int>(C));
	for (int old_carry = 0; old_carry < C; ++old_carry) {
		for (int d = 0; d <= 7; ++d) {
			int b = (old_carry + d) & 1;
			int new_carry = (old_carry + d) / 2;
			matr[b][old_carry][new_carry]++;
		}
	}

	vector<vector<vector<int>>> matrs(1 << L);
	function<void(int, int, vector<vector<int>>)> dfs = [&](int mask, int d, vector<vector<int>> const& cur_matr) {
		if (d == L) {
			matrs[mask] = cur_matr;
			return;
		}

		dfs(mask, d + 1, mult(cur_matr, matr[0]));
		dfs(mask | (1 << d), d + 1, mult(cur_matr, matr[1]));
	};
	vector<vector<int>> I(C, vector<int>(C));
	for (int i = 0; i < C; ++i) {
		I[i][i] = 1;
	}
	dfs(0, 0, I);

	int t;
	cin >> t;
	vector<int> vec(C);
	vector<int> new_vec(C);
	for (int i = 0; i < t; ++i) {
		ll num;
		cin >> num;
		fill(vec.begin(), vec.end(), 0);
		vec[0] = 1;
		while (num) {
			fill(new_vec.begin(), new_vec.end(), 0);
			int cur = num % (1 << L);
			for (int a = 0; a < C; ++a) {
				for (int b = 0; b < C; ++b) {
					add(new_vec[b], mult(vec[a], matrs[cur][a][b]));
				}
			}
			swap(vec, new_vec);
			num >>= L;
		}

		cout << vec[0] << "\n";
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