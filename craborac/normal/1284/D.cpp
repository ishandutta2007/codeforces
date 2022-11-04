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
	vector<int> a(n), b(n), c(n), d(n);
	vector<pair<int, int> > mas;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];	
	}
	for (int qwe = 0; qwe < 2; qwe++)
	{
	mas.clear();
	for (int i = 0; i < n; i++)
	{
		mas.push_back({a[i], -i - 1});
		mas.push_back({b[i], i + 1});
	}
	sort(all(mas));
	set<pair<int, int> > le, ri;
	for (auto p: mas)
	{
		int i = abs(p.second) - 1;
		if (p.second < 0)
		{
			if (le.size())
			{
				auto q = le.end();
				q--;
				if (q->first > d[i])
				{
					cout << "NO" << endl;
					return;
				}
			}
			if (ri.size())
			{
				auto q = ri.begin();
				if (q->first < c[i])
				{
					cout << "NO" << endl;
					return;
				}
			}
			le.insert({c[i], i});
			ri.insert({d[i], i});
		}
		else
		{
			le.erase({c[i], i});
			ri.erase({d[i], i});
		}
	}
	for (int i = 0; i < n; i++)
	{
		swap(a[i], c[i]);
		swap(b[i], d[i]);
	}
	}
	cout << "YES" << endl;
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