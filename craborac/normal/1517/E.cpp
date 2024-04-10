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
	vector<ll> mas(n), arr[2], pref[2];
	pref[0].push_back(0);
	pref[1].push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		arr[i & 1].push_back(mas[i]);
		pref[i & 1].push_back(pref[i & 1].back() + mas[i]);
	}
	ll ans = 0;
	ll sum = pref[0].back() + pref[1].back();
	ll cur = 0;
	for (int i = 0; i + 2 < n; i++) {
		cur += mas[i];
		if (cur > sum - cur)
			ans++;
	}
	//cout << ans << endl;
	//cout << "?" << sum << endl;
	cur = 0;
	for (int i = n - 2; i >= 0; i--) {
		cur += mas[i];
		if (cur > sum - cur) {
			//cout << "!" << i << endl;
			ans += 1 + i / 2;
			ans += i / 2;
			if (i > 0 && (i & 1) == 0)
				ans--;
		} else {
			int le = -1, ri = i / 2;
			if ((i & 1) == 0) {
				le++;
			}
			while (ri - le > 1) {
				int mi = (le + ri) / 2;
				ll nw = cur + pref[i & 1][i / 2] - pref[i & 1][mi];
				if (nw > sum - nw)
					le = mi;
				else
					ri = mi;
			}
			ans += le + 1;
			if ((i & 1) == 0) {
				ans--;
			}
			if (cur + mas[0] > sum - cur - mas[0]) {
				ans += i / 2;
			} else {
				le = 0, ri = i / 2;
				while (ri - le > 1) {
					int mi = (le + ri) / 2;
					ll nw = cur + pref[i & 1][i / 2] - pref[i & 1][mi] + mas[0];
					if (nw > sum - nw)
						le = mi;
					else
						ri = mi;
				}
				ans += le;
			}
		}
		//cout << ans << endl;
	}
	//cout << "?" << sum << endl;
	cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		cur += mas[i];
		if (cur > sum - cur) {
			ans += 1 + i / 2;
			ans += i / 2;
			if (i > 0 && (i & 1) == 0)
				ans--;
		} else {
			int le = -1, ri = i / 2;
			if ((i & 1) == 0)
				le++;
			while (ri - le > 1) {
				int mi = (le + ri) / 2;
				ll nw = cur + pref[i & 1][i / 2] - pref[i & 1][mi];
				if (nw > sum - nw)
					le = mi;
				else
					ri = mi;
			}
			ans += le + 1;
			if ((i & 1) == 0)
				ans--;
			if (cur + mas[0] > sum - cur - mas[0]) {
				ans += i / 2;
			} else {
				le = 0, ri = i / 2;
				while (ri - le > 1) {
					int mi = (le + ri) / 2;
					ll nw = cur + pref[i & 1][i / 2] - pref[i & 1][mi] + mas[0];
					if (nw > sum - nw)
						le = mi;
					else
						ri = mi;
				}
				ans += le;
			}
		}
		//cout << ans << endl;
	}
	cout << ans % 998244353 << "\n";
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