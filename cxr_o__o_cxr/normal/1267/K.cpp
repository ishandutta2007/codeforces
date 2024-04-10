#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

int T;
ll n;
int c[40];
ll C[40][40];

void init(int n) {
	C[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
}

ll calc(int cnt) {
	ll f = 1;
	int space = 1;
	for (int i = cnt; ~i; i--) {
		if (space < 0) {
			if (c[i])
				return 0;
		} else {
//			cerr << space << ' ';
			f *= C[space][c[i]];
			space -= c[i];
		}
		space += (i != 1);
	}
//	cerr << '\n';
	return f;
}

int main() {
	init(35);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		memset(c, 0, sizeof(c));
		int cnt;
		for (cnt = 1; n; cnt++) {
			c[n % (cnt + 1)]++;
			n /= (cnt + 1);
		}
		--cnt;
		ll ans = calc(cnt);
		if (c[0] && !c[cnt]) {
			c[0]--;
			ans -= calc(cnt - 1);
		}
		--ans;
		printf("%lld\n", ans);
	}
	return 0;
}