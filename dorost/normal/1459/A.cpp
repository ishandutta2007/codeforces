/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i])
			s1++;
		if (a[i] < b[i])
			s2++;
	}
	cout << (s1 == s2 ? "EQUAL" : (s1 > s2 ? "RED" : "BLUE")) << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}