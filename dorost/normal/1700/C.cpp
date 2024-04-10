/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 69LL, L = -1, R = 3000LL * 1000LL * 1000LL + 69;
int a[N], s[N], p[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n + 5; i++) {
		p[i] = 0;
		s[i] = 0;
	}
	int sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] != a[i + 1]) {
			if (a[i] > a[i + 1]) {
				p[i] += (a[i] - a[i + 1]);
			} else {
				s[i + 1] += (a[i + 1] - a[i]);
			}
		}
		sum += abs(a[i] - a[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
	}
	for (int i = n; i >= 0; i--) {
		p[i] += p[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		a[i] -= (p[i] + s[i]);
	}
	assert(a[1] == a[n]);
	cout << sum + abs(a[1]) << '\n';
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