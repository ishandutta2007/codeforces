#include<bits/stdc++.h>
using namespace std;

using DB = double;
const DB EPS = 1e-8;
const DB INF = 1e10;

struct PT{
	DB x, y;
	PT (DB x = 0, DB y = 0) : x(x), y(y) {}
	void in() {
		int _x, _y;
		cin >> _x >> _y;
		x = _x, y = _y;
	}
	bool operator < (const PT &p) const {
		if (fabs(p.x - x) < EPS) return y < p.y - EPS;
		return x < p.x;
	}
	bool operator == (const PT &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
};

PT operator + (PT p1, PT p2) { return PT(p1.x + p2.x, p1.y + p2.y); }
PT operator - (PT p1, PT p2) { return PT(p1.x - p2.x, p1.y - p2.y); }
PT operator * (PT p, DB d) { return PT(p.x * d, p.y * d); }
PT operator / (PT p, DB d) { return PT(p.x / d, p.y / d); }

DB vect(PT p, PT p1, PT p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

const int N = 110000;

int n, e1, e2;
int w, h, t[N];
PT p[N];
PT dir[4] = {PT(-1, -1), PT(1, -1), PT(1, 1), PT(-1, 1)};
PT brd[4] = {PT(0, 0), PT(1, 0), PT(1, 1), PT(0, 1)};

PT inter(PT A, PT B, DB a, DB b, DB c) {
	DB val1 = A.x * a + A.y * b + c;
	DB val2 = B.x * a + B.y * b + c;
	if (val1 * val2 > EPS) return PT(INF, INF);
	if (fabs(val1) < EPS && fabs(val2) < EPS) return A;
	return (A * val2 - B * val1) / (val2 - val1);
}

vector<PT> convex(vector<PT>& ps) {
	if ((int)ps.size() <= 1) return ps;
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<PT> ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && vect(ch[k - 2], ch[k - 1], ps[i]) < EPS) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && vect(ch[k - 2], ch[k - 1], ps[i]) < EPS) --k;
	ch.resize(k - 1);
	return ch;
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> w >> h >> e1 >> e2;
	for (int i = 0; i < n; i++) {
		cin >> t[i]; p[i].in();
	}
	DB st = 0, en = 10;
	for (int times = 0; times < 35; times++) {
		PT A = PT(1. * e1 / w, 1. * e2 / w);
		PT B = A;
		DB md = (st + en) / 2;
		DB prv = 0;
		int flg = 0;
		for (int i = 0; i < n; i++) {
			DB d = t[i] - prv;
			prv = t[i];
			vector<PT> pts;
			for (int j = 0; j < 4; j++)
				pts.push_back(A + dir[j] * d * md), pts.push_back(B + dir[j] * d * md);
			pts = convex(pts);
			DB a = 1. - (DB)p[i].y / h, b = (DB)p[i].y / h, c = -1. * p[i].x / w;
			vector<PT> incs;
			for (int j = 0; j < pts.size(); j++) {
				PT L = pts[j], R = pts[(j+1)%pts.size()];
				PT inc = inter(L, R, a, b, c);
				if (inc.x == INF) continue;
//				assert(fabs(a * inc.x + b * inc.y + c) < 1e-3);
				incs.push_back(inc);
			}
			if (!incs.size()) {
				flg = 1;
				break;
			}
			sort(incs.begin(), incs.end());
			A = incs[0], B = incs.back();
			vector<PT> binc;
			for (int j = 0; j < 4; j++) {
				PT inc = inter(brd[j], brd[(j+1)%4], a, b, c);
				if (inc.x == INF) continue;
//				assert(fabs(a * inc.x + b * inc.y + c) < 1e-3);
				binc.push_back(inc);
			}
			sort(binc.begin(), binc.end());
			if (A < binc[0]) A = binc[0];
			if (binc.back() < B) B = binc.back();
			if (B < A) {
				flg = 1;
				break;
			}
		}
		if (flg) st = md;
		else en = md;
	}
	if (st > 10 - EPS) puts("-1");
	else printf("%.10lf\n", st * w);
}