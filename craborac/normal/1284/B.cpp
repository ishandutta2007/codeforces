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
	long long cnt = 0;
	vector<int> a, b;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int mn = (int)1e6 + 10;
		int mx = 0;
		bool d = 0;
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			if (x > mn)
				d = 1;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		if (d)
			cnt++;
		else
		{
			a.push_back(mn);
			b.push_back(mx);
		}
	}
	sort(all(a));
	sort(all(b));
	int q = 0, w = 0;
	long long ans = cnt * cnt + 2 * cnt * (n - cnt);
	while (q < (int)a.size() && w < (int)b.size())
	{
		if (a[q] >= b[w])
			w++;
		else
		{
			ans += (int)b.size() - w;
			q++;
		}
	}
	cout << ans << endl;
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
	//cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
 
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}