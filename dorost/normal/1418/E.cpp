/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 998244353, N = 201234;
int a[N], ps[N];

int tav(int x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ps[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		ps[i] = ps[i + 1] + a[i];
	}
	for (int i = 0; i < q; i++) {
		int d, b;
		cin >> d >> b;
		int in = lower_bound(a, a + n, b) - a;
		int cnt = n - in;
		if (d > cnt) {
			cout << 0 << ' ';
		} else {
			int s1 = ps[in], s2 = ps[0] - ps[in];
			s1 %= M;
			s2 %= M;
			int ans = 0;
			int x = (cnt - d) * inv(cnt);
			x %= M;
			x *= (s1);
			x %= M;
			ans += x;
			x = (cnt - d + 1) * inv(cnt + 1);
			x %= M;
			x *= s2;
			x %= M;
			ans += x;
			ans %= M;
			cout << ans << ' ';
		}
	}
}