/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 2000ll * 1000ll * 1000 * 1000ll * 1000 * 1000ll;

int fac(int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++) {
		ans *= i;
	}
	return ans;
}

int C(int n, int k) {
	return (fac(n) / (((fac(n - k) * fac(k)))));
}

void solve() {
	int n;
	cin >> n;
	cout << C(n, n / 2) * ((fac(n / 2 - 1) * fac(n / 2 - 1))) / 2;
}

int32_t main() {
	solve();
}