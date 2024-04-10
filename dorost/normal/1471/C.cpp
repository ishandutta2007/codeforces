/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234;
int a[N], b[N], cnt[N];

void solve() {
	int n, m, mx = 0;
	cin >> n >> m;
	for (int i = 0; i < m + 10; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--, cnt[a[i]]++;
	for (int j = 0; j < m; j++)
		cin >> b[j];
	for (int i = m - 2; i >= 0; i--) {
		cnt[i] += cnt[i + 1];
	}
	for (int i = 1; i <= m; i++) {
		if (cnt[i - 1] >= i) {
			mx = max(mx, i);
		}
	}
	int sum = 0;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < mx; i++) {
		sum += b[i];
	}
	for (int i = mx; i < n; i++) {
		sum += b[a[i]];
	}
	cout << sum << ' ';
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