/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], ps[N], cnt[N * 21];

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n * 21; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) 
		a[i] = (s[i] - '0');
	ps[0] = 0;
	for (int i = 1; i <= n; i++)
		ps[i] = ps[i - 1] + a[i - 1];
	for (int i = 0; i <= n; i++) {
		ps[i] -= i;
		ps[i] += 10 * n;
		cnt[ps[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n * 21; i++) {
		ans += (cnt[i] * (cnt[i] - 1)) / 2;
	}
	cout << ans << '\n';
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