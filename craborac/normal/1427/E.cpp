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
 
ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

pair<ll, ll> gcd2(ll a, ll b) {
	if (b == 0) {
		return {1, 0};
	}
	ll c = a / b;
	auto p = gcd2(b, a % b);
	return {p.second, p.first - c * p.second};
}

void solve() {
	set<ll> se;
	vector<pair<pair<ll, ll>, ll>> ans;
	ll x;
	cin >> x;
	se.insert(x);
	auto add = [&](ll a, ll b) {
		//cerr << a << " " << b << endl;
		if (se.count(a + b) == 0) {
			ans.push_back(make_pair(make_pair(a, b), 0));
			se.insert(a + b);
		}
		return;
	};
	auto rox = [&](ll a, ll b) {
		if (se.count(a ^ b) == 0) {
			ans.push_back(make_pair(make_pair(a, b), 1));
			se.insert(a ^ b);
		}
		return;
	};	
	auto mul = [&](ll a, ll b) {
		ll ans = 0;
		while (b) {
			//cerr << a << " " << ans << " " << b << endl;
			if (b & 1) {
				if (ans != 0)
					add(ans, a);
				ans += a;
			}
			b /= 2;
			if (b)
				add(a, a);
			a += a;
		}
		return;
	};
	for (ll i = 0; ; i++) {
		ll a = (i * x) ^ ((i + 1) * x);
		if (gcd(a, x) == 1) {
			mul(x, i);
			mul(x, i + 1);
			rox(x * i, x * i + x);
			auto p = gcd2(x, a);
			p.first = abs(p.first);
			p.second = abs(p.second);
			mul(x, p.first);
			mul(a, p.second);
			ll q = x * p.first;
			ll w = a * p.second;
			if (q > w)
				swap(q, w);
			if (q & 1) {
				add(q, x);
				add(w, x);
				q += x;
				w += x;
			}
			rox(q, w);
			break;
		}
	}
	cout << ans.size() << "\n";
	for (auto p: ans) {
		cout << p.first.first << " ";
		if (p.second)
			cout << "^ ";
		else
			cout << "+ ";
		cout << p.first.second << "\n";
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