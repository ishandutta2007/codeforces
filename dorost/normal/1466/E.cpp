/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 501234, M = 1000 * 1000 * 1000 + 7;
int a[N], cnt[64], an[N], o[N];
bool b[N][64];
int p2[64];

void solve() {
	p2[0] = 1;
	for (int i = 1; i < 64; i++) {
		p2[i] = p2[i - 1] * 2;
		p2[i] %= M;
	}
	int n;
	cin >> n;
	for (int i = 0; i < 64; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 0; j < 64; j++) {
			b[i][j] = x % 2;
			cnt[j] += x % 2;
			x /= 2;
		}
	}
	for (int i = 0; i < n; i++) {
		an[i] = 0;
		for (int j = 0; j < 64; j++) {
			if (b[i][j] == 0) {
				continue;
			}
			an[i] += (cnt[j] * p2[j]) % M;
			an[i] %= M;
		}
	}
	for (int i = 0; i < n; i++) {
		o[i] = 0;
		for (int j = 0; j < 64; j++) {
			if (b[i][j] == 0) {
				o[i] += (cnt[j] * p2[j]) % M;
				o[i] %= M;
				continue;
			}
			o[i] += (n * p2[j]) % M;
			o[i] %= M;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (an[i] * o[i]) % M;
		ans %= M;
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