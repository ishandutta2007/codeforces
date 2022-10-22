/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
int a[N], n;

bool check(int x) {
	if (x > n / 2) {
		return false;
	}
	for (int i = 0; i < x; i++) {
		if (a[i] * 2 > a[n - x + i]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << n - l;
}