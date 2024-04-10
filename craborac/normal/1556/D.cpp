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
	int n, m;
	cin >> n >> m;
	vector<int> mas(n);
	vector<int> a(6), o(6);
	for (int i = 0; i < 3; i++) {
		cout << "and " << i + 1 << " " << (i + 1) % 3 + 1 << endl;
		cin >> a[i];
		a[i + 3] = a[i];
		cout << "or " << i + 1 << " " << (i + 1) % 3 + 1 << endl;
		cin >> o[i];
		o[i + 3] = o[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 30; j++) {
			if (a[i] & (1 << j)) {
				mas[i] |= (1 << j);
				mas[(i + 1) % 3] |= (1 << j);
			}
			if ((o[i] & (1 << j)) && (o[i + 1] & (1 << j)) && ((a[i + 2] & (1 << j)) == 0)) {
				mas[(i + 1) % 3] |= (1 << j);
			}
		}
	}
	for (int i = 3; i < n; i++) {
		int x, y;
		cout << "and 1 " << i + 1 << endl;
		cin >> x;
		cout << "or 1 " << i + 1 << endl;
		cin >> y;
		y -= x;
		mas[i] = mas[0] ^ y;
	}
	sort(mas.begin(), mas.end());
	cout << "finish " << mas[m - 1] << endl;
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