/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 202345, M = 1000 * 1000 * 1000 + 7;
int a[N];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	ll ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = tav(2, n) - 1;
	ans += M;
	ans %= M;
	for (int i = 1; i <= 30; i++) {
		int x = 1 << i;
		v.clear();
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] % x == 0) {
				v.push_back(a[j] / x);
				if (v.back() % 2)
					cnt++;
			}
		}
		if (cnt == 0) 
			continue;
		if (v.size() == 0)
			break;
		ans -= tav(2, ((int)v.size()) - 1);
		ans += M;
		ans %= M;
	}
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	solve();
}