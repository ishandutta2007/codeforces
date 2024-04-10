#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-8;

struct pt{
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {};
	bool operator < (const pt &p) const {
		if (fabs(x - p.x) > eps) return x < p.x;
		return y < p.y - eps;
	}
	bool operator == (const pt &p) const {
		return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
	}
};

inline db sqr(db x) {
	return x * x;
}

db dis(pt p1, pt p2) {
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

int posCirCir(pt p1, db r1, pt p2, db r2, pt *q) {
	if (p1 == p2) return 0;
	db dx = p2.x - p1.x, dy = p2.y - p1.y;
	db d = dis(p1, p2);
	db e = (sqr(r1) - sqr(r2) + sqr(d)) / 2 / d;
	db f2 = sqr(r1) - sqr(e);
	if (f2 < -eps) return 0;
	db f = sqrt(fabs(f2));
	q[0] = pt(p1.x + (e * dx - f * dy) / d, p1.y + (e * dy + f * dx) / d);
	q[1] = pt(p1.x + (e * dx + f * dy) / d, p1.y + (e * dy - f * dx) / d);
	if (f2 < eps) return 1;
	return 2;
}

pt p[3];
db r[3];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y >> r[i];
	if (n == 1) return cout << 2 << endl, 0;
	if (n == 2) {
		pt tmp[2];
		int ret = posCirCir(p[0], r[0], p[1], r[1], tmp);
		cout << 2 + max(1, ret) << endl; 
		return 0;
	} 
	int a = -1, b = -1, c, sz;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			pt tmp[2];
			int ret = posCirCir(p[i], r[i], p[j], r[j], tmp);
			if (ret) {
				a = i, b = j, sz = ret;
				for (int k = 0; k < 3; k++) {
					if (k != a && k != b) c = k;
				}
				break;
			}
		}
		if (a >= 0) break;
	}
	if (a < 0) return cout << 4 << endl, 0;
	set<pt> S;
	pt tmp[2];
	int ret = posCirCir(p[a], r[a], p[c], r[c], tmp);
	for (int i = 0; i < ret; i++) S.insert(tmp[i]);
	ret = posCirCir(p[b], r[b], p[c], r[c], tmp);
	for (int i = 0; i < ret; i++) S.insert(tmp[i]);
	cout << sz + 2 + max(1, (int)S.size()) << endl;
}