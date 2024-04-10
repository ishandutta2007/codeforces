/**

Inv(a) = -  = -  {i,j} : i < j, a[i] > a[j]

if (a[i] > a[i+1])
	swap(a[i], a[i+1]) // Inv(a)--

InsertionSort = O(n^2) = n + Inv(a)

forn(i, n) {
	int x = a[j], j;
	for (j = i; j > 0 && a[j - 1] > x; j--)
		a[j] = a[j - 1];
	a[j] = x;
}

*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(), a.end()

// namespace x {
// 	using std::swap;
// 	using namespace std;
// };

const int N = 5e4;

int a[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int tn;
	cin >> tn;
 	while (tn--) {
 		int n;
 		cin >> n;
 		forn(i, n) cin >> a[i];

 		int cnt = 0;
 		// printf("n = %d\n", n);
		forn(i, n) {
			int x = a[i];
			int j = upper_bound(a, a + i, x) - a;
			// forn(z, i) printf("%d ", a[z]);
			// printf(": x = %d, j = %d\n", x, j);
			// a[j] > x
			// [j, i) --> [j+1,i]
			memmove(a + j + 1, a + j, sizeof(a[0]) * (i - j));
			// for (j = i; j > 0 && a[j - 1] > x; j--)
			// 	a[j] = a[j - 1];
			a[j] = x, cnt += i - j;
		}
		cout << (cnt >= (int64_t)n * (n - 1) / 2 ? "NO\n" : "YES\n");
 	}
}