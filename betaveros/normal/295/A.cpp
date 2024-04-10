#include <cassert>
#include <iostream>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int n, nOps, nMetaops;

const int N = 100008;
long long a[N];

struct Op {
	int lo;
	int hi;
	int delta;
};

Op ops[N];

int opc[N];

long long dd[N];

int main() {
	cin >> n >> nOps >> nMetaops;
	fori (i, 0, n) { cin >> a[i]; }

	fori (i, 0, nOps) {
		cin >> ops[i].lo >> ops[i].hi >> ops[i].delta;
		ops[i].lo--;
	}

	fori (i, 0, nMetaops) {
		int lo, hi;
		cin >> lo >> hi;
		lo--;
		opc[lo] += 1;
		opc[hi] -= 1;
	}

	fori (i, 1, nOps + 1) {
		opc[i] += opc[i-1];
	}
	assert(opc[nOps] == 0);

	fori (i, 0, nOps) {
		dd[ops[i].lo] += ((long long) opc[i]) * ops[i].delta;
		dd[ops[i].hi] -= ((long long) opc[i]) * ops[i].delta;
	}

	long long totalDelta = 0;
	fori (i, 0, n) {
		totalDelta += dd[i];
		a[i] += totalDelta;
		if (i) cout << ' ';
		cout << a[i];
	}
	assert(totalDelta + dd[n] == 0);
	cout << "\n";
}