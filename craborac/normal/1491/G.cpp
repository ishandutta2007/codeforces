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
	int n;
	cin >> n;
	vector<int> mas(n), used(n, 1);
	vector<vector<int>> arr;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		mas[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			if (mas[i] == i) {
				used[i] = 0;
			} else {
				used[i] = 0;
				int x = i;
				vector<int> cur;
				cur.push_back(x);
				x = mas[x];
				while (x != i) {
					cur.push_back(x);
					used[x] = 0;
					x = mas[x];
				}
				arr.push_back(cur);
			}
		}
	}
	//cout << arr.size() << endl;
	for (int i = sz(arr) % 2; i < sz(arr); i += 2) {
		ans.push_back({arr[i][0], arr[i + 1][0]});
		for (int j = 1; j < sz(arr[i]); j++) {
			ans.push_back({arr[i][j], arr[i + 1][0]});
		}
		for (int j = 1; j < sz(arr[i + 1]); j++) {
			ans.push_back({arr[i][0], arr[i + 1][j]});
		}
		ans.push_back({arr[i][0], arr[i + 1][0]});
	}
	if (sz(arr) % 2) {
		if (sz(arr[0]) == n) {
			ans.push_back({arr[0][0], arr[0][1]});
			ans.push_back({arr[0][1], arr[0][2]});
				ans.push_back({arr[0][0], arr[0][2]});
			for (int i = 3; i < sz(arr[0]); i++) {
				ans.push_back({arr[0][1], arr[0][i]});
			}
			ans.push_back({arr[0][0], arr[0][1]});
		} else {
			fill(used.begin(), used.end(), 0);
			for (int i: arr[0])
				used[i] = 1;
			int x = 0;
			while (used[x])
				x++;
			for (int j: arr[0])
				ans.push_back({x, j});
			ans.push_back({x, arr[0][0]});
		}
	}
	cout << sz(ans) << "\n";
	for (auto p: ans) {
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
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