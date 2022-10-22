/* 	* In the name of GOD 
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
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n + 2);
	for (int i = 0; i < n + 2; i++) {
		int x = sum - a[i];
		int in = n + 1;
		if (i == in)
			in--;
		if (x - a[in] == a[in]) {
			for (int j = 0; j < n + 2; j++) {
				if (j != i && j != in) {
					cout << a[j] << ' ';
				}
			}
			cout << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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