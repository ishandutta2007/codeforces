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
	return a + b >= mod ? a + b - mod : a + b;
} 

int sub(int a, int b) {
	return a >= b ? a - b : a + mod - b;
}

int mul(int a, int b) {
	return ((ll)a * b) % mod;
}

vector<vector<int>> cur;
int up[2000], cntt[2000], last[2000], used[(int)1e5 + 10];
vector<vector<int>> ins, cnt;

int get(int a) {
	if (a == up[a])
		return a;
	return up[a] = get(up[a]);
}

void add(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
			if (cur[b].size() > cur[a].size())
			swap(a, b);
		for (int i: cur[b])
			cur[a].push_back(i);
		up[b] = a;
		cntt[a] += cntt[b];
	}
	cntt[a]++;
}

vector<int> add(vector<int> a, vector<int> b) {
	vector<int> ans(sz(a) + sz(b) - 1, 0);
	for (int i = 0; i < sz(a); i++)
		for (int j = 0; j < sz(b); j++)
			ans[i + j] = sum(ans[i + j], mul(a[i], b[j]));
	return ans;
}

void solve() {
	//cout << "kek" << endl;
	int n;
	cin >> n;
	vector<int> empty;
	for (int i = 0; i < n; i++) {
		cur.push_back(empty);
		cur[i].push_back(i);
		up[i] = i;
		cntt[i] = 0;
	}
	//cout << "kek" << endl;
	vector<pair<int, pair<int, int>>> arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (i < j)
				arr.push_back(make_pair(x, make_pair(i, j)));
		}
	}
	//cout << "kek" << endl;
	//cout << arr.size() << endl;
	empty.push_back(0);
	fill(used, used + (int)1e5 - 10, -1);
	for (int i = 0; i < n; i++) {
		last[i] = i;
		cnt.push_back(empty);
		cnt[i].push_back(1);
	}
	empty[0] = 1;
	sort(all(arr));
	int m = n;
	for (auto qwe: arr) {
		auto p = qwe.second;
		int x = p.first;
		int y = p.second;
		add(x, y);
		int q = get(x);
		if (cntt[q] == (sz(cur[q]) * (sz(cur[q]) - 1) / 2)) {
			//cout << qwe.first << " " << x << " " << y << endl;
			cnt.push_back(empty);
			for (int j: cur[q]) {
				if (used[last[j]] < m) {
					used[last[j]] = m;
					cnt[m] = add(cnt[m], cnt[last[j]]);
				}
				last[j] = m;
			}
			cnt[m][1] = 1;
			m++;
		}
	}
	m--;
	for (int i = 1; i <= min(n, sz(cnt[m]) - 1); i++)
		cout << cnt[m][i] << " ";
	for (int i = 0; i < n + 1 - sz(cnt[m]); i++)
		cout << 0 << " ";
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