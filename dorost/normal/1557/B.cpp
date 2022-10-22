/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
pair <int, int> a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i].F, a[i].S = i;
	int need = 0;
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		if (a[i].S + 1 != a[i + 1].S) {
			need++;
		}
	}
//	cout << need << '\n';
	cout << (need + 1 <= k ? "YES " : "NO "); 
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}