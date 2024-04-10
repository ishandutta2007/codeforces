/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = INT_MAX;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	b[m] = INT_MAX;
	ll suma = 0, sumb = 0;
	int ina = 0, inb = 0, ans = 0;
	for (int i = 0; i < n + m; i++) {
		if (suma < sumb && a[ina] != INT_MAX) {
			suma += a[ina];
			ina++;
		} else {
			sumb += b[inb];
			inb++;
		}
		if (suma == sumb) {
			ans++;
		}
	}
	if (suma != sumb) {
		cout << -1;
		return 0;
	}
	cout << ans;
}