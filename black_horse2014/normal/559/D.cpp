#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-10;

const int N = 220000;

struct pt {
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
} p[N];

int x[N], y[N];

db vect(pt p1, pt p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

const int M = 100;
const int L = 1100;

db pw[N], ipw[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout << setprecision(10);
	pw[0] = 1, ipw[0] = 1;
	for (int i = 1; i < L; i++) pw[i] = pw[i-1]*2, ipw[i] = ipw[i-1]/2;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		p[i] = pt(x[i], y[i]);
		x[i+n] = x[i], y[i+n] = y[i];
	}
	for (int i = 0; i < n; i++) p[i+n] = p[i];
	db ss = 0, on = 0, sz = 0;
	db all = pow(2, n) - 1 - n - 1. * n * (n-1) / 2;
	if (n > 200) all = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < min(i+M, i+n-1); j++) {
			db cnt;
			if (n > 200) cnt = ipw[j-i+1];
			else cnt = pw[i+n-1-j] - 1;
			ss += cnt * vect(p[i], p[j]);
			int d = abs(__gcd(x[j] - x[i], y[j] - y[i]));
			on += cnt * d;
		}
	}
	cout << (ss / 2 - on / 2) / all + 1 << endl;
}