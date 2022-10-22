/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int c[N];
bool a[N];

void solve() {
	int n;
	cin >> n;
	int lst = -1;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n; i++) 
		cin >> c[i];
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (i > lst && c[i] >= i) {
			a[i] = 1;
		}
		c[i] -= a[i] * i;
		for (int j = lst + 1; t < c[i]; j++) {
			a[j] = 1;
			t += 1;
			lst++;
		}
		if (lst + 1 != n)
			a[lst + 1] = 0;
		lst++;
	}
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