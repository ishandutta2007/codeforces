/*

Code for problem F by cookiedoth
Generated 26 May 2020 at 06.03 PM


 ] 
 
Il] 


\_()_/
^_^
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

const __int128 BINF = 1e20;

__int128 C(__int128 n, __int128 k) {
	if (k > n) {
		return 0;
	}
	__int128 res = 1;
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (__int128)(i + 1);
		if (res >= BINF) {
			return BINF;
		}
	}
	return res;
}

const int mx = 2e5 + 228;

__int128 temp[mx];
ll a[mx], b[mx];
ll sum_a;
int n;

int subt(ll *arr, ll k) {
	// cerr << "subt" << endl;
	// output(arr, arr + n);
	// cerr << "k = " << k << endl;
	fill(temp, temp + n, 0);
	for (int i = 0; i < n; ++i) {
		for (int delta = 0; delta <= min((ll)i, k); ++delta) {
			__int128 curC = C(k, delta);
			if (curC == BINF) {
				return 0;
			}
			if (delta % 2 == 1) {
				curC *= -1;
			}
			temp[i] += (curC * arr[i - delta]);
		}
		if (temp[i] < 1) {
			return 0;
		}
	}
	__int128 sum_temp = 0;
	for (int i = 0; i < n; ++i) {
		sum_temp += temp[i];
	}
	if (sum_temp >= sum_a) {
		copy(temp, temp + n, arr);
		return 1;
	} else {
		return 0;
	}
}

vector<pair<int, ll> > op;

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum_a += a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
}

int reversed;

int check_eq() {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

int chec_rev_eq() {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[n - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

int check_monotone() {
	for (int i = 0; i < n - 1; ++i) {
		if (!(b[i] < b[i + 1])) {
			return 0;
		}
	}
	return 1;
}

const ll INF = 1e18;

void process() {
	if (n == 1 && a[0] != b[0]) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	while (true) {
		if (check_eq()) {
			break;
		}
		if (chec_rev_eq()) {
			op.emplace_back(1, 0);
			break;
		}
		if (!check_monotone()) {
			if (reversed == 0) {
				reversed = 1;
				op.emplace_back(1, 0);
				reverse(b, b + n);
				continue;
				// cerr << "reversed" << endl;
			} else {
				cout << "IMPOSSIBLE" << endl;
				exit(0);
			}
		}
		reversed = 0;
		int deg2 = 0;
		ll op_cnt = 0;
		int flag = 0;
		while (deg2 >= 0) {
			int res = subt(b, 1 << deg2);
			if (!res) {
				flag = 1;
			} else {
				op_cnt += (1 << deg2);
			}
			if (flag) {
				deg2--;
			} else {
				deg2++;
			}
		}
		op.emplace_back(0, op_cnt);
		if (op_cnt == 0) {
			cout << "IMPOSSIBLE" << endl;
			exit(0);
		}
		// cerr << "op_cnt = " << op_cnt << endl;
	}
}

int OP_TRESHOLD = 2e5;

void print() {
	ll sum_op = 0;
	for (auto pp : op) {
		if (pp.first == 0) {
			sum_op += pp.second;
		}
	}
	if (sum_op > OP_TRESHOLD) {
		cout << "BIG" << endl;
		cout << sum_op << endl;
	} else {
		cout << "SMALL" << endl;
		reverse(all(op));
		string ans;
		for (auto pp : op) {
			if (pp.first == 0) {
				for (int it = 0; it < pp.second; ++it) {
					ans.push_back('P');
				}
			} else {
				ans.push_back('R');
			}
		}
		cout << ans.size() << endl;
		cout << ans << endl;
	}
}

signed main() {
	fast_io();
	read();
	process();
	print();
}