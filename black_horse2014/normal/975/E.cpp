#include <bits/stdc++.h>
using namespace std;

using db = long double;
const db pi = acosl(-1);

struct pt {
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
	void in() {
		int _x, _y;
		cin >> _x >> _y;
		x = _x, y = _y;
	}
};

pt operator + (const pt &p1, const pt &p2) {
	return pt(p1.x + p2.x, p1.y + p2.y); 
}

pt operator - (const pt &p1, const pt &p2) {
	return pt(p1.x - p2.x, p1.y - p2.y); 
}

pt operator * (const pt &p, const db &d) {
	return pt(p.x * d, p.y * d);
}

pt operator / (const pt &p, const db &d) {
	return pt(p.x / d, p.y / d);
}

db vect(const pt &p1, const pt &p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

db dis(const pt &p) {
	return sqrtl(p.x * p.x + p.y * p.y);
}

const int N = 11000;

pt p[N], d[N], g;
db an[N], si[N], co[N], di[N];
int n;

void getG() {
	p[n] = p[0];
	db x = 0, y = 0, ss = 0;
	for (int i = 0; i < n; i++) {
		pt p1 = p[i], p2 = p[i+1];
		db s = vect(p1, p2);
		x += s * (p1.x + p2.x) / 3;
		y += s * (p1.y + p2.y) / 3;
		ss += s;
	}
	g = pt(x / ss, y / ss);
}

int hid = -1;

pt query(int v) {
	if (hid == -1) return p[v];
	return pt(d[v].x * co[hid] - d[v].y * si[hid], d[v].x * si[hid] + d[v].y * co[hid]) + g;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout << setprecision(5);
	int q; cin >> n >> q;
	for (int i = 0; i < n; i++) p[i].in();
	db ox = p[0].x, oy = p[0].y;
	for (int i = 0; i < n; i++) p[i] = p[i] - pt(ox, oy);
	getG();
	for (int i = 0; i < n; i++) {
		d[i] = p[i] - g;
		di[i] = dis(d[i]);
		si[i] = d[i].x / di[i];
		co[i] = d[i].y / di[i];
	}
	int a = 0, b = 1;
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int f, t; cin >> f >> t;
			--f, --t;
			int up;
			if (a == f) a = t, up = b;
			else b = t, up = a;
			pt pp = query(up);
			g = pp - pt((db)0, di[up]);
			hid = up;
		} else {
			int v; cin >> v;
			--v;
			pt pv = query(v);
			cout << pv.x + ox << ' ' << pv.y + oy << endl;
		}
	}
}