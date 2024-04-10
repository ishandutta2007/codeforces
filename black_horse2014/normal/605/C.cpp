#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;

inline db sqr(db x) { return x * x; }

const int N = 110000;
const db eps = 1e-8;

struct pt{
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
	bool operator < (const pt &p) const {
		if (fabs(p.x - x) > eps) return x < p.x;
		return y < p.y - eps;
	}
} p[N], q[N];

pt operator - (const pt &p1, const pt &p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

pt operator + (const pt &p1, const pt &p2) {
	return pt(p1.x + p2.x, p1.y + p2.y);
}

pt operator * (const pt &p1, const db &d) {
	return pt(p1.x * d, p1.y * d);
}

db dis(pt p) {
	return sqrt(sqr(p.x) + sqr(p.y));
}

db vect(pt p, pt p1, pt p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

db scal(pt p, pt p1, pt p2) {
	return (p1.x - p.x) * (p2.x - p.x) + (p1.y - p.y) * (p2.y - p.y);
}

bool onSeg(pt p, pt p1, pt p2) {
	return scal(p, p1, p2) < -eps;
}

int posLineLine(pt p1, pt p2, pt p3, pt p4, pt &res) {
	db s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (fabs(s1 - s2) < eps) {
		if (fabs(s1) < eps) return 2;
		return 0;
	}
	res = p3 + (p4 - p3) * (s1 / (s1 - s2));
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout<<setprecision(10);
	int n, _x, _y; cin >> n >> _x >> _y;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + n);
	int k = 0;
	for (int i = 0; i < n; q[k++] = p[i++])
		while (k >= 2 && vect(q[k-2], q[k-1], p[i]) >= 0) --k;
	double ans = 1e100;
	for (int i = 0; i < k; i++) {
		double d = max(1. * _y / q[i].y, 1. * _x / q[i].x);
		ans = min(ans, d);
		if (i == k-1) continue;
		pt tmp;
		int ret = posLineLine(q[i], q[i+1], pt(0, 0), pt(_x, _y), tmp);
		if (ret == 1 && onSeg(tmp, q[i], q[i+1])) {
			ans = min(ans, dis(pt(_x, _y)) / dis(tmp));
		}
	}
	cout << ans << endl;
}