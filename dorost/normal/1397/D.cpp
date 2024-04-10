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
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	cout << (*max_element(a, a + n) * 2 > sum || sum % 2 ? "T\n" : "HL\n");
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}