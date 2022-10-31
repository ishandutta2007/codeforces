#include <iostream>
#include <cassert>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 500008;
int n;
int a[N];

int result[N];

const int OO = 1000000008;

int segtree[4*N];

void build(int ix, int lo, int hi) {
	if (hi - lo == 1) {
		segtree[ix] = lo;
	} else {
		int mid = (hi + lo) / 2;
		build(2*ix, lo, mid);
		build(2*ix+1, mid, hi);

		int li = segtree[2*ix];
		int ri = segtree[2*ix+1];
		segtree[ix] = a[li] < a[ri] ? li : ri;
	}
}

int minIndex(int ix, int lo, int hi, int tlo, int thi) {
	assert(lo <= tlo);
	assert(tlo < thi);
	assert(thi <= hi);

	if (lo == tlo && hi == thi) {
		return segtree[ix];
	} else {
		int mid = (hi + lo) / 2;
		int ret = tlo;

		if (tlo < mid) {
			int li = minIndex(2*ix, lo, mid, tlo, min(mid, thi));
			if (a[li] < a[ret]) ret = li;
		}
		if (thi > mid) {
			int ri = minIndex(2*ix+1, mid, hi, max(mid, tlo), thi);
			if (a[ri] < a[ret]) ret = ri;
		}
		return ret;
	}
}

// return maximum total floors
long long solve(int lo, int hi) {
	if (lo == hi) return 0;
	assert(lo < hi);

	// cerr << lo << "," << hi << "\n";

	int mini = minIndex(1, 0, n, lo, hi);

	result[mini] = a[mini];
	long long base = a[mini];
	long long leftScore = base + solve(lo, mini) + (hi - (mini + 1)) * base;
	long long rightScore = base + (mini - lo) * base + solve(mini + 1, hi);

	// cerr << leftScore << "<>" << rightScore << "\n";

	if (leftScore >= rightScore) {
		// cerr << "resetting " << (mini + 1) << "," << hi << "\n";
		fori (i, mini + 1, hi) result[i] = a[mini];
		return leftScore;
	} else {
		// cerr << "resetting " << lo << "," << mini << "\n";
		fori (i, lo, mini) result[i] = a[mini];
		return rightScore;
	}
}

int main() {
	cin >> n;
	fori (i, 0, n) {
		cin >> a[i];
	}

	build(1, 0, n);

	solve(0, n);
	fori (i, 0, n) {
		if (i) cout << ' ';
		cout << result[i];
	}
}