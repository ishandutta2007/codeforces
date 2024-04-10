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
	vector<int> used(n, 0), h(n, 0), ans(m, 0), up(n, -1);
	vector<vector<pair<int, int>>> mas(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		mas[a].push_back({b, i});
		mas[b].push_back({a, i});
	}
	vector<pair<int, int>> ext;
	vector<int> id;
	function<void(int, int)> dfs = [&](int v, int pr) {
		used[v] = 1;
		for (auto p: mas[v]) {
			int u = p.first;
			if (used[u] == 0) {
				h[u] = h[v] + 1;
				up[u] = p.second;
				dfs(u, v);
			} else if (h[v] > h[u] && u != pr) {
				ext.push_back({v, u});
				id.push_back(p.second);
				ans[p.second] = 1;
			}
		}
	};
	dfs(0, -1);
	if (ext.size() == 3) {
		set<int> se;
		for (auto p: ext) {
			se.insert(p.first);
			se.insert(p.second);
		}
		if (se.size() == 3) {
			ans[id[0]] = 0;
			ans[up[ext[0].first]] = 1;
		}
	}	
	for (int i = 0; i < m; i++)
		cout << ans[i];
	cout << "\n";
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