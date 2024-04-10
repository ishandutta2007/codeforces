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
 
const ll p = rnd(100, 300), mod = 998244353;

ll h1[(int)1e6 + 10], h2[(int)1e6 + 10], st[(int)1e6 + 10];

ll mo(ll a)
{
	a %= mod;
	if (a < 0)
		a += mod;
	return a;
}

ll hash1(int l, int r)
{
	return mo(h1[r] - h1[l] * st[r - l]);
}

ll hash2(int l, int r)
{
	return mo(h2[l] - h2[r] * st[r - l]);
}
 
void solve() {
	string s;
	cin >> s;
	int n = s.size();
	int l = 0;
	while (l <= n - 1 - l && s[l] == s[n - 1 - l])
		l++;
	if (l > n - 1 - l)
	{
		cout << s << "\n";
		return;
	}
	h1[0] = 0;
	h2[n] = 0;
	st[0] = 1;
	for (int i = 0; i < n; i++)
	{
		h1[i + 1] = (h1[i] * p + s[i]) % mod;
		st[i + 1] = (st[i] * p) % mod;
	}
	for (int i = n - 1; i >= 0; i--)
		h2[i] = (h2[i + 1] * p + s[i]) % mod;
	int mx = -1, where = -1;
	for (int i = l; i <= n - 1 - l; i++)
	{
		if (hash1(l, i + 1) == hash2(l, i + 1) && i - l >= mx)
		{
			mx = i - l;
			where = 0;
		}
	}
	for (int i = n - 1 - l; i >= l; i--)
	{
		if (hash1(i, n - l) == hash2(i, n - l) && n - 1 - l - i >= mx)
		{
			mx = n - 1 - l - i;
			where = 1;
		}
	}
	if (where)
	{
		int i = n - 1 - l - mx;
		for (int j = 0; j < l; j++)
			cout << s[j];
		for (int j = i; j < n; j++)
			cout << s[j];
		cout << "\n";
	}
	else
	{
		int i = mx + l;
		for (int j = 0; j <= i; j++)
			cout << s[j];
		for (int j = n - l; j < n; j++)
			cout << s[j];
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
 
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}