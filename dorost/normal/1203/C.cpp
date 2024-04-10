/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 401234;
int a[N];

void solve() {
	int n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i);
	int gcd = a[0];
	for (int i = 0; i < n; i++)
		gcd = __gcd(gcd, a[i]);
	int ans = 0;
	for (int i = 1; i * i <= gcd; i++) {
		if (gcd % i)
			continue;
		ans += 2 - (i == gcd / i);
	}
	printf("%lld", ans);
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}