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
int suf[N];
pair <int, int> a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].F;
	for (int i = 0; i < n; i++)
		cin >> a[i].S;
	sort(a, a + n);
	suf[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + a[i].S;
	}
	int mn = suf[0];
	for (int i = 0; i < n; i++) {
		mn = min(mn, max(a[i].F, suf[i + 1]));
	}
	cout << mn << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}