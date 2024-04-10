/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int fac(int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++) {
		ans *= i;
	}
	return ans;
}
 
int C(int k, int n) {
	int ans = 1;
	for (int i = n; i >= n - k + 1; i--) {
		ans *= i;
	}
	for (int i = 1; i <= k; i++) {
		ans /= i;
	}
	return ans;
}
 
int32_t main() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	int a[5] = {1, 0, 1, 2, 9};
	for (int i = 0; i <= k; i++) {
		ans += C(i, n) * a[i];
	}
	cout << ans;
}