/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

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
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mn = 123456789, an = -1;
	for (int i = 1; i < N; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			x += (min({abs(a[j] - i), abs(a[j] - (i - 1)), abs(a[j] - (i + 1))}));
		}
		if (mn > x) {
			mn = x;
			an = i;
		}
	}
	cout << an << ' ' << mn;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}