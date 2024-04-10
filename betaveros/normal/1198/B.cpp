#include <iostream>
#include <cassert>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int n, nOperations;
const int N = 200008;

typedef int SegTreeElt;
struct SegTree {
	int size;
	SegTreeElt a[4*N];
	void _push(int ix) {
		maxify(a[2*ix], a[ix]);
		maxify(a[2*ix+1], a[ix]);
		a[ix] = 0;
	}

	// ========================================

	int _pointQuery(int ix, int lo, int hi, int target) {
		assert(lo <= target);
		assert(target < hi);
		if (hi - lo == 1) {
			return a[ix];
		} else {
			_push(ix);
			int mid = (lo + hi + 1) / 2;
			if (target < mid) { return _pointQuery(2*ix  , lo, mid, target); }
			else              { return _pointQuery(2*ix+1, mid, hi, target); }
		}
	}
	int pointQuery(int target) { return _pointQuery(1, 0, size, target); }

	// ========================================

	void _pointModify(int ix, int lo, int hi, int target, int value) {
		assert(lo <= target);
		assert(target < hi);
		if (hi - lo == 1) {
			assert(lo == target);
			a[ix] = value;
		} else {
			_push(ix);
			int mid = (lo + hi + 1) / 2;
			if (target < mid) { _pointModify(2*ix    , lo, mid, target, value); }
			else              { _pointModify(2*ix + 1, mid, hi, target, value); }
		}
	}
	void pointModify(int target, int value) { _pointModify(1, 0, size, target, value); }

	void allMax(int value) { maxify(a[1], value); }
};

SegTree st;

int main() {
	cin >> n;
	st.size = n;

	fori (i, 1, n+1) {
		int val;
		cin >> val;
		st.pointModify(i - 1, val);
	}

	cin >> nOperations;
	fori (i, 0, nOperations) {
		int type, person, value;
		cin >> type;
		switch (type) {
			case 1:
				cin >> person >> value;
				st.pointModify(person - 1, value);
				break;
			case 2:
				cin >> value;
				st.allMax(value);
				break;
			default:
				throw logic_error("bad");
		}
	}

	fori (i, 1, n + 1) {
		if (i > 1) cout << ' ';
		cout << st.pointQuery(i - 1);
	}
	cout << "\n";
}