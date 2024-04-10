/*

Code for problem G by cookiedoth
Generated 06 Sep 2022 at 12.25 PM
The Moon is Waxing Gibbous (82% of Full)


       !
       !
       ^
      / \
     /___\
    |=   =|
    |     |
    |     |
    |     |
    |     |
    |     |
    |     |
    |     |
    |     |
    |     |
   /|##!##|\
  / |##!##| \
 /  |##!##|  \
|  / ^ | ^ \  |
| /  ( | )  \ |
|/   ( | )   \|
    ((   ))
   ((  :  ))
   ((  :  ))
    ((   ))
     (( ))
      ( )
       .
       .
       .

^_^
~_^
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#include <array>
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

const int MOD = 998244353;

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


const int MAX_N = 2e5 + 228;
int n, a[MAX_N], b[MAX_N], target, ans, max_val, mult[5 * MAX_N];
vector<pair<int, int>> vp;

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		vp.emplace_back(a[i], b[i]);
	}
	sort(all(vp));
	max_val = vp[n - 1].first;
	// cerr << "vp\n";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << vp[i].first << ' ' << vp[i].second << '\n';
	// }
}

void solve(bool eq) {
	// cerr << "solve " << eq << '\n';
	int lt, rt, smaller = 0;
	if (eq) {
		lt = max_val;
		rt = max_val;
	} else {
		lt = max_val + 1;
		rt = 5 * n;
	}
	fill(mult, mult + 5 * n + 1, 1);
	int row = 0, drow = 0, cur = 1;
	for (int i = 0; i < n; ++i) {
		if (i && vp[i].first != vp[i - 1].first) {
			smaller = i;
		}
		row++;
		if (i && vp[i] != vp[i - 1]) {
			row = 1;
		}
		drow++;
		if (i && vp[i].first != vp[i - 1].first) {
			drow = 1;
		}
		// cerr << vp[i].first << ' ' << vp[i].second  << " i, row, drow " << i << ' ' << row << ' ' << drow << '\n';
		if (vp[i].second == 0) {
			chkmax(lt, vp[i].first);
			chkmin(rt, vp[i].first + smaller);
			// cerr << "row = " << row << '\n';
			if (eq && vp[i].first == max_val) {
				cur = mul(cur, row);
			} else {
				cur = mul(cur, row);
			}
			// cerr << "rt = " << rt << '\n';
		} else {
			if ((!eq || vp[i].first != max_val) && row > 1) {
				return;
			}
			if (eq && vp[i].first == max_val) {
				cur = mul(cur, i + 1);
			} else {
				int bigger = n - 1 - i;
				chkmax(lt, vp[i].first + bigger);
				chkmin(rt, vp[i].first + bigger + smaller);
				// cerr << "val, bigger, smaller = " << vp[i].first << ' ' << bigger << ' ' << smaller << '\n';
				// cerr << "row = " << row << '\n';
				cur = mul(cur, row);
				if ((bigger + smaller) % 2 == 0) {
					int p = (bigger + smaller) / 2;
					if (p >= 0 && p <= smaller) {
						// cerr << "p = " << p << '\n';
						int target = vp[i].first + smaller - p;
						// cerr << "mult target " << target << ' ' << drow << ' ' << row << '\n';
						mult[target] = mul(mult[target], mul(drow, inverse(row)));
					}
				}
				// cerr << "rt = " << rt << '\n';
			}
		}
	}
	if (lt <= rt) {
		int tot_mult = 0;
		for (int i = lt; i <= rt; ++i) {
			add(tot_mult, mult[i]);
		}
		add(ans, mul(cur, tot_mult));
	}
	// cerr << "lt, rt = " << lt << ' ' << rt << '\n';
	// cerr << "ans = " << ans << '\n';
}

signed main() {
	fast_io();
	read();
	solve(false);
	solve(true);
	cout << ans << '\n';
}