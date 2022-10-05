#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool flagx, flagy, flag3;
LL n, m, x, y, vx, vy;

void p(LL x, LL y = 0) {
	if (x == -1) puts("-1");
	else {
		if (flagx) x = n - x;
		if (flagy) y = m - y;
//		if (flag3) swap(x, y);
		printf("%I64d %I64d\n", x, y);
	}
	exit(0);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1; y = 0; return a; }
	LL gcd = exgcd(b, a%b, y, x); y -= a / b * x;
	return gcd;
}

void solve() {
//	if (x < y) swap(x, y), swap(n, m), flag3 = 1;
	LL x0, y0, d, g, del;
	d = x - y; g = exgcd(n, m, x0, y0);
	if (d % g) p(-1); del = m / g;
	x0 *= d / g; y0 *= d / g;
	while (x0 <= 0) x0 += del;
	while (x0 - del >= 1) x0 -= del;
	y0 = (x0 * n + y - x) / m;
	p(x0 & 1 ? n : 0, y0 & 1 ? m : 0);
}

int main() {
	cin >> n >> m >> x >> y >> vx >> vy;
	if (vx * vy == 0) {
		if ((x == 0 || x == n) && vy == -1) p(x, 0);
		if ((x == 0 || x == n) && vy == 1) p(x, m);
		if ((y == 0 || y == m) && vx == -1) p(0, y);
		if ((y == 0 || y == m) && vx == 1) p(n, y);
		p(-1);
		return 0;
	}
	if (vx == -1) flagx = 1, x = n - x;
	if (vy == -1) flagy = 1, y = m - y;
	solve();
	return 0;
}