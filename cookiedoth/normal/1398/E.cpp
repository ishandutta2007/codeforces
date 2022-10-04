/*

Code for problem E by cookiedoth
Generated 14 Aug 2020 at 06.02 PM



10%

30%

50%

70%

100%

>_<
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

int n, cur_el, li, real_li;
ll sum, sum_upper;
multiset<int> upper, lower, ones;

void balance() {
	// cerr << "balance" << endl;
	real_li = max(0, min(li, cur_el - 1));
	// cerr << "real_li " << real_li << " " << upper.size() << endl;
	while (upper.size() < real_li) {
		// cerr << "val " << (*prev(lower.end())) << endl;
		sum_upper += (*prev(lower.end()));
		upper.insert(*prev(lower.end()));
		lower.erase(prev(lower.end()));
	}
	while (upper.size() > real_li) {
		// cerr << "kek" << endl;
		sum_upper -= (*upper.begin());
		lower.insert(*upper.begin());
		upper.erase(upper.begin());
	}
}

ll get() {
	ll val = -1;
	if (!ones.empty()) {
		val = (*ones.begin());
		if (upper.find(val) != upper.end()) {
			upper.erase(upper.find(val));
			sum_upper -= val;
		} else {
			lower.erase(lower.find(val));
		}
	}
	// cerr << "val = " << val << endl;
	// cerr << "sum = " << sum << endl;
	// cerr << "sum_upper = " << sum_upper << endl;
	// output(all(upper));
	// output(all(lower));
	// cerr << "/" << endl;
	balance();
	ll res = sum_upper + sum;
	if (val != -1) {
		if (!upper.empty() && val > (*upper.begin())) {
			upper.insert(val);
			sum_upper += val;
		} else {
			lower.insert(val);
		}
	}
	return res;
}

void insert(int type, int d) {
	// cerr << "insert " << type << " " << d << endl;
	cur_el++;
	li += type;
	sum += d;
	if (type == 1) {
		ones.insert(d);
	}
	if (!upper.empty() && d > (*upper.begin())) {
		upper.insert(d);
		sum_upper += d;
	} else {
		lower.insert(d);
	}
}

void erase(int type, int d) {
	cur_el--;
	li -= type;
	sum -= d;
	if (type == 1) {
		ones.erase(ones.find(d));
	}
	auto it = upper.find(d);
	if (it != upper.end()) {
		upper.erase(it);
		sum_upper -= d;
	} else {
		lower.erase(lower.find(d));
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int type, d;
		cin >> type >> d;
		if (d > 0) {
			insert(type, d);
		} else {
			erase(type, -d);
		}
		ll res = get();
		cout << res << '\n';
	}
}