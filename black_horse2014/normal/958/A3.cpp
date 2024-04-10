#include<bits/stdc++.h>
using namespace std;

typedef double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e10;
const DB EPS = 1e-8;

inline DB sqr(DB x) {
	return x * x;
}

struct PT {
	DB x, y;

	PT() {}
	PT(DB x, DB y) : x(x), y(y) {}
	void in() {
		scanf("%lf%lf", &x, &y);
	}
};

bool operator<(const PT& p1, const PT& p2) {
	if (fabs(p1.x - p2.x) > EPS) return p1.x < p2.x;
	return p1.y + EPS < p2.y;
}

bool operator==(const PT& p1, const PT& p2) {
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

PT operator+(PT p1, PT p2) {
	return PT(p1.x + p2.x, p1.y + p2.y);
}

PT operator-(PT p1, PT p2) {
	return PT(p1.x - p2.x, p1.y - p2.y);
}

PT operator*(PT p, DB c) {
	return PT(p.x * c, p.y * c);
}

PT operator/(PT p, DB c) {
	return PT(p.x / c, p.y / c);
}

DB dis(PT p) {
	return sqrt(sqr(p.x) + sqr(p.y));
}

DB dis2(PT p) {
	return sqr(p.x) + sqr(p.y);
}

DB dis2(PT p1, PT p2) {
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

DB dis(PT p1, PT p2) {
	return sqrt(dis2(p1, p2));
}

DB vect(PT p1, PT p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

DB scal(PT p1, PT p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

DB getAngle(PT p) {
	return atan2(p.y, p.x);
}

DB vect(PT p, PT p1, PT p2) {
	return vect(p1 - p, p2 - p);
}

DB scal(PT p, PT p1, PT p2) {
	return scal(p1 - p, p2 - p);
}

DB getAngle(PT p, PT p1, PT p2) {
	return getAngle(p2 - p) - getAngle(p1 - p);
}

DB getAngle180(PT p, PT p1, PT p2) {
	return acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2));
}

DB disToLine(PT p, PT p1, PT p2) {
	return fabs(vect(p, p1, p2)) / dis(p1, p2);
}

DB disToSeg(PT p, PT p1, PT p2) {
	if (scal(p1, p, p2) < 0) return dis(p, p1);
	if (scal(p2, p, p1) < 0) return dis(p, p2);
	return disToLine(p, p1, p2);
}

bool onLine(PT p, PT p1, PT p2) {
	return fabs(vect(p1 - p, p2 - p)) < EPS;
}

bool onSeg(PT p, PT p1, PT p2) {
	if (!onLine(p, p1, p2)) return 0;
	return (p1.x - p.x) * (p2.x - p.x) < EPS && (p1.y - p.y) * (p2.y - p.y) < EPS;
}

PT projection(PT a, PT b, PT p) {
	return a + (a - b) * scal(p - a, a - b) / dis2(a - b);
}

int posLineLine(PT p1, PT p2, PT p3, PT p4, PT& p) {
	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (fabs(s1 - s2) < EPS) {
		if (fabs(s1) < EPS) return 2;
		return 0;
	}
	p = p3 + (p4 - p3) * s1 / (s1 - s2);
	return 1;
}

int posCirLine(PT p, DB r, PT p1, PT p2, PT *q) {
	DB a, b, c, d2, d;
	a = dis2(p1, p2);
	b = scal(p1, p, p2);
	c = dis2(p, p1) - sqr(r);
	d2 = sqr(b) - a * c;
	if (d2 < -EPS) return 0;
	d = sqrt(fabs(d2));
	q[0] = p1 + (p2 - p1) * (b + d) / a;
	if (d2 < EPS) return 1;
	q[1] = p1 + (p2 - p1) * (b - d) / a;
	return 2;
}

int posCirCir(PT p1, DB r1, PT p2, DB r2, PT *q) {
	DB dx, dy, d, e, f2, f;
	dx = p2.x - p1.x, dy = p2.y - p1.y;
	d = dis(p1, p2);
	e = (sqr(r1) - sqr(r2) + sqr(d)) / 2 / d;
	f2 = sqr(r1) - sqr(e);
	if (f2 < -EPS) return 0;
	f = sqrt(fabs(f2));
	q[0] = PT(p1.x + (e * dx - f * dy) / d, p1.y + (e * dy + f * dx) / d);
	if (f2 < EPS) return 1;
	q[1] = PT(p1.x + (e * dx + f * dy) / d, p1.y + (e * dy - f * dx) / d);
	return 2;
}

DB calcArea(PT *p, int n) {
	DB rlt = 0;
	for (int i = 0; i < n; i++) rlt += vect(p[i], p[(i + 1) % n]);
	return rlt / 2;
}

PT rot(PT p, DB t) {
	return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}

int inPolygon(PT p, PT *q, int m) {
	PT p1, p2;
	int k = 0;
	for (int i = 0; i < m; i++) {
		p1 = q[i], p2 = q[(i + 1) % m];
		if (onSeg(p, p1, p2)) return 2;
		if (p1.y > p2.y) swap(p1, p2);
		if (p1.y < p.y + EPS && p.y + EPS < p2.y && vect(p, p1, p2) > 0) k++;
	}
	return k % 2;
}

const int N = 110000;
PT p[N];

int convex_hull(PT *_p, int n, PT *q) {
	for (int i = 0; i < n; i++) p[i] = _p[i];
	sort(p, p + n);
	n = unique(p, p + n) - p;
	if (n == 1) {
		q[0] = p[0];
		return 1;
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && vect(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && vect(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	return --m;
}

typedef pair<int, int> PII;


map<PII, int> MA;
int to[N];
PT P[N], Q[N], R[N];
PT PC[N], QC[N], RC[N];
vector<int> vec;

int main() {
	int n; scanf("%d", &n);
	int n1; scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		P[i].in();
		P[i] = P[i] * 100;
	}
	int n2; scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		Q[i].in();
		Q[i] = Q[i] * 100;
		int x = round(Q[i].x);
		int y = round(Q[i].y);
		MA[PII(x, y)] = i + 1;
	}
	int m1 = convex_hull(P, n1, PC);
	int m2 = convex_hull(Q, n2, QC);
	for (int i = 0; i < m1; i++) {
		PT X = PC[i];
		for (int j = 0; j < m1; j++) {
			if (i == j) continue;
			PT Y = PC[j];
			for (int k = 0; k < m2; k++) {
				PT X1 = QC[k];
				for (int l = 0; l < m2; l++) {
					if (k == l) continue;
					PT Y1 = QC[l];
					if (fabs(dis(X, Y) - dis(X1, Y1)) > 1) continue;
					for (int _ = 0; _ < n1; _++) R[_] = P[_] + (X1 - X);
					double ang = getAngle(X1, Y - X + X1, Y1);
					for (int _ = 0; _ < n1; _++) R[_] = X1 + rot(R[_] - X1, ang);
					int cnt = 0;
					vec.clear();
					for (int _ = 0; _ < n1; _++) {
						int x = round(R[_].x), y = round(R[_].y);
						int ret = 0;
						for (int _x = x - 1; !ret && _x <= x + 1; _x++) {
							for (int _y = y - 1; !ret && _y <= y + 1; _y++) {
								if (!MA.count(make_pair(_x, _y))) continue;
								ret = MA[make_pair(_x, _y)];
							}
						}
						if (ret) {
							cnt++;
							vec.push_back(_ + 1);
							to[_ + 1] = ret;
							if (cnt > n) break;
						}
					}
					if (cnt > 0.91 * n) {
						vec.resize(n);
						for (int _ = 0; _ < vec.size(); _++) if (!vec[_]) vec[_] = 1;
						for (int _ : vec) printf("%d %d\n", _, to[_]);
						return 0;
					}
				}
			}
		}
	}
}