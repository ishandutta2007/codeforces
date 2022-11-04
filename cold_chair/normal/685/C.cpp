#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int T, n;
ll x, y, z;
ll b[N][4], a[N][3];

ll l[4], r[4], u[4], v[4];

const ll inf = 9e18;

int jo(int x) {
	return x < 0 ? -x % 2 : x % 2;
}

int work(int c) {
	ll su = 0, sv = 0;
	fo(j, 0, 3) {
		u[j] = l[j], v[j] = r[j];
		if(jo(u[j]) == c) u[j] ++;
		if(jo(v[j]) == c) v[j] --;
		if(u[j] > v[j]) return 0;
		if(j < 3) su += u[j], sv += v[j];
	}
	if(max(su, l[3]) <= min(sv, r[3])) {
		ll g = max(su, l[3]);
		fd(j, 2, 0) {
			su -= u[j], sv -= v[j];
			ll p = g - sv, q = g - su;
			p = max(p, u[j]), q = min(q, v[j]);
			if(jo(p) == c) p ++;
			if(p > q) return 0;
			g -= p;
			if(j == 2) z = p;
			if(j == 1) y = p;
			if(j == 0) x = p;
		}
		ll x1 = x, y1 = y, z1 = z;
		x = (x1 + y1) / 2;
		y = (x1 + z1) / 2;
		z = -(y1 + z1) / 2;
		return 1;
	}
	return 0;
}

int pd(ll m) {
	fo(j, 0, 3) l[j] = -inf, r[j] = inf;
	fo(i, 1, n) fo(j, 0, 3)
		l[j] = max(l[j], b[i][j] - m), r[j] = min(r[j], b[i][j] + m);
	fo(j, 0, 3) if(l[j] > r[j]) return 0;
	if(work(0)) return 1;
	if(work(1)) return 1;
	return 0;
}

#define abs(X) ((X) < 0 ? -(X) : (X))
ll solve(ll x, ll y, ll z) {
	ll ans = 0;
	fo(i, 1, n) ans = max(ans, abs(x - a[i][0]) + abs(y - a[i][1]) + abs(z - a[i][2]));
	return ans;
}

int main() {
	//freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) {
			scanf("%lld %lld %lld", &x, &y, &z);
			a[i][0] = x;
			a[i][1] = y;
			a[i][2] = z;
			b[i][0] = x + y + z;
			b[i][1] = x - y - z;
			b[i][2] = -x + y - z;
			b[i][3] = x + y - z;
		}
		ll as;
		for(ll l = 0, r = 3e18; l <= r; ) {
			ll m = l + r >> 1;
			if(pd(m)) as = m, r = m - 1; else l = m + 1;
		}
		pd(as);
		ll u = x, v = y, w = z;
		int c = 2;
		fo(i, -c, c) fo(j, -c, c) fo(k, -c, c) {
			if(solve(u + i, v + j, w + k) < solve(x, y, z))
				x = u + i, y = v + j, z = w + k;
		}
		pp("%lld %lld %lld\n", x, y, z);
	}
}