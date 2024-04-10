/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, M = 998244353;
pair <int, int> a[N];
int b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> a[i].F;
		a[i].F *= (i + 1) * (n - i);
		a[i].S = i;
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b + n);
	reverse(b, b + n);
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a[i].F %= M;
		b[i] %= M;
		ans += a[i].F * b[i];
		ans %= M;
	}
	cout << ans;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}