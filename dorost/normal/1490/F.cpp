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
int a[N], pre[N], suf[N], suf2[N];
pair <int, int> b[N];

void solve() {
	int n;
	cin >> n;
	map <int, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a + n);
	int cn = 0;
	for (auto [x, y] : cnt) {
		b[cn] = {y, x};
		cn++;
	}
	sort(b, b + cn);
	for (int i = 0; i < cn; i++) {
		if (i == 0)
			pre[i] = b[i].F;
		else
			pre[i] = pre[i - 1] + b[i].F;
	}
	for (int i = cn - 1; i >= 0; i--) {
		if (i == cn - 1)
			suf[i] = b[i].F;
		else
			suf[i] = suf[i + 1] + b[i].F;
	}
	int mn = LLONG_MAX;
	for (int i = 0; i < cn; i++) {
		int x = 0;
		int num = b[i].F;
		if (i != cn - 1) {
			x += suf[i + 1] - num * (cn - i - 1);
		}
		if (i != 0) {
			x += pre[i - 1];
		}
		mn = min(mn, x);
	}
	cout << mn << ' ';
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