/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 200001, M = 1000 * 1000 * 1000 + 7, inv2 = 500000004;
int cnt[N];

int tav(int x, int n) {
	if (x == 0)
		return 0;
	if (n == 0)
		return 1;
	int a = tav(x, (n / 2)) % M;
	a = a * a;
	a %= M;
	if (n % 2)
		a *= x;
	return a % M;
}

void solve() {
	int m;
	int n = 1;
	scanf("%lld", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%lld", &x);
		cnt[x]++;
		n *= x;
		n %= M;
	}
	int ans = 1, y = 1;
	bool f = true, h = true;
	for (int i = 1; i < N; i++) {
		if (cnt[i] == 0)
			continue;
		int x = 1;
		if (h && (cnt[i] + 1) % 2 == 0) {
			f = false;
			x *= ((cnt[i] + 1) / 2);
			h = false;
		}else {
			x *= (cnt[i] + 1);
			if (cnt[i] % 2)
				f = false;
		}
		y *= x;
		y %= (M - 1);
	}
	if (f) {
		h = true;
		y /= 2;
		for (int i = 1; i < N; i++) {
			ans *= tav(i, (cnt[i] / 2));
			ans %= M;
		}
	}
	ans *= tav(n, y);
	ans %= M;
	printf("%lld", ans);
}

int32_t main() {
	solve();
}