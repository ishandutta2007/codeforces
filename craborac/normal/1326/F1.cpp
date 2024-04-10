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
	vector<string> s(n);
	vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++)
		cin >> s[i];
	c[0][0] = 1;
	auto code = [&](vector<int> a) {
		int ans = 0;
		int k = a.size();
		int i = a.size() - 1;
		while (i > 0 && a[i] < a[i - 1])
		{
			swap(a[i], a[i - 1]);
			i--;
		}
		int last = 0;
		for (i = 0; i < k; i++)
		{
			for (int j = last + 1; j < a[i]; j++)
				ans += c[n - j][k - i - 1];
			last = a[i];
		}
		return ans;
	};
	auto encode = [&](int x, int k) {
		vector<int> ans;
		int last = 1;
		for (int i = 0; i < k; i++)
		{
			while (x >= c[n - last][k - i - 1])
			{
				x -= c[n - last][k - i - 1];
				last++;
			}
			ans.push_back(last);
			last++;
		}
		return ans;
	};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			c[i][j] = c[i - 1][j];
			if (j)
				c[i][j] += c[i - 1][j - 1];
		}
	}
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(1, vector<ll>(1, 1)));
	for (int i = 0; i < n - 1; i++)
	{
		vector<vector<vector<ll>>> nw(c[n][i + 2], vector<vector<ll>>(i + 2, vector<ll>(1 << (i + 1), 0)));
		for (int x = 0; x < c[n][i + 1]; x++)
		{
			vector<int> a = encode(x, i + 1);
			for (int j = 0; j < i + 1; j++)
			{
				int w = 0;
				for (int q = 1; q <= n; q++)
				{
					if (w < i + 1 && q == a[w])
					{
						w++;
						continue;
					}
					a.push_back(q);
					int cur = code(a);
					a.pop_back();
					for (int mask = 0; mask < (1 << i); mask++)
						nw[cur][w][mask + (s[q - 1][a[j] - 1] == '1') * (1 << i)] += dp[x][j][mask];
				}
			}
		}
		swap(dp, nw);
	}
	for (int mask = 0; mask < (1 << (n - 1)); mask++)
	{
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += dp[0][i][mask];
		cout << ans << " ";
	}
	cout << endl;
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