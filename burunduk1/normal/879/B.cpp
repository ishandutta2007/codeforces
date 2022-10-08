#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int64_t n, k;

int solve() {
	int a[n+n];
	forn(i, n) cin >> a[i];

	int m = 0; //  i-
	forn(i, n) {
		// [i,i+n)
		if (a[i] > a[i + 1]) {
			m++;
			a[i + n] = a[i + 1];
			a[i + 1] = a[i];
		} else {
			m = 1;
			a[i + n] = a[i];
		}
		
		// ,     -- a[i+1]
		if (m >= k) 
			return a[i + 1];
	}
	return a[n];
}

int main() {
	while (cin >> n >> k)
		cout << solve() << endl;
}