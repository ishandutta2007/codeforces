#include <bits/stdc++.h>
using namespace std;
typedef double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e20;
const DB EPS = 1e-8;
inline DB sqr(DB x) { return x * x; }
inline int sgn(DB x) { return (x>EPS)-(x<(-EPS)); }

struct PT {
	DB x, y;
	PT() {}
	PT(DB x, DB y) : x(x), y(y) {}
	void in() {
	    cin >> x >> y;
	}
	bool operator <(const PT &p) const {
		if (fabs(x - p.x) > EPS) return x < p.x;
		return y + EPS < p.y;
	}
	bool operator ==(const PT &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
};

PT operator+(PT p1, PT p2) { return PT(p1.x + p2.x, p1.y + p2.y); }
PT operator-(PT p1, PT p2) { return PT(p1.x - p2.x, p1.y - p2.y); }
PT operator*(PT p, DB c) { return PT(p.x * c, p.y * c); }
PT operator/(PT p, DB c) { return PT(p.x / c, p.y / c); }

DB dis(PT p) { return sqrt(sqr(p.x) + sqr(p.y)); }
DB dis2(PT p) { return sqr(p.x) + sqr(p.y); }

DB vect(PT p1, PT p2) { return p1.x * p2.y - p2.x * p1.y; }
DB vect(PT p, PT p1, PT p2) { return vect(p1 - p, p2 - p); }
DB scal(PT p1, PT p2) { return p1.x * p2.x + p1.y * p2.y; }
DB scal(PT p, PT p1, PT p2) { return scal(p1 - p, p2 - p); }

DB getAngle(PT p) { return atan2(p.y, p.x); }
PT normalize(PT p) { return p / dis(p); }
PT virt(PT p) { return PT(-p.y, p.x); }
PT projection(PT a, PT b, PT p) { return a + (a - b) * (scal(p - a, a - b) / dis2(a - b)); }

bool onLine(PT p, PT p1, PT p2) { return fabs(vect(p1 - p, p2 - p)) < EPS; }
bool onSeg(PT p, PT p1, PT p2) {
	if (!onLine(p, p1, p2)) return 0;
	return (p1.x - p.x) * (p2.x - p.x) < EPS && (p1.y - p.y) * (p2.y - p.y) < EPS;
}

int posLineLine(PT p1, PT p2, PT p3, PT p4, PT& p) {
	DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	if (fabs(s1 - s2) < EPS) {
		if (fabs(s1) < EPS) return 2;
		return 0;
	}
	p = p3 + (p4 - p3) * (s1 / (s1 - s2));
	return 1;
}

//O(n*log(n))
using data = tuple<PT, int, int>;

DB interSimpleLine(vector<PT> p, PT A, PT B) {
	int n = p.size();
	p.push_back(p[0]);
	vector<data> inters;
	for (int i = 0; i < n; i++) {
		if (onLine(p[i], A, B)) inters.emplace_back(p[i], (i-1+n)%n, (i+1)%n);
		PT res;
		int ret = posLineLine(A, B, p[i], p[i+1], res);
		if (ret == 1 && scal(res, p[i], p[i+1]) < -EPS) inters.emplace_back(res, i, (i+1)%n);
	}
	sort(inters.begin(), inters.end());
	int sz = inters.size();
	bool chk[sz] = {0};
	int now = 0;
	vector<PT> pts;
	for (int i = 0; i < sz-1; i++) {
		PT inc; int id1, id2;
		tie(inc, id1, id2) = inters[i];
		pts.push_back(inc);
		PT cur; int idd1, idd2;
		tie(cur, idd1, idd2) = inters[i+1];
		if (i == sz-2) pts.push_back(cur);
		if (vect(p[id1], A, B) > EPS) now++;
		if (vect(p[id2], A, B) > EPS) now++;
		if (now & 1 || onSeg(cur, inc, p[id1]) || onSeg(cur, inc, p[id2])) chk[i] = 1; 
	}
	vector<pair<PT, PT>> ret;
	for (int i = 0; i < sz-1; i++) {
		if (chk[i]) {
			if (ret.size() && ret.back().second == pts[i]) ret.back().second = pts[i+1];
			else ret.emplace_back(pts[i], pts[i+1]);
		}
	}
	DB val = 0;
	for (auto t : ret) val += dis(t.first - t.second);
	return val;
}

const int N = 1100;
vector<PT> p;

int main() {
	ios_base::sync_with_stdio(0);
	cout.setf(ios::fixed); cout << setprecision(10);
	int n, m; cin >> n >> m;
	p.resize(n);
	for (int i = 0; i < n; i++) p[i].in();
	DB ss = 0;
	for (int i = 0; i < n; i++) {
	    ss += vect(p[i], p[(i+1)%n]);
	}
	if (ss < 0) reverse(p.begin(), p.end());
	while (m--) {
		PT A, B;
		A.in(), B.in();
		cout << interSimpleLine(p, A, B) << endl;
	}
}