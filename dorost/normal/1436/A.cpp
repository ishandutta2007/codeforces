/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

void solve() {
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	cout << (sum == m ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}