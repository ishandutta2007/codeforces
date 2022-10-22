#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

LL n, l, r, k, e, f;
LL best = -1;

bool check(LL a, LL b) {
	if (b % a != 0) return false;
	if (b < 0) return false;
	return true;
}

void solve1() {
	rep(i, 0, e)
		rep(j, 0, f) {
			bool ok = 0;
			ok |= check(n + i + j, k - e - i);
			if (i > 0)
			ok |= check(n + i + j, k - e - i + 1);
			if (ok) best = max(best, (LL) i + j);
		}
}

pair <LL, LL> euklid(LL a, LL b) {
	LL ax = 1;
	LL ay = 0;
	LL bx = 0;
	LL by = 1;
	while (b != 0) {
		LL r = a / b;
		ax -= r * bx;
		ay -= r * by;
		a -= r * b;
		swap(a, b);
		swap(ax, bx);
		swap(ay, by);
	}
	return {ax, ay};
}

LL dol(LL l, LL r) {
	if ((l + r) / 2 >= 0) return (l + r) / 2;
	return (l + r - 1) / 2;
}

LL gora(LL l, LL r) {
	return (l + r + 1) / 2;
}
	

LL sol(LL a, LL b, LL c, bool special) {
	if (c < 0) return -1;
	pair<LL, LL> p = euklid(a, b);
	LL nwd = p.fi * a + p.se * b;
	assert(nwd == 1);
	LL x1 = p.fi * c / nwd;
	LL y1 = p.se * c / nwd;
	
	LL l1 = -1e12;
	LL r1 = 1e12;
	bool good = 0;
	
	while (l1 < r1) {
		LL m = dol(l1, r1);
		
		LL nx = x1 + b * m;
		LL ny = y1 - a * m;
		
		if (nx < 0 || ny > f || (nx == 0 && special)) {
			l1 = m + 1;
			continue;
		}
		if (nx > e || ny < 0) {
			r1 = m - 1;
			continue;
		}
		good = 1;
		r1 = m;
	}
	
	if (!good) return -1LL;
	
	LL l2 = -1e12;
	LL r2 = 1e12;
	
	while (l2 < r2) {
		LL m = gora(l2, r2);
		
		LL nx = x1 + b * m;
		LL ny = y1 - a * m;
		
		if (nx < 0 || ny > f || (nx == 0 && special)) {
			l2 = m + 1;
			continue;
		}
		if (nx > e || ny < 0) {
			r2 = m - 1;
			continue;
		}
		l2 = m;
	}
	
	LL p1 = x1 + b * l1;
	LL k1 = y1 - a * l1;
	
	LL p2 = x1 + b * l2;
	LL k2 = y1 - a * l2;
	
	LL o1 = p1 + k1;
	LL o2 = p2 + k2;
	
	return max(o1, o2);
}
	
	

void solve2() {
	rep(c, 0, k / n) {
		best = max(best, sol(c + 1, c, k - c * n - e, 0));
		best = max(best, sol(c + 1, c, k - c * n + 1 - e, 1));
	}
}

int main() {	
	scanf ("%lld %lld %lld %lld", &n, &l, &r, &k);
	e = (l <= r ? r - l + 1 : n - (l - r - 1));
	f = n - e;
	if (n <= 20000) solve1();
	else solve2();
	printf ("%lld", best);
	
	return 0;
}