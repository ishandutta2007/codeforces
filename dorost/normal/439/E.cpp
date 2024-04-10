/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 1000 * 1000 * 1000 + 7;
int s[N], fac[N], inv[N];
vector <int> dvs[N];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	int ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}

int invf(int x) {
	return tav(x, M - 2);
}

int C(int k, int n) {
	if (k > n)
		return 0;
	return (fac[n] * (inv[n - k] * inv[k] % M)) % M;
}

void solve() {
	int n, f;
	cin >> n >> f;
	if (f == 1) {
		if (n == 1) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
		return;
	}
	int ans = C(f - 1, n - 1);
	for (auto x : dvs[n]) {
		int a = C(f - 1, n / x - 1);
//		cout << x << ' ' << a << endl;
		if (s[x] == -1)
			continue;
		if (s[x] % 2 != 0) {
			ans -= a;
		} else {
			ans += a;
		}
		ans %= M;
		if (ans < 0) {
			ans += M;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fac[0] = 1;
	inv[0] = invf(1);
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= M;
		inv[i] = invf(fac[i]);
	}
	for (int i = 2; i < N; i++) {
		for (int j = i * 2; j < N; j += i) {
			dvs[j].push_back(i);
		}
	}
	for (int i = 1; i < N; i++) {
		int x = 0, y = i, z = 0;
		for (int j = 2; j * j <= y; j++) {
			if (y % j == 0) {
				x++;
				while (y % j == 0)
					y /= j, z++;
			} 
		}
		if (y != 1)
			x++, z++;
		if (x != z) {
			s[i] = -1;
			continue;
		}
		s[i] = z;
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}