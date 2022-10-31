#include <iostream>
#include <cassert>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 1008;
int n;
int a[N];

int result[N];

const int OO = 1000000008;

// return maximum total floors
long long solve(int lo, int hi) {
	if (lo == hi) return 0;
	assert(lo < hi);

	// cerr << lo << "," << hi << "\n";

	int mini = lo;
	fori (i, lo, hi) {
		if (a[i] < a[mini]) {
			mini = i;
		}
	}

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

	solve(0, n);
	fori (i, 0, n) {
		if (i) cout << ' ';
		cout << result[i];
	}
}