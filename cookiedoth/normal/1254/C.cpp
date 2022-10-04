/*

Code for problem C by cookiedoth
Generated 20 Nov 2019 at 08.55 P



10%

30%

50%

70%

100%

o_O
-_-
z_z

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
}

struct pt {
	ll x, y;
	pt (ll _x, ll _y): x(_x), y(_y) {}
	pt (): x(0), y(0) {}
};

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

ll operator ^ (pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

#ifdef TESTING

vector<pt> a;

ll get_sign(int i, int j, int k) {
	assert(i != j && i != k && j != k);
	ll P = (a[j] - a[i]) ^ (a[k] - a[i]);
	if (P > 0) {
		return 1;
	} else {
		return -1;
	}
}

ll get_S(int i, int j, int k) {
	assert(i != j && i != k && j != k);
	ll P = (a[j] - a[i]) ^ (a[k] - a[i]);
	return abs(P);
}

#else

ll get_sign(int i, int j, int k) {
	cout << "2 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	ll res;
	cin >> res;
	return res;
}

ll get_S(int i, int j, int k) {
	cout << "1 " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	ll res;
	cin >> res;
	return res;
}

#endif

const int mx = 1010;
int n;
ll cross[mx];

ll cross_cmp(int i, int j) {
	return cross[i] < cross[j];
}

vector<int> restore(int s, int t, vector<int> v) {
	// cerr << "restore " << s << " " << t << endl;
	// output(all(v));
	int len = v.size();
	if (len == 0) {
		return vector<int> ();
	}
	int max_S = 0;
	for (int i = 1; i < len; ++i) {
		if (cross[v[i]] > cross[v[max_S]]) {
			max_S = i;
		}
	}
	// cerr << "max_S = " << max_S << endl;
	vector<int> inc, dec;
	for (int i = 0; i < len; ++i) {
		if (i == max_S || get_sign(0, v[max_S], v[i]) == 1) {
			inc.push_back(v[i]);
		} else {
			dec.push_back(v[i]);
		}
	}

	// cerr << "inc" << endl;
	// output(all(inc));

	sort(rall(inc), cross_cmp);
	sort(all(dec), cross_cmp);
	if (inc.size() >= 2) {
		int L1 = inc[0];
		int L2 = inc[1];
		if (get_sign(0, L1, L2) != 1) {
			swap(inc[0], inc[1]);
		}
	}
	vector<int> res;
	for (auto x : dec) {
		res.push_back(x);
	}
	for (auto x : inc) {
		res.push_back(x);
	}

	// cerr << "res" << endl;
	// output(all(res));

	return res;
}

signed main() {
	fast_io();
	cin >> n;

	#ifdef TESTING
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	#endif

	for (int i = 2; i < n; ++i) {
		cross[i] = get_S(0, 1, i) * get_sign(0, 1, i);
	}

	//0 - left, 1 - right
	vector<int> up, down;
	for (int i = 2; i < n; ++i) {
		if (cross[i] > 0) {
			up.push_back(i);
		} else {
			down.push_back(i);
			cross[i] = -cross[i];
		}
	}

	// cerr << "up" << endl;
	// output(all(up));
	// cerr << "down" << endl;
	// output(all(down));

	vector<int> a = restore(0, 1, up);
	vector<int> b = restore(1, 0, down);
	vector<int> ans = {0};
	for (auto x : b) {
		ans.push_back(x);
	}
	ans.push_back(1);
	for (auto x : a) {
		ans.push_back(x);
	}

	cout << "0 ";
	for (auto x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}