#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

ll query(int l, int r) {
	if(l > r) return 0;
	printf("? %d %d\n", l, r);
	fflush(stdout);
	ll ret; scanf("%lld", &ret);
	if(ret == -1) exit(0);
	return ret;
}

ll f(ll x) {
	ll l = 1, r = N;
	while(l <= r) {
		ll m = l + r >> 1;
		if(m * (m - 1) / 2 < x) l = m + 1;
		else r = m - 1;
	}
	return l;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		ll tot = query(1, N);
		int l = 1, r = N;
		int x;
		while(l <= r) {
			int m = l + r >> 1;
			ll t = query(1, m);
			if(t >= tot) {
				r = m - 1;
				x = r;
			}
			else if(t == 0) {
				l = m + 1;
				x = l;
			}
			else { x = m; break; }
		}
		ll l1 = query(1, x);
		ll r1 = query(x + 1, N);
		ll l2 = query(1, x + 1);
		ll r2 = query(x + 2, N);
		ll t = l2 - l1 + r1 - r2 + 1;
		tot -= t * (t - 1) / 2;
		ll s = f(tot);
		if(l1 - (l2 - l1) * (l2 - l1 - 1) / 2) {
			ll j = x - (l2 - l1) + 1;
			printf("! %lld %lld %lld\n", j - s, j, j + t - 1);
		}
		else {
			ll i = x - (l2 - l1) + 1;
			printf("! %lld %lld %lld\n", i, i + t, i + s + t - 1);
		}
		fflush(stdout);
	}
	return 0;
}