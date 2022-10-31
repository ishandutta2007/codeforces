#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-8;
const int N = 4400;

struct pt {
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
};

struct line{
	db a, b, c;
	line (){}
	line (db _a, db _b, db _c) {
		a = _a, b = _b, c = _c;
		if (a < 0) a *= -1, b *= -1, c *= -1;
	}
	bool operator < (const line &l) const {
		return atan2(b, a) < atan2(l.b, l.a);
	}
} L[N];

pt inter(line l1, line l2) {
	db m = l1.a * l2.b - l1.b * l2.a;
	return pt((l1.c * l2.b - l2.c * l1.b) / m, (l2.c * l1.a - l1.c * l2.a) / m);
}

db vect(pt p1, pt p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

int main() {
	cout.setf(ios::fixed), cout<<setprecision(10);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		L[i] = line(a, b, c);
	}
	sort(L, L + n);
	db ans = 0;
	for (int i = 0; i < n; i++) {
		pt ss = pt(0, 0);
		for (int j = i + 1; j < i + n; j++) {
			pt inc = inter(L[i], L[j%n]);
			ans += vect(inc, ss);
			ss = pt(ss.x + inc.x, ss.y + inc.y);
		}
	}
	cout << abs(ans / n / (n - 1) / (n - 2) * 3);
}