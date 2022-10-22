/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];
vector <int> p;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

void solve() {
	int n;
	cin >> n;
	bool f = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int mn = INT_MAX;
		for (int x = 1; x <= 60; x++) {
			if (a[i] % x)
				mn = min(mn, x);
		}
		if (mn > i + 2) {
			f = false;
		}
	}
	cout << (f ? "YES" : "NO") << '\n';
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