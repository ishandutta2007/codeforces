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
 
const int mod = 998244353;

int sum(int a, int b) {
	return (a + b >= mod ? a + b - mod : a + b);
}

int mul(int a, int b) {
	return ((ll)a * b) % mod;
}

int mpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		b /= 2;
	}
	return ans;
}

int del(int a, int b) {
	return mul(a, mpow(b, mod - 2));
}

const int N = 3e5 + 10;

vector<int> ans2(N, 0), fact(N, 0), par(N, 0); 

void solve() {
	int n, ans = 0;
	cin >> n;
	auto f = [&](int n, int x) {
		return del(fact[n - x], mul(fact[x], fact[n - 2 * x]));
	};
	for (int i = 0; i <= n / 4; i++) {
		ans = sum(ans, mul(f(n, 2 * i), mul(par[i], ans2[n - 4 * i])));
		//cout << f(n, 2 * i) << " " << par[i] << " " << ans2[n - 4 * i] << "\n";
	}
	cout << ans << "\n";
}
 
 
int main() {
#ifdef LOCAL
	clock_t start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ans2[0] = 1;
	ans2[1] = 1;
	fact[0] = 1;
	fact[1] = 1;
	par[0] = 1;
	par[1] = 2;
	for (int i = 2; i <= N; i++) {
		ans2[i] = sum(ans2[i - 1], mul(ans2[i - 2], i - 1));
		fact[i] = mul(fact[i - 1], i);
		par[i] = mul(par[i - 1], 4 * i - 2);
	}
	
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