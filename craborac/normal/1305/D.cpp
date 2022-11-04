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
 
vector<int> mas[1010];

int fin(int v)
{
	if (mas[v].size() >= 2)
		return v;
	return mas[v][0];
}

void del(int a, int b)
{
	for (int i = 0; i < (int)mas[a].size(); i++)
	{
		if (mas[a][i] == b)
		{
			swap(mas[a][i], mas[a][mas[a].size() - 1]);
			mas[a].pop_back();
			break;
		}
	}
}
 
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		mas[a].push_back(b);
		mas[b].push_back(a);
	}
	int cur = 0;
	while (true)
	{
		if (mas[cur].size() == 0)
		{
			cout << "! " << cur + 1 << endl;
			return;
		}
		int v = fin(cur);
		if (mas[v].size() == 1)
		{
			cout << "? " << v + 1 << " " << mas[v][0] + 1 << endl;
			int x;
			cin >> x;
			cout << "! " << x << endl;
			return;
		}
		cout << "? " << mas[v][0] + 1 << " " << mas[v][1] + 1 << endl;
		int x;
		cin >> x;
		x--;
		if (x == mas[v][0] || x == mas[v][1])
		{
			del(v, x);
			del(x, v);
			cur = x;
		}
		else
		{
			int aa = mas[v][0];
			int bb = mas[v][1];
			del(x, aa);
			del(aa, x);
			del(x, bb);
			del(bb, x);
			cur = x;
		}
	}
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