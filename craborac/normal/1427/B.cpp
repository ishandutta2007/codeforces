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
	int n, k;
	string s;
	cin >> n >> k >> s;
	int ans = 0;
	vector<pair<int, int>> mas;
	int last = -n;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			if (last >= 0 && last < i - 1) {
				mas.push_back({i - 1 - last, last});
			}
			last = i;
		}
	}
	sort(mas.begin(), mas.end());
	for (auto p: mas) {
		for (int i = p.second + 1; i <= p.second + p.first && k > 0; i++) {
			s[i] = 'W';
			k--;
		}
	}
	for (int i = 1; i < n && k > 0; i++) {
		if (s[i - 1] == 'W' && s[i] == 'L') {
			s[i] = 'W';
			k--;
		}
	}
	for (int i = n - 2; i >= 0 && k > 0; i--) {
		if (s[i] == 'L' && s[i + 1] == 'W') {
			s[i] = 'W';
			k--;
		}
	}
	for (int i = 0; i < n && k > 0; i++) {
		if (s[i] == 'L') {
			s[i] = 'W';
			k--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			ans++;
			if (i > 0 && s[i - 1] == 'W')
				ans++;
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
 
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}