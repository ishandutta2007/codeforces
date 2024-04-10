#include <bits/stdc++.h>
using namespace std;

using db = long double;
const db eps = 1e-12;
inline db sqr(db x) { return x * x; }

struct pt{
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
};

struct line{
	db a, b, c;
	line (db a = 0, db b = 0, db c = 0) : a(a), b(b), c(c) {}
	line (pt p1, pt p2) {
		a = p2.y - p1.y, b = p1.x - p2.x;
		c = a * p1.x + b * p1.y;
		db x = sqrt(sqr(a) + sqr(b));
		assert(x > eps);
		a /= x, b /= x, c /= x;
		if (a < -eps) a *= -1, b *= -1, c *= -1;
		if (fabs(a) < eps && b < -eps) b *= -1, c *= -1;
		if (fabs(a) < eps && fabs(b) < eps && c < -eps) c *= -1;
	}
	bool operator < (const line &l) const {
		if (fabs(a - l.a) > eps) return a < l.a;
		if (fabs(b - l.b) > eps) return b < l.b;
		return c < l.c - eps;
	}
};

map<line, int> M;

const int N = 2200;
bool ban[N];
pt p[N];

int main() {
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		db a, b, c; cin >> a >> b >> c;
		p[i] = pt(a * c / (a * a + b * b), b * c / (a * a + b * b));
		if (fabs(c) < eps) {
			ban[i] = 1;
			cnt++;
		}
	}
	assert(cnt < 3);
	long long ans = 0;
	if (cnt == 2) ans = n-2;
	for (int i = 0; i < n; i++) {
		if (ban[i]) continue;
		for (int j = 0; j < i; j++) {
			if (ban[j]) continue;
			M[line(p[i], p[j])]++;
		}
	}
	for (auto t : M) {
		int cnt = t.second;
		int k = ((int)round(sqrt(cnt * 8 + 1)) + 1) / 2;
		assert(cnt == k * (k - 1) / 2);
		ans += 1ll * k * (k - 1) * (k - 2) / 6;
	}
	cout << ans << endl;
}