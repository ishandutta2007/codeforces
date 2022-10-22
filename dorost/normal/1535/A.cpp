/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	set <int> st1, st2;
	st1.insert(max(a[0], a[1]));
	st1.insert(max(a[2], a[3]));
	sort(a, a + 4);
	st2.insert(a[2]);
	st2.insert(a[3]);
	if (*st1.begin() == *st2.begin() && *st1.rbegin() == *st2.rbegin()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}