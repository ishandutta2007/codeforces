#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m, x, y, vx, vy;
int fx, fy;

void no() {
	cout << -1 << endl;
	exit(0);
}

void out(int x, int y) {
	if (fx) x = n - x;
	if (fy) y = m - y;
	cout << x << ' ' << y << endl;
	exit(0);
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	ll d = extEuclid(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

int main() {
	cin >> n >> m >> x >> y >> vx >> vy;
	if (vx == 0) {
		if (0 < x && x < n) no();
		if (vy > 0) out(x, m);
		else out(x, 0);
	}
	if (vy == 0) {
		if (0 < y && y < m) no();
		if (vx > 0) out(n, y);
		else out(0, y);
	}
	if (vx < 0) fx = 1, x = n-x;
	if (vy < 0) fy = 1, y = m-y;
	ll d = __gcd(n, m);
	if ((x - y) % d) no();
	ll v = (x - y) / d;
	ll nn = n / d, mm = m / d;
	ll k, l; extEuclid(nn, mm, k, l);
	k *= v, l *= v;
	if (k <= 0) {
		ll ad = (mm - k) / mm;
		k += ad * mm, l -= ad * nn;
	} else {
		ll er = (k - 1) / mm;
		k -= er * mm, l += er * nn;
	}
	l *= -1;
	assert(k > 0 && k <= mm);
	assert(l > 0 && l <= nn);
	assert(k * n - l * m == x - y);
	out((k & 1) ? n : 0, (l & 1) ? m : 0);
}