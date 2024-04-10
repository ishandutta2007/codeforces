/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 107;
pair <int, int> a[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F >> a[i].S;
	}
	sort(a, a + n);
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (x >= a[i].F && x <= a[i].S)
			x = a[i].S;
	}
	cout << (x == m ? "yEs": "nO");
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}