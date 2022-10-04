/*

Code for problem C by cookiedoth
Generated 26 Apr 2021 at 09.40 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

\_()_/
o_O
-_-

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

struct Hasher {
	size_t operator() (const pair<ll, ll>& pp) const {
		return pp.first ^ pp.second;
	}
};

const int MAX_N = 25;
bool found;
ll a[MAX_N][3], vec[3];
int key1, key2;
ll opt = -1e18;

void bruteforce(int l, int r, void (*func)(ll, ll, ll, int)) {
	// cerr << "bruteforce " << l << ' ' << r << '\n';
	for (int key = 0; ; ++key) {
		int t = key;
		fill(vec, vec + 3, 0);
		for (int i = l; i <= r; ++i) {
			int x = t % 3;
			// cerr << "x = " << x << '\n';
			t /= 3;
			for (int j = 0; j < 3; ++j) {
				if (j != x) {
					vec[j] += a[i][j];
				}
			}
		}
		if (t) {
			break;
		}
		// output(vec, vec + 3);
		func(vec[1] - vec[0], vec[2] - vec[1], vec[0], key);
	}
}

unordered_map<pair<ll, ll>, pair<ll, int>, Hasher> have;

void add(ll x, ll y, ll val, int key) {
	auto it = have.find({x, y});
	if (it == have.end()) {
		have[{x, y}] = {val, key};
	} else {
		chkmax(it->second, {val, key});
	}
}

void check(ll x, ll y, ll val, int key) {
	auto it = have.find({-x, -y});
	if (it == have.end()) {
		return;
	}
	if (chkmax(opt, (it->second).first + val)) {
		// cerr << "opa!\n";
		// cerr << (it->first).first << ' ' << (it->first).second << ' ' << (it->second).first << ' ' << (it->second).second << '\n';
		key1 = (it->second).second;
		key2 = key;
		found = true;
	}
}

int n, n1, n2;

void printAns() {
	// cerr << "opt = " << opt << '\n';
	if (found == false) {
		cout << "Impossible" << '\n';
		return;
	}
	vector<int> out;
	for (int i = 0; i < n1; ++i) {
		out.push_back(key1 % 3);
		key1 /= 3;
	}
	for (int i = 0; i < n2; ++i) {
		out.push_back(key2 % 3);
		key2 /= 3;
	}
	// cerr << "out\n";
	// output(all(out));
	for (int i = 0; i < n; ++i) {
		if (out[i] == 0) {
			cout << "MW\n";
		} else if (out[i] == 1) {
			cout << "LW\n";
		} else {
			cout << "LM\n";
		}
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> a[i][j];
		}
	}
	n1 = n / 2, n2 = n - n1;
	bruteforce(0, n1 - 1, add);

	bruteforce(n1, n - 1, check);
	printAns();
}