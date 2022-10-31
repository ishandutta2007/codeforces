#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

// [1,5]
// [1,2] and [4,5]; a[3] = 1
// [2,2] and [4,5]; a[1] = 2
// [2,2] and [5,5]; a[4] = 3

// [lo, hi)
typedef struct Segment {
	int lo;
	int hi;

	bool operator<(const Segment & other) const {
		if (hi - lo != other.hi - other.lo) {
			return hi - lo < other.hi - other.lo;
		}
		return lo > other.lo;
	}
} Segment;

priority_queue<Segment> zeroes;

int a[200008];

void tc() {
	int n;
	cin >> n;

	zeroes.push(Segment { .lo = 0, .hi = n });

	fori (i, 1, n+1) {
		// longest, of those leftmost
		Segment s = zeroes.top();
		zeroes.pop();
		int half = s.lo + (s.hi - s.lo - 1) / 2;
		// "cut out" [half, half + 1)
		a[half] = i;
		if (s.lo < half) {
			zeroes.push(Segment { .lo = s.lo, .hi = half });
		}

		if (half + 1 < s.hi) {
			zeroes.push(Segment { .lo = half + 1, .hi = s.hi });
		}
	}

	assert(zeroes.empty());

	fori (i, 0, n) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << "\n";
}

int main() {
	int tcn;
	cin >> tcn;
	fori (i, 0, tcn) tc();
}