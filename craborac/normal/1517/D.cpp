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
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<int>>> cost(n, vector<vector<int>>(m, vector<int>(4, (int)1e6 + 10)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			cin >> cost[i][j][1];
			cost[i][j + 1][3] = cost[i][j][1];
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cost[i][j][2];
			cost[i + 1][j][0] = cost[i][j][2];
		}
	}
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << -1 << " ";
			}
			cout << "\n";
		}
		return;
	}
	k /= 2;
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k + 1)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fill(dist[i][j].begin(), dist[i][j].end(), (int)1e9 + 10);
			dist[i][j][0] = 0;
		}
	}
	for (int q = 0; q < k; q++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0)
					dist[i][j][q + 1] = min(dist[i][j][q + 1], dist[i - 1][j][q] + cost[i][j][0]);
				if (j + 1 < m)
					dist[i][j][q + 1] = min(dist[i][j][q + 1], dist[i][j + 1][q] + cost[i][j][1]);
				if (i + 1 < n)
					dist[i][j][q + 1] = min(dist[i][j][q + 1], dist[i + 1][j][q] + cost[i][j][2]);
				if (j > 0)
					dist[i][j][q + 1] = min(dist[i][j][q + 1], dist[i][j - 1][q] + cost[i][j][3]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << 2 * dist[i][j][k] << " ";
		}
		cout << "\n";
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