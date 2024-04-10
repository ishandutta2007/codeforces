/*

Code for problem E by cookiedoth
Generated 02 Oct 2021 at 04.21 PM


  !











~_^
=_=
\_()_/

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ostream& operator << (ostream& os, pair<int, int> pp) {
	return os << pp.first << ' ' << pp.second;
}

// struct DpHolder {
// 	vector<pair<ll, ll>> val, f;
// 	pair<ll, ll> total;
// 	int n;

// 	pair<ll, ll> prefsum(int pos) {
// 		return total - fget(n - 2 - pos);
// 	}

// 	pair<ll, ll> fget(int pos) {
// 		pair<ll, ll> res;
// 		while (pos >= 0) {
// 			res += f[pos];
// 			pos = (pos & (pos + 1)) - 1;
// 		}
// 		return res;
// 	}

// 	pair<ll, ll> get(int pos) {
// 		return val[n - 1 - pos];
// 	}

// 	void push(pair<ll, ll> new_val) {
// 		val.push_back(new_val);
// 		pair<ll, ll> new_f = total - fget((n & (n + 1)) - 1) + new_val;
// 		total += new_val;
// 		f.push_back(new_f);
// 		val.push_back(new_val);
// 		n++;
// 	}

// 	void add(int pos, pair<ll, ll> delta) {
// 		pos = n - 1 - pos;
// 		val[pos] += delta;
// 		while (pos < n) {
// 			f[pos] += delta;
// 			pos = (pos | (pos + 1));
// 		}
// 	}
// };

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

int diff(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

void subt(int &a, const int &b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

void add(int &a, const int &b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int power(int a, int deg) {
	int res = 1;
	for (; deg; a = mul(a, a), deg >>= 1) {
		if (deg & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

int divide(int a, int b) {
	return mul(a, inverse(b));
}

// struct DpHolder {
// 	int n = 0;

// 	DpHolder() {}

// 	deque<pair<int, int>> arr;

// 	void push(pair<int, int> val) {
// 		arr.push_front(val);
// 		n++;
// 	}

// 	pair<int, int> prefsum(int pos) {
// 		pair<int, int> res;
// 		for (int i = 0; i <= pos && i < arr.size(); ++i) {
// 			add(res.first, arr[i].first);
// 			add(res.second, arr[i].second);
// 		}
// 		return res;
// 	}

// 	void update(int pos, pair<int, int> delta) {
// 		add(arr[pos].first, delta.first);
// 		add(arr[pos].second, delta.second);
// 	}

// 	pair<int, int> get(int pos) {
// 		if (pos < 0) {
// 			return {0, 0};
// 		}
// 		return arr[pos];
// 	}

// 	void augment(int a) {
// 		for (int i = 0; i < arr.size(); ++i) {
// 			add(arr[i].second, mul(arr[i].first, a));
// 		}
// 	}

// 	void print() {
// 		for (int i = 0; i < arr.size(); ++i) {
// 			cerr << arr[i].first << ' ' << arr[i].second << '\n';
// 		}
// 	}
// };

void operator += (pair<int, int>& a, const pair<int, int>& b) {
	add(a.first, b.first);
	add(a.second, b.second);
}

void operator -= (pair<int, int>& a, const pair<int, int>& b) {
	subt(a.first, b.first);
	subt(a.second, b.second);
}

pair<int, int> operator + (const pair<int, int>& a, const pair<int, int>& b) {
	return {sum(a.first, b.first), sum(a.second, b.second)};
}

pair<int, int> operator - (const pair<int, int>& a, const pair<int, int>& b) {
	return {diff(a.first, b.first), diff(a.second, b.second)};
}

struct DpHolder;

map<DpHolder*, int> storage;

int get_id(DpHolder* ptr) {
	if (storage.find(ptr) == storage.end()) {
		storage[ptr] = storage.size();
	}
	return storage[ptr];
}

struct DpHolder {
	vector<pair<int, int>> val, f;
	pair<int, int> total;
	int n = 0, mod = 0;

	pair<int, int> prefsum(int pos) {
		pair<int, int> res = total - fget(n - 2 - pos);
		res.second = sum(res.second, mul(res.first, mod));
		// cerr << "prefsum " << get_id(this) << ' ' << pos << ' ' << res.first << ' ' << res.second << '\n';
		return res;
	}

	pair<int, int> fget(int pos) {
		pair<int, int> res;
		while (pos >= 0) {
			res += f[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	pair<int, int> get(int pos) {
		if (pos < 0) {
			return {0, 0};
		}
		pair<int, int> res = val[n - 1 - pos];
		res.second = sum(res.second, mul(res.first, mod));
		// cerr << "get " << get_id(this) << ' ' << pos << ' ' << res.first << ' ' << res.second << '\n';
		return res;
	}

	void push(pair<int, int> new_val) {
		// cerr << "push " << get_id(this) << ' ' << new_val.first << ' ' << new_val.second << '\n';
		new_val.second = diff(new_val.second, mul(new_val.first, mod));
		// cerr << "kek " << val[0] << ' ' << val[1] << '\n';
		pair<int, int> new_f = total - fget((n & (n + 1)) - 1) + new_val;
		total += new_val;
		f.push_back(new_f);
		val.push_back(new_val);
		n++;
	}

	void update(int pos, pair<int, int> delta) {
		// cerr << "update " << get_id(this) << ' ' << delta.first << ' ' << delta.second << '\n';
		delta.second = diff(delta.second, mul(delta.first, mod));
		total += delta;
		pos = n - 1 - pos;
		val[pos] += delta;
		while (pos < n) {
			f[pos] += delta;
			pos = (pos | (pos + 1));
		}
		// cerr << f[0] << ' ' << f[1] << '\n';
	}

	void augment(int a) {
		// cerr << "augment " << get_id(this) << ' ' << a << '\n';
		add(mod, a);
	}

	void print() {}
};

DpHolder* add_up(DpHolder* from, DpHolder* to) {
	if (from->n > to->n) {
		swap(from, to);
	}
	for (int i = 0; i < from->n; ++i) {
		to->update(i, from->get(i));
	}
	delete from;
	return to;
}

const int MAX_N = 2e5 + 228;
vector<vector<pair<int, int>>> g;
vector<vector<int>> children;
ll a[MAX_N];
int n, k, up_clr[MAX_N], h[MAX_N];

void hang(int v, int pv) {
	h[v] = 0;
	for (auto [v1, clr] : g[v]) {
		if (v1 != pv) {
			up_clr[v1] = clr;
			children[v].push_back(v1);
			hang(v1, v);
			chkmax(h[v], h[v1] + 1);
		}
	}
	sort(all(children[v]), [] (int u, int v) { return h[u] > h[v]; });
}

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	g.resize(n);
	children.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, clr;
		cin >> u >> v >> clr;
		u--;
		v--;
		g[u].emplace_back(v, clr);
		g[v].emplace_back(u, clr);
	}
	hang(0, 0);
	// cerr << "done read\n";
}

int ans;

DpHolder* dfs(int v) {
	if (children[v].empty()) {
		DpHolder* holder = new DpHolder();
		holder->push({1, a[v]});
		return holder;
	}
	vector<DpHolder*> holders(2);
	holders[0] = dfs(children[v][0]);
	// cerr << "holder " << children[v][0] << '\n';
	// holders[0]->print();
	holders[1] = new DpHolder();
	for (int i = 1; i < children[v].size(); ++i) {
		int v1 = children[v][i];
		DpHolder* cur = dfs(v1);
		// cerr << "calculated " << v1 << '\n';
		// cur->print();
		int type = (up_clr[v1] != up_clr[children[v][0]]);
		for (int cost = 0; cost < cur->n; ++cost) {
			if (cost > k) {
				break;
			}
			// cerr << "cost = " << cost << '\n';
			pair<int, int> dp_val = cur->get(cost);
			// cerr << "cost " << dp_val.first << ' ' << dp_val.second << '\n';
			for (int it = 0; it < 2; ++it) {
				int max_cost = k - cost - (type != it);
				// cerr << "max_cost = " << max_cost << '\n';
				// cerr << holders[0]->n << ' ' << holders[1]->n << '\n';
				if (max_cost >= 0) {
					pair<int, int> other = holders[it]->prefsum(max_cost);
					// cerr << "other = " << other.first << ' ' << other.second << '\n';
					int delta = 0;
					add(delta, mul(dp_val.first, other.second));
					add(delta, mul(dp_val.second, other.first));
					add(delta, mul(mul(dp_val.first, other.first), a[v]));
					// cerr << "add " << delta << '\n';
					add(ans, delta);
				}
			}
		}
		holders[type] = add_up(cur, holders[type]);
	}
	pair<int, int> v1 = holders[0]->prefsum(min(holders[0]->n - 1, k));
	pair<int, int> v2 = holders[1]->prefsum(min(holders[1]->n - 1, k));
	int delta = 0;
	// cerr << min(holders[0]->n - 1, k) << '\n';
	// cerr << "opa!\n";
	// cerr << v1.first << ' ' << v1.second << '\n';
	add(delta, mul(v1.first, a[v]));
	add(delta, v1.second);
	add(delta, mul(v2.first, a[v]));
	add(delta, v2.second);
	// cerr << "delta = " << delta << '\n';
	add(ans, delta);
	// cerr << "finish " << v << '\n';
	// holders[0]->print();
	// cerr << "===\n";
	// holders[1]->print();
	holders[up_clr[v] ^ up_clr[children[v][0]] ^ 1]->push({0, 0});
	DpHolder* result = add_up(holders[1], holders[0]);
	result->augment(a[v]);
	result->update(0, {1, a[v]});
	return result;
}

void solve() {
	dfs(0);
	for (int i = 0; i < n; ++i) {
		add(ans, a[i]);
	}
	cout << ans << '\n';
}

void test_DP_holder() {
	DpHolder holder;
	holder.push({1, 8});
	holder.push({0, 0});
	holder.update(0, {1, 9});
	cout << holder.prefsum(0) << '\n';
	// holder.push({1, 2});
	// holder.push({2, 4});
	// cerr << holder.get(0) << '\n';
	// cerr << holder.get(1) << '\n';
}

signed main() {
	fast_io();
	// test_DP_holder();
	read();
	solve();
}