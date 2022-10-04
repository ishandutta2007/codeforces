/*

Code for problem C by cookiedoth
Generated 03 Apr 2020 at 06.55 PM


  !











-_-
z_z
=_=

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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

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

const int MAX_H = 20;
const int MX = 1 << MAX_H;
int N, N1, h, g, a[MX], opt[MX], used[MX], who[MX], _who[MX];
vector<int> restore;
ll ans;

void F(int pos) {
	// cerr << "_F " << pos << endl;
	// cerr << a[pos * 2] << " " << a[pos * 2 + 1] << endl;
	if (pos >= N / 2 || (a[pos * 2] == 0 && a[pos * 2 + 1] == 0)) {
		who[pos] = -1;
		a[pos] = 0;
	} else {
		if (a[pos * 2] > a[pos * 2 + 1]) {
			// cerr << "move " << pos * 2 << endl;
			a[pos] = a[pos * 2];
			_who[who[pos * 2]] = pos;
			who[pos] = who[pos * 2];
			F(pos * 2);
		} else {
			// cerr << "move " << 2 * pos + 1 << endl;
			// cerr << who[2 * pos + 1] << endl;
			// cerr << a[2 * pos + 1] << endl;
			// cerr << a[2 * pos] << endl;
			a[pos] = a[pos * 2 + 1];
			_who[who[pos * 2 + 1]] = pos;
			who[pos] = who[pos * 2 + 1];
			F(pos * 2 + 1);
		}
	}
}

void fetch(int from, int to) {
	// cerr << "fetch " << from << " " << to << endl;
	// cerr << who[14] << " " << who[7] << " " << who[3] << " " << who[1] << endl;
	int cur = from, val = who[cur];
	while (cur != to) {
		// cerr << "====dest " << (cur >> 1) << endl;
		while (who[cur >> 1] != val) {
			restore.push_back(cur >> 1);
			_who[who[cur >> 1]] = -1;
			who[cur >> 1] = -1;
			// cerr << "F " << (cur >> 1) << endl;
			F(cur >> 1);
			// output(who, who + N);
		}
		cur >>= 1;
	}
}

void checkout(int v) {
	int u = v;
	while (u >= N1) {
		u >>= 1;
	}
	while (u && used[u] == 1) {
		u >>= 1;
	}
	if (u != 0 && (u >= N1 / 2 || (used[u * 2] && used[u * 2 + 1]))) {
		if (u >= N1 / 2 || (a[v] > a[opt[u * 2]] && a[v] > a[opt[u * 2 + 1]])) {
			used[u] = 1;
			opt[u] = v;
			ans += a[v];
		}
	}
}

void solve() {
	ans = 0;
	restore.clear();
	cin >> h >> g;
	N = (1 << h);
	N1 = (1 << g);
	for (int i = 1; i < N; ++i) {
		cin >> a[i];
	}
	vector<vector<int> > leaves;
	for (int i = 1; i < N; ++i) {
		leaves.push_back({a[i], i});
	}
	sort(all(leaves));
	fill(used, used + N, 0);
	for (auto pp : leaves) {
		checkout(pp[1]);
	}
	iota(who, who + N, 0);
	iota(_who, _who + N, 0);
	for (int i = 1; i < N1; ++i) {
		// cerr << "mmm " << opt[i] << endl;
		assert(_who[opt[i]] != -1);
		fetch(_who[opt[i]], i);
	}
	for (int i = N; i > N1; --i) {
		if (who[i] != -1) {
			F(i);
		}
	}
	cout << ans << "\n";
	output(all(restore), cout);
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}