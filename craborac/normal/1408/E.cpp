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
 
int up[(int)2e5 + 10];
int cnt[(int)2e5 + 10];

int get(int a) {
	if (up[a] == a)
		return a;
	return up[a] = get(up[a]);
}

void add(int a, int b) {
	a = get(a);
	b = get(b);
	if (cnt[b] > cnt[a])
		swap(a, b);
	cnt[a] += cnt[b];
	up[b] = a;
}
 
void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> mas;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int q;
			cin >> q;
			q--;
			mas.push_back(make_pair(a[i] + b[q], make_pair(i, n + q)));
		}
	}
	sort(all(mas));
	reverse(all(mas));
	n += m;
	for (int i = 0; i < n; i++) {
		up[i] = i;
		cnt[i] = 1;
	}
	ll ans = 0;
	for (auto qwe: mas) {
		auto p = qwe.second;
		int x = p.first;
		int y = p.second;
		if (get(x) == get(y))
			ans += qwe.first;
		else
			add(x, y);
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