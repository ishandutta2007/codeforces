/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201;
int w[N], a[N];

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

void solve() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (is_prime(sum)) {
		cout << n - 1 << '\n';
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				cout << i + 1 << ' ';
			} else {
				if (f) {
					f = false;
				} else {
					cout << i + 1 << ' ';
				}
			}
		}
		cout << '\n';
	} else {
		cout << n << '\n';
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}
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