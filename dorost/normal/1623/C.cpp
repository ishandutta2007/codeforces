/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int n, a[N], b[N];

bool is_valid(int x) {
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] < x) {
			return false;
		}
		if (i <= 1)
			continue;
		int d = min(a[i], (b[i] - x)) / 3;
		b[i] -= 3 * d;
		if (b[i] < 0)
			return false;
		b[i - 1] += d;
		b[i - 2] += 2 * d;
	}
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	int l = 0, r = 1012345678;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) 
			l = mid;
		else
			r = mid;
	}
	cout << l << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}