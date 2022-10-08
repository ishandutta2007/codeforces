/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	int64_t x, n, r = 0;
	cin >> x >> n;	
	if (n % 4 == 1) r = -n;
	if (n % 4 == 2) r = 1;
	if (n % 4 == 3) r = n + 1;
	if (n % 4 == 0) r = 0;
	cout << x + (x % 2 ? -r : r) << "\n";
	// for (int i = 1; i <= n; i++) {
	// 	x += (x % 2 ? i : -i);
	// 	printf("i=%d x=%d\n", i, x-2);
	// }

// x=0, n=100
// i=5 x=-5
// i=6 x=1
// i=7 x=8
// i=8 x=0

// x=1, n=100
// i=5 x=5
// i=6 x=-1
// i=7 x=-8
// i=8 x=0

// x=2, n=100
// i=5 x=-5
// i=6 x=1
// i=7 x=8
// i=8 x=0

// x=2, n=100
// i=5 x=5
// i=6 x=-1
// i=7 x=-8
// i=8 x=0
}
int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}