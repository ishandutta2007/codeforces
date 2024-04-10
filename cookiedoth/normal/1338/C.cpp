/*

Code for problem C by cookiedoth
Generated 12 Apr 2020 at 05.25 PM










(@)(@)(@)(@)(@)

o_O
^_^
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

const ll MX = 2e16;
ll n;

vector<int> perm = {0, 2, 3, 1};

struct segment {
	ll l, r, L, R, len, L1;	
};

vector<segment> segs;

void gen_segs() {
	ll l = 0, r = 0, L = 1, R = 1, len = 1;
	segs.push_back({l, r, L, R, len, R + 1});
	while (r < MX) {
		L *= 4;
		len *= 4;
		l = r + 1;
		r = l + len - 1;
		R = L + len - 1;
		segs.push_back({l, r, L, R, len, R + 1});
	}
}

int get_seg_id(ll pos) {
	for (int i = 0; i < segs.size(); ++i) {
		if (segs[i].l <= pos && pos <= segs[i].r) {
			return i;
		}
	}
	assert(0);
}

ll get_first(ll pos) {
	int seg_id = get_seg_id(pos);
	return segs[seg_id].L + (pos - segs[seg_id].l);
}

ll get_second(ll pos, int seg_id) {
	// cerr << "get_second " << pos << " " << seg_id << endl;
	if (seg_id == 0) {
		return 2;
	} else {
		ll D = segs[seg_id].len / 4;
		ll sub_id = (pos - segs[seg_id].l) / D;
		ll sub_pos = (pos - segs[seg_id].l) % D;
		// cerr << "sub_id " << sub_id << " " << sub_pos << endl;
		// cerr << segs[seg_id - 1].L1 << endl;
		ll res = segs[seg_id].L1 + D * (ll)perm[sub_id] + get_second(segs[seg_id - 1].l + sub_pos, seg_id - 1) - segs[seg_id - 1].L1;
		return res;
	}
}

ll get_second(ll pos) {
	int seg_id = get_seg_id(pos);
	return get_second(pos, seg_id);
}

ll get_third(ll pos) {
	return get_first(pos) ^ get_second(pos);
}

void solve() {
	cin >> n;
	n--;
	ll triple_id = n / 3;
	ll pos = n % 3;
	ll ans;
	if (pos == 0) {
		ans = get_first(triple_id);
	}
	if (pos == 1) {
		ans = get_second(triple_id);
	}
	if (pos == 2) {
		ans = get_third(triple_id);
	}
	cout << ans << "\n";
}

signed main() {
	fast_io();
	gen_segs();
	// cerr << "segs" << endl;
	// for (auto seg : segs) {
	// 	cerr << seg.l << " " << seg.r << " " << seg.len << " " << seg.L << " " << seg.R << " " << seg.L1 << endl;
	// }
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}