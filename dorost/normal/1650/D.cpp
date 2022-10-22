/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N], b[N], ans[N];

void cyclic(int k, int x) {
	x %= (k + 1);
	for (int i = 0; i <= k; i++) {
		b[(i + x) % (k + 1)] = a[i];
	}
	for (int i = 0; i <= k; i++) 
		a[i] = b[i];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	for (int i = n - 1; i >= 0; i--) {
//		for (int j = 0; j < n; j++)
//			cout << a[j] + 1 << ' ';
//		cout << '\n';
		int in = 0;
		for (int j = 0; j <= i; j++) {
			if (a[j] == i)
				in = i - j;
		}
		if (in == 0) {
			ans[i] = 0;
			continue;
		}
		ans[i] = (i + 1) - in;
		cyclic(i, in);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
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