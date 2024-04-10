/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];
pair <int, int> b[N];
bool f[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
		f[i] = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i].F = a[i] + i;
		b[i].S = i;
	}
	sort(b, b + n);
	for (int i = n - 1; i >= n - k; i--) {
		f[b[i].S] = false;
	}
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (f[i])
			sum += a[i] + cnt;
		else
			cnt++;
	}
	cout << sum << '\n';
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