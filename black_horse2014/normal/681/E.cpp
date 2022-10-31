#include <bits/stdc++.h>
using namespace std;

using db = long double;
const db eps = 1e-8;
const db pi = acos(-1);

struct pt{
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {};
};

pt operator - (pt p1, pt p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

inline db sqr(db x) { return x * x; }

db dis(pt p1, pt p2) {
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

int posCirCir(pt p1, db sqr1, pt p2, db sqr2, pt *q) {
	db dx = p2.x - p1.x, dy = p2.y - p1.y;
	db d2 = dx*dx + dy*dy;
	db d = sqrt(d2);
	db dr = sqr1 - sqr2;
	db e = (dr/d + d)/2;
	db ed = dr/d2/2 + .5;
	db f2 = sqr1 - (dr*dr/d2 + d2)/4 - dr*.5;
	if (f2 < -eps) return 0;
	db f = sqrt(max(f2, (db)0));
	q[0] = {p1.x + ed*dx - f*dy/d, p1.y + ed*dy + f*dx/d};
	q[1] = {p1.x + ed*dx + f*dy/d, p1.y + ed*dy - f*dx/d};
	if (f2 < eps) return 1;
	return 2;
}

db getAngle(pt p) {
	return atan2(p.y, p.x);
}

pt O;
db v, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout << setprecision(10);
	cin >> O.x >> O.y >> v >> t;
	int ox = O.x, oy = O.y;
	db l = v * t;
	int n; cin >> n;
	vector<pair<db, db>> vec;
	auto insert = [&] (db f, db t) {
		if (f < t - 1e-10) vec.emplace_back(f, t);
		if (t < f - 1e-10) {
			vec.emplace_back(f, pi);
			vec.emplace_back(-pi, t);
		}
	};
	for (int i = 0; i < n; i++) {
		int x, y, r; cin >> x >> y >> r;
		pt pp = pt(x, y);
		db dd = dis(O, pp);
		if (1ll*(O.x-x)*(O.x-x)+1ll*(O.y-y)*(O.y-y) <= 1ll*r*r) return cout << 1 << endl, 0;
		db ori = getAngle(pp - O);
		db del = asin(1. * r / dd);
		db lk = sqrt(sqr(dd) - sqr(r));
		if (l < dd - r + eps) continue;
		if (l > lk - eps) {
			db f = ori - del, t = ori + del;
			if (t > pi) t -= 2 * pi;
			if (f < -pi) f += 2 * pi;
			if (fabs(fabs(f) - pi) < 1e-10 && fabs(fabs(t) - pi) < 1e-10) continue;
			insert(f, t);
			continue;
		}
		pt tmp[2];
		int ret = posCirCir(O, l*l, pp, 1.*r*r, tmp);
		insert(getAngle(tmp[1] - O), getAngle(tmp[0] - O));
	}
	vector<db> angles;
	angles.push_back(-pi);
	angles.push_back(pi);
	for (auto t : vec) {
		angles.push_back(t.first);
		angles.push_back(t.second);
	}
	sort(angles.begin(), angles.end());
	db sum = 0;
	int cnt[angles.size()+1] = {0};
	for (auto t : vec) {
		int fr = lower_bound(angles.begin(), angles.end(), t.first) - angles.begin();
		int to = lower_bound(angles.begin(), angles.end(), t.second) - angles.begin();
		cnt[fr]++;
		cnt[to]--;
	}
	for (int i = 1; i < angles.size(); i++) {
		cnt[i] += cnt[i-1];
		if (cnt[i-1]) sum += angles[i] - angles[i-1];
	}
	cout << sum / (pi + pi) << endl;
}