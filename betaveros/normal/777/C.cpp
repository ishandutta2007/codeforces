#include <iostream>
#include <map>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int nRows, nCols;
int a[100008]; // i guess we'll stuff it in row major

int cs[100008];
// element maps to number of <='s up to and including it
map<pair<int, int>, bool> memo;

// if (2, 4), we want to see if 1 <= 2 and 2 <= 3,
// which is cumsum[3] - cumsum[1].
bool innerSolve(int lo, int hi) {
	fori (j, 0, nCols) {
		if (cs[(hi - 1) * nCols + j] - cs[(lo - 1) * nCols + j] == hi - lo) return true;
	}
	return false;
}

bool solve(int lo, int hi) {
	if (memo.count({lo, hi})) return memo[{lo, hi}];

	return memo[{lo, hi}] = innerSolve(lo, hi);
	
}

int main() {
	cin >> nRows >> nCols;
	fori (i, 0, nRows) {
		fori (j, 0, nCols) {
			cin >> a[i * nCols + j];
		}
	}

	fori (j, 0, nCols) {
		cs[j] = 0;
		fori (i, 1, nRows) {
			cs[i * nCols + j] = cs[(i-1) * nCols + j] + (a[(i-1) * nCols + j] <= a[i * nCols + j]);
		}
	}

	int nQueries;
	cin >> nQueries;

	fori (i, 0, nQueries) {
		int lo, hi;
		cin >> lo >> hi;
		cout << (solve(lo, hi) ? "Yes\n" : "No\n");
	}
}