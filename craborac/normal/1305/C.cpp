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
 
int mod;

int mul(int a, int b)
{
	return ((ll)a * b) % mod;
} 

int mpow(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		b /= 2;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n >> mod;
	vector<int> a(n), b(mod, 0), c(mod, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(all(a));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < mod; j++)
			c[(a[i] - j) % mod] += b[j];
		b[a[i] % mod]++;
	}
	int ans = 1;
	for (int i = 0; i < mod; i++)
		ans = mul(ans, mpow(i, c[i]));
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