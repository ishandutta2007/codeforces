/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n, k, used = 0;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++)
		a[i] = 0;
	for (int i = 0; i < n - 1; i++) {
		if (used == k)
			break;
		if (s[i] == '0') {
			a[i] = (1 - k % 2);
		} else {
			a[i] = k % 2;
		}
		used += a[i];
	}
	a[n - 1] = k - used;
	for (int i = 0; i < n; i++) {
		if ((k - a[i]) & 1) {
			s[i] = (s[i] == '0' ? '1' : '0');
		}
	}
	cout << s << '\n';
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
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