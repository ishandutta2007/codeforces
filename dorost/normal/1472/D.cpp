/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	int ansa = 0, ansb = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	bool x = true;
	for (int i = n - 1; i >= 0; i--) {
		if (x) {
			if (a[i] % 2 == 0)
				ansa += a[i];
		} else {
			if (a[i] % 2)
				ansb += a[i];
		}
		x = !x;
	}
	if (ansa == ansb) {
		cout << "Tie\n";
	} else {
		cout << (ansa > ansb ? "Alice" : "Bob") << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}