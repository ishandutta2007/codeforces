/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 402;
bool f[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 2 * n + 2; i <= 4 * n; i += 2) 
		cout << i << ' ';
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}