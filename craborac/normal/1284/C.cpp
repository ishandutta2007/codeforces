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
 

int n;
int mod;

int add(int a, int b)
{
	return a + b >= mod ? a + b - mod : a + b;
}

int sub(int a, int b)
{
	return a >= b ? a - b : a + mod - b;
}

int mul(int a, int b)
{
	return ((long long)a * b) % mod;
}
 
void solve() {
	cin >> n >> mod;
	vector<int> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = mul(fact[i - 1], i);
	int ans = 0;
	for (int l = 1; l <= n; l++)
	{
		int cur = n - l + 1;
		cur = mul(cur, n - l + 1);
		cur = mul(cur, fact[l]);
		cur = mul(cur, fact[n - l]);
		ans = add(ans, cur);
	}
	cout << ans << "\n";
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