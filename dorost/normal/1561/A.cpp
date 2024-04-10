/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (is_sorted(a, a + n)) {
		cout << 0 << ' ';
		return;
	}
	for (int i = 0; ; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n - 1; j += 2) {
				if (a[j + 1] < a[j])
					swap(a[j], a[j + 1]);
			}
		} else {
			for (int j = 1; j < n - 1; j += 2) {
				if (a[j + 1] < a[j])
					swap(a[j], a[j + 1]);
			}
		}
		ans++;
		if (is_sorted(a, a + n)) {
			break;
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}