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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		//cout << a[i] << " ";
	}
	//cout << "\n";
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++) {
		vector<int> cur;
		if (a[0] == 0) {
			int k = 0;
			while (k < n && a[k] == k)
				k++;
			if (k == n)
				break;
			int l = n - 1;
			while (l >= 0 && a[l] == l)
				l--;
			int q;
			for (int j = 0; j < n; j++)
				if (a[j] == l)
					q = j;
			for (int j = 0; j < k; j++)
				cur.push_back(1);
			if (q != k) {
				cur.push_back(q - k);
			}
			cur.push_back(l + 1 - q);
			for (int j = 0; j < n - 1 - l; j++)
				cur.push_back(1);
			int last = 0;
			for (int j = n - 1; j > l; j--)
				b[last++] = a[j];
			for (int j = q; j <= l; j++)
				b[last++] = a[j];
			for (int j = k; j < q; j++)
				b[last++] = a[j];
			for (int j = k - 1; j >= 0; j--)
				b[last++] = a[j]; 
		} else {
			int k = 0;
			while (k < n && a[k] == n - 1 - k)
				k++;
			if (k == n) {
				reverse(a.begin(), a.end());
				for (int j = 0; j < n; j++)
					cur.push_back(1);
				ans.push_back(cur);
				break;
			}	
			int l = n - 1;
			while (l >= 0 && a[l] == n - 1 - l)
				l--;
			int q;
			for (int j = 0; j < n; j++)
				if (a[j] == n - 1 - l)
					q = j;
			for (int j = 0; j < k; j++)
				cur.push_back(1);
			if (q != k) {
				cur.push_back(q - k);
			}
			cur.push_back(l + 1 - q);
			for (int j = 0; j < n - 1 - l; j++)
				cur.push_back(1);
			int last = 0;
			for (int j = n - 1; j > l; j--)
				b[last++] = a[j];
			for (int j = q; j <= l; j++)
				b[last++] = a[j];
			for (int j = k; j < q; j++)
				b[last++] = a[j];
			for (int j = k - 1; j >= 0; j--)
				b[last++] = a[j];
		}
		for (int j = 0; j < n; j++) {
			a[j] = b[j];
			//cout << a[j] << " ";
		}
		//cout << "\n";
		ans.push_back(cur);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].size() << " ";
		for (int j: ans[i])
			cout << j << " ";
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