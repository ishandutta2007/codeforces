/// Created by Arsenii Kirillov
 
#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#ifndef LOCAL
#  define cerr __get_ce
#endif
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
 
/*
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
//*/
 
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
	int r, n;
	cin >> r >> n;
	vector<int> x(n), y(n), t(n), dp(n, -INF), ne(n, -INF);
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> x[i] >> y[i];
		if (x[i] + y[i] - 2 <= t[i])
			dp[i] = 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i)
			ne[i] = max(ne[i], ne[i - 1]);
		dp[i] = max(dp[i], ne[i] + 1);	
		ans = max(ans, dp[i]);
		int d = max(x[i] - 1, r - x[i]) + max(y[i] - 1, r - y[i]);
		for (int j = i + 1; j < n; j++) {
			if (t[j] >= t[i] + d) {
				ne[j] = max(ne[j], dp[i]);
				break;
			}
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}
	cout << ans << endl;
}
 
 
int main() {
#ifdef LOCAL
	clock_t start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int test_count = 1;
	//cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
 
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}