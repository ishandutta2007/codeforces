/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 20123;
int a[N];

void solve() {
	int n, t;
	cin >> n >> t;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i], sum += (86400 - a[i]);
		if (sum >= t) {
			cout << i + 1;
			return;
		}
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}