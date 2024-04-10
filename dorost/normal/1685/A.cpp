/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n % 2) {
		cout << "NO\n";
		return;
	}
	sort(a, a + n);
	vector <int> v, w;
	for (int i = 0; i < n / 2; i++) {
		v.push_back(a[i]);
	}
	for (int i = n / 2; i < n; i++)
		w.push_back(a[i]);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a[i] = v[i / 2];
		} else {
			a[i] = w[i / 2];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == (a[(i + 1) % n])) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YEs\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
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