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

struct point
{
	long long x, y;
	point(long long x_ = 0, long long y_ = 0): x(x_), y(y_) {};
	point operator -(point a)
	{
		return point(x - a.x, y - a.y);
	}
	point operator +(point a)
	{
		return point(x + a.x, y + a.y);
	}
	long long operator *(point a)
	{
		return x * a.x + y * a.y;
	}
	long long operator /(point a)
	{
		return x * a.y - y * a.x;
	}
	bool operator < (point a)
	{
		if (x != a.x)
			return x < a.x;
		return y < a.y;
	}
};

point start;

bool cmp(point a, point b)
{
	bool aa = (a.y > start.y || (a.y == start.y && a.x > start.x));
	bool bb = (b.y > start.y || (b.y == start.y && b.x > start.x));
	if (aa != bb)
		return aa;
	return (a - start) / (b - start) > 0;
}
 
void solve() {
	int n;
	cin >> n;
	vector<point> mas(n);
	for (int i = 0; i < n; i++)
		cin >> mas[i].x >> mas[i].y;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		vector<point> arr;
		for (int j = 0; j < n; j++)
			if (j != i)
				arr.push_back(mas[j]);
		start = mas[i];
		sort(all(arr), cmp);
		for (int j = 0; j < n - 1; j++)
			arr.push_back(arr[j]);
		ans += (n - 1ll) * (n - 2ll) * (n - 3ll) * (n - 4ll) / 24ll;
		int w = 0;
		//cout << ans << "\n";
		for (int q = 0; q < n - 1; q++)
		{
			while (w <= q)
				w++;
			while (w < (int)arr.size() && (arr[q] - mas[i]) / (arr[w] - mas[i]) > 0)
				w++;
			long long cnt = w - q - 1;
			//cout << cnt << " " << cnt * (cnt - 1) * (cnt - 2) / 6 << endl;
			ans -= cnt * (cnt - 1) * (cnt - 2) / 6;
		}
		//cout << ans << "\n";
		//cout << endl;
	}
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