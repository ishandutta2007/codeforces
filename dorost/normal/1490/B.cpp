/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 30123;
int a[N];

void solve() {
	int n, c[3] = {}, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], c[a[i] % 3]++;
	while (c[0] > n / 3) {
		c[0]--;
		c[1]++;
		ans++;
	}
	while (c[1] > n / 3) {
		c[1]--;
		c[2]++;
		ans++;
	}
	while (c[2] > n / 3) {
		c[2]--;
		c[0]++;
		ans++;
	}
	while (c[0] > n / 3) {
		c[0]--;
		c[1]++;
		ans++;
	}
	while (c[1] > n / 3) {
		c[1]--;
		c[2]++;
		ans++;
	}
	while (c[2] > n / 3) {
		c[2]--;
		c[0]++;
		ans++;
	}
	while (c[0] > n / 3) {
		c[0]--;
		c[1]++;
		ans++;
	}
	while (c[1] > n / 3) {
		c[1]--;
		c[2]++;
		ans++;
	}
	while (c[2] > n / 3) {
		c[2]--;
		c[0]++;
		ans++;
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