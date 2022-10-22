/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1) {
		if (a[0] <= 1) 
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	sort(a, a + n);
	cout << (a[n - 2] + 1 >= a[n - 1] ? "YES\n" : "NO\n");
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}