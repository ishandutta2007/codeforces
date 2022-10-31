#include <iostream>
#include <cassert>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int main() {
	int n;
	long long start;
	cin >> n >> start;
	long long lo = start, hi = start, cost = 0;

	fori (i, 0, n) {
		long long nlo, nhi;
		cin >> nlo >> nhi;

		if (nlo > hi) {
			cost += nlo - hi;
			lo = hi;
			hi = nlo;
		} else if (nhi < lo) {
			cost += lo - nhi;
			hi = lo;
			lo = nhi;
		} else {
			lo = max(lo, nlo);
			hi = min(hi, nhi);
		}

		assert(lo <= hi);
	}

	cout << cost << "\n";
}