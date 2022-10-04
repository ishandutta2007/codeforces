/*

Code for problem D by cookiedoth
Generated 04 Jan 2020 at 03.32 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

=_=
\_()_/
^_^

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

struct fenwick {
	vector<int> t;
	int n;

	fenwick() {}

	void init(int _n) {
		n = _n;
		t.assign(n, 0);
	}

	void update(int pos, int val) {
		while (pos < n) {
			t[pos] += val;
			pos = (pos | (pos + 1));
		}
	}

	int get(int r) {
		int res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

struct superfenwick {
	fenwick f;

	superfenwick() {}

	void init(int _n) {
		f.init(_n + 1);
	}

	void update(int l, int r) {
		// cerr << "update " << l << " " << r << endl;
		f.update(l, 1);
		f.update(r + 1, -1);
	}

	int get(int pos) {
		// cerr << "get " << pos << endl;
		return f.get(pos);
	}
};

struct guy {
	int l, r, L, R;
};

bool lcmp(guy a, guy b) {
	return a.l < b.l;
}

bool rcmp(guy a, guy b) {
	return a.r < b.r;
}

int n;
vector<guy> a, al, ar;
vector<int> coords;

void no() {
	cout << "NO" << endl;
	exit(0);
}

void check() {
	superfenwick F;
	F.init(coords.size());
	al = a;
	ar = a;
	sort(all(al), lcmp);
	sort(all(ar), rcmp);
	// cerr << "case1" << endl;
	int ptr = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (ptr >= 0 && ar[i].r < al[ptr].l) {
			F.update(al[ptr].L, al[ptr].R);
			ptr--;
		}
		if (F.get(ar[i].L) || F.get(ar[i].R)) {
			no();
		}
	}
	// cerr << "case2" << endl;
	F.init(coords.size());
	ptr = 0;
	for (int i = 0; i < n; ++i) {
		while (ptr < n && ar[ptr].r < al[i].l) {
			F.update(ar[ptr].L, ar[ptr].R);
			ptr++;
		}
		if (F.get(al[i].L) || F.get(al[i].R)) {
			no();
		}
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r, L, R;
		cin >> l >> r >> L >> R;
		a.push_back({l, r, L, R});
		coords.push_back(l);
		coords.push_back(r);
		coords.push_back(L);
		coords.push_back(R);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	for (int i = 0; i < n; ++i) {
		a[i].l = lower_bound(all(coords), a[i].l) - coords.begin();
		a[i].r = lower_bound(all(coords), a[i].r) - coords.begin();
		a[i].L = lower_bound(all(coords), a[i].L) - coords.begin();
		a[i].R = lower_bound(all(coords), a[i].R) - coords.begin();
	}
	// cerr << "a" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << a[i].l << " " << a[i].r << " " << a[i].L << " " << a[i].R << endl;
	// }
	check();
	for (int i = 0; i < n; ++i) {
		swap(a[i].l, a[i].L);
		swap(a[i].r, a[i].R);
	}
	// cerr << "a" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << a[i].l << " " << a[i].r << " " << a[i].L << " " << a[i].R << endl;
	// }
	check();
	cout << "YES" << endl;
}