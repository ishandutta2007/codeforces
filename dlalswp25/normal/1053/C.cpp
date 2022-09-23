#include <stdio.h>
#define MOD 1000000007

typedef long long ll;

struct node {
	ll w, wx, wn;
};
node tree[200005 * 4];

ll X[200005];
ll W[200005];

void update(int idx, int s, int e, int p, ll x) {
	if(e < s || p < s || e < p) return;
	if(s == e) {
		tree[idx].w = x;
		tree[idx].wx = X[p] * x % MOD;
		tree[idx].wn = x * p % MOD;
		return;
	}
	int m = (s + e) >> 1;
	update(idx * 2, s, m, p, x);
	update(idx * 2 + 1, m + 1, e, p, x);
	tree[idx].w = (tree[idx * 2].w + tree[idx * 2 + 1].w);
	tree[idx].wx = (tree[idx * 2].wx + tree[idx * 2 + 1].wx) % MOD;
	tree[idx].wn = (tree[idx * 2].wn + tree[idx * 2 + 1].wn) % MOD;
}

ll getw(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return tree[idx].w;
	int m = (s + e) >> 1;
	return (getw(idx * 2, s, m, p, q) + getw(idx * 2 + 1, m + 1, e, p, q));
}
ll getwx(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return tree[idx].wx;
	int m = (s + e) >> 1;
	return (getwx(idx * 2, s, m, p, q) + getwx(idx * 2 + 1, m + 1, e, p, q)) % MOD;
}
ll getwn(int idx, int s, int e, int p, int q) {
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return tree[idx].wn;
	int m = (s + e) >> 1;
	return (getwn(idx * 2, s, m, p, q) + getwn(idx * 2 + 1, m + 1, e, p, q)) % MOD;
}

int main() {
	int N, Q; scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%lld", &X[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &W[i]);
	for(int i = 1; i <= N; i++) update(1, 1, N, i, W[i]);

	ll ansx;
	
	while(Q--) {
		ll x, y; scanf("%lld%lld", &x, &y);
		if(x < 0) {
			x *= -1;
			update(1, 1, N, x, y);
		}
		else {
			// median
			ll S = getw(1, 1, N, x, y); S = (S + 1) / 2;
			//printf("%lld\n", S);
			int l = x, r = y;
			while(l <= r) {
				int m = (l + r) >> 1;
				if(getw(1, 1, N, x, m) < S) l = m + 1;
				else r = m - 1;
			}
			ansx = X[l] - (l - x);
			//printf("%lld\n", ansx);

			l = x, r = y;
			while(l <= r) {
				int m = (l + r) >> 1;
				if(X[m] - (m - x) < ansx) l = m + 1;
				else r = m - 1;
			}
			// ~r : neg

			ll ans = 0;

			int s = x, e = r;
			if(s <= e) {
				ans = (ans + getw(1, 1, N, s, e) % MOD * ansx) % MOD;
				ans = (ans + MOD - getwx(1, 1, N, s, e)) % MOD;
				//ll wne = getwn(1, 1, N, 1, e);
				//ll wns = getwn(1, 1, N, 1, s - 1);
				//ans = (ans + wne - wns) % MOD;
				ans = (ans + getwn(1, 1, N, s, e)) % MOD;
				ll t = x * (getw(1, 1, N, s, e) % MOD) % MOD;
				ans = (ans + MOD - t) % MOD;
			}
			//printf("%lld\n", ans);

			ll ans2 = 0;
			s = l, e = y;

			if(s <= e) {
				ans2 = (ans2 + getw(1, 1, N, s, e) % MOD * ansx) % MOD;
				ans2 = (ans2 + MOD - getwx(1, 1, N, s, e)) % MOD;
				//ll wne = getwn(1, 1, N, 1, e);
				//ll wns = getwn(1, 1, N, 1, s - 1);
				//ans2 = (ans2 + wne - wns) % MOD;
				ans2 = (ans2 + getwn(1, 1, N, s, e)) % MOD;
				ll t = x * (getw(1, 1, N, s, e) % MOD) % MOD;
				ans2 = (ans2 + MOD - t) % MOD;
			}
			//printf("%lld\n", MOD - ans2);

			printf("%lld\n", (ans + MOD - ans2) % MOD);
		}
	}
	return 0;
}