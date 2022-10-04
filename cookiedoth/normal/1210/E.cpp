/*

Code for problem E by cookiedoth
Generated 22 Sep 2019 at 01.14 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

o_O
^_^
~_^

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

const int mx = 123;
int n, k, p_cnt, mult[mx][mx];
vector<vector<int> > P;
map<vector<int>, int> id;

void init() {
	vector<int> p(k);
	iota(all(p), 0);

	do {
		id[p] = P.size();
		P.push_back(p);
	} while (next_permutation(all(p)));

	p_cnt = P.size();
	for (int i = 0; i < p_cnt; ++i) {
		for (int j = 0; j < p_cnt; ++j) {
			vector<int> res(k);
			for (int x = 0; x < k; ++x) {
				res[x] = P[i][P[j][x]];
			}
			mult[i][j] = id[res];
			//cerr << mult[i][j] << " ";
		}
		//cerr << endl;
	}
}

bool operator < (const bitset<mx> &a, const bitset<mx> &b) {
	for (int i = 0; i < mx; ++i) {
		if (a[i] < b[i]) {
			return 1;
		}
		if (a[i] > b[i]) {
			return 0;
		}
	}
	return 0;
}

unordered_map<bitset<mx>, vector<bitset<mx> > > go;

bitset<mx> get_go(bitset<mx> a, int p) {
	if (go.find(a) == go.end()) {
		go[a] = vector<bitset<mx> > (p_cnt);
	}
	if (go[a][p].any()) {
		return go[a][p];
	}
	bitset<mx> cur = a, used = a;
	queue<int> q;
	q.push(p);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cur[v] = 1;
		for (int i = 0; i < p_cnt; ++i) {
			if (cur[i]) {
				int v1 = mult[i][v], v2 = mult[v][i];
				if (!used[v1]) {
					used[v1] = 1;
					q.push(v1);
				}
				if (!used[v2]) {
					used[v2] = 1;
					q.push(v2);
				}
			}
		}
	}
	return go[a][p] = cur;
}

vector<int> a;
ll ans;

signed main() {
	fast_io();
	cin >> n >> k;
	a.resize(n);
	init();

	//cerr << "init" << endl;

	for (int i = 0; i < n; ++i) {
		vector<int> cur_p(k);
		for (int j = 0; j < k; ++j) {
			cin >> cur_p[j];
			cur_p[j]--;
		}
		a[i] = id[cur_p];
	}

	/*cerr << "a" << endl;
	output(all(a));*/

	vector<pair<bitset<mx>, int> > store;
	for (int i = 0; i < n; ++i) {
		vector<pair<bitset<mx>, int> > new_store;

		bitset<mx> nxt;
		nxt[0] = 1;
		nxt = get_go(nxt, a[i]);

		bitset<mx> last;
		for (auto pp : store) {
			bitset<mx> cur = get_go(pp.first, a[i]);
			if (cur != last) {
				new_store.emplace_back(cur, pp.second);
				last = cur;
			}
		}
		if (nxt != last) {
			new_store.emplace_back(nxt, i);
		}

		store = new_store;

		/*cerr << "new_store" << endl;
		for (auto pp : new_store) {
			for (int i = 0; i < 10; ++i) {
				cerr << pp.first[i];
			}
			cerr << " " << pp.second << endl;
		}*/

		for (int j = 0; j < new_store.size(); ++j) {
			ll popcnt = new_store[j].first.count();
			ans += popcnt * (ll)(i - new_store[j].second + 1);
			if (j < (int)new_store.size() - 1) {
				ans -= popcnt * (ll)(i - new_store[j + 1].second + 1);
			}
		}
	}

	cout << ans << endl;
}