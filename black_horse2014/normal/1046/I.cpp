#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-8;

struct pt {
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
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

db vect(pt p1, pt p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

db scal(pt p1, pt p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

db sqr(db x) {
	return x * x;
}

db dis2(pt p) {
	return sqr(p.x) + sqr(p.y);
}

db dis(pt p) {
	return sqrt(dis2(p));
}

bool onSeg(pt p, pt p1, pt p2) {
	return scal(p1 - p, p2 - p) < eps;
}

pt projection(pt a, pt b, pt p) { 
	return a + (a - b) * (scal(p - a, a - b) / dis2(a - b)); 
}

int sig, ans;
db d1, d2;

void push(db x) {
	if (sig) {
		if (x > d2 + eps) {
			sig = 0;
		}
	} else {
		if (x < d1 + eps) {
			sig = 1;
			ans++;
		}
	}
}

int main() {
	int n; cin >> n >> d1 >> d2;
	pt prv;
	for (int i = 0; i < n; i++) {
		pt A, B;
		cin >> A.x >> A.y >> B.x >> B.y;
		pt d = B - A;
		if (i == 0) prv = d, push(dis(d));
		else {
			pt pj = projection(prv, d, pt(0, 0));
			if (onSeg(pj, prv, d)) {
				push(dis(pj));
			}
			push(dis(d));
			prv = d;
		}
	}
	cout << ans << endl;
}