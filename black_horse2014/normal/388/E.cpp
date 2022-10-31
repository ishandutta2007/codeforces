#include <bits/stdc++.h>
using namespace std;
typedef long double DB;
const DB EPS = 1e-12;
const DB PI = acos(-1);

DB sqr(DB x) {
	return x * x;
}

struct PT{
	DB x, y;
	PT (DB x = 0, DB y = 0) : x(x), y(y) {}
	void in() { 
		double xx, yy;
		scanf("%lf%lf", &xx, &yy);
		x = xx, y = yy;
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

struct db1{
	DB x;
	db1(DB x = 0) : x(x) {}
	bool operator <(const db1 &d) const {
		return x + 1e-12 < d.x;
	}
	bool operator ==(const db1 &d) const {
		return fabs(x - d.x) < 1e-12;
	}
};

struct db2{
	DB x;
	db2(DB x = 0) : x(x) {}
	bool operator <(const db2 &d) const {
		return x + 1e-8 < d.x;
	}
	bool operator ==(const db2 &d) const {
		return fabs(x - d.x) < 1e-8;
	}
};

const int N = 1100;
DB from[N], to[N];
PT F[N], T[N], V[N], S[N];

map<db2, int> M;
map<db1, set<PT>> H;

int main() {
//	freopen("in.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double f, t;
		scanf("%lf", &f); from[i] = f;
		F[i].in();
		scanf("%lf", &t); to[i] = t;
		T[i].in();
		V[i] = (T[i] - F[i]) / (to[i] - from[i]);
		S[i] = F[i] - V[i] * from[i];
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		M.clear();
		H.clear();
		for (int j = 0; j < n; j++) {
			if (dis(V[i] - V[j]) < 1e-7) continue;
			PT d = S[j] - S[i], e = V[j] - V[i];
			DB ang1 = atan2(d.y, d.x), ang2 = atan2(e.y, e.x);
			if (ang1 < 0) ang1 += PI;
			if (fabs(ang1 - PI) < EPS) ang1 = 0;
			if (ang2 < 0) ang2 += PI;
			if (fabs(ang2 - PI) < EPS) ang2 = 0;
			if (fabs(dis(d)) < 1e-7 || fabs(ang1 - ang2) < EPS) {
				DB ang = atan2(e.y, e.x);
				if (ang < 0) ang += PI;
				if (fabs(ang - PI) < EPS) ang = 0;
				int sig = 1;
				if (e.x * d.x < -EPS || e.y * d.y < -EPS) sig = -1;
				H[ang].insert(e);
				M[dis(d) / dis(e) * sig]++;
			}
		}
		for (auto &t : M) ans = max(ans, t.second + 1);
		for (auto &t : H) ans = max(ans, (int)t.second.size() + 1);
	}
	cout << ans << endl;
	return 0;
}