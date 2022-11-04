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

const int MAXN = (int)12e5 + 10;

int sum[MAXN], mn[MAXN], p[MAXN / 4];
pair<int, int> mx[MAXN];

void init(int v, int l, int r)
{
	if (r - l == 1)
	{
		mx[v] = {p[l], l};
		sum[v] = 0;
		mn[v] = 0;
		return;
	}
	int m = (l + r) / 2;
	init(2 * v + 1, l, m);
	init(2 * v + 2, m, r);
	mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
	sum[v] = 0;
	mn[v] = 0;
}

void kill(int v, int l, int r, int q)
{
	if (r - l == 1)
	{
		mx[v].first = -1;
		sum[v]++;
		mn[v]++;
		return;
	}
	int m = (l + r) / 2;
	if (q < m)
		kill(2 * v + 1, l, m, q);
	else
		kill(2 * v + 2, m, r, q);
	sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
	mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
	mn[v] = min(mn[2 * v + 1], sum[2 * v + 1] + mn[2 * v + 2]);
}

void add(int v, int l, int r, int q, int w)
{
	if (r - l == 1)
	{
		sum[v] += w;
		mn[v] += w;
		return;
	}
	int m = (l + r) / 2;
	if (q < m)
		add(2 * v + 1, l, m, q, w);
	else
		add(2 * v + 2, m, r, q, w);
	sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
	mn[v] = min(mn[2 * v + 1], sum[2 * v + 1] + mn[2 * v + 2]);
}

int fir(int v, int l, int r, int q)
{
	if (r - l == 1)
	{
		if (sum[v] < q)
			return l;
		else
			return -1;
	}
	int m = (l + r) / 2;
	if (mn[2 * v + 1] < q)
		return fir(2 * v + 1, l, m, q);
	else
		return fir(2 * v + 2, m, r, q - sum[2 * v + 1]);
}

pair<int, int> get(int v, int l, int r, int q)
{
	if (l >= q)
		return {-1, -1};
	if (r <= q)
		return mx[v];
	int m = (l + r) / 2;
	return max(get(2 * v + 1, l, m, q), get(2 * v + 2, m, r, q));
}
 
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	init(0, 0, n);
	for (int i = 0; i < n; i++)
	{
		auto pp = get(0, 0, n, n);
		cout << pp.first << " ";
		int q;
		cin >> q;
		q--;
		add(0, 0, n, q, -1);
		int t = fir(0, 0, n, 0);
		pp = get(0, 0, n, t + 1);
		kill(0, 0, n, pp.second);
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