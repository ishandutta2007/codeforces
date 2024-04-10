#include <bits/stdc++.h>
using namespace std;

using db = double;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout << setprecision(10);
	int n; db r, v; cin >> n >> r >> v;
	v /= r;
	while (n--) {
		db s, t; cin >> s >> t;
		db l = t - s;
		l /= r;
		db st = 0, en = 1e10;
		for (int times = 0; times < 100; times++) {
			db md = (st + en) / 2;
			db a = cos(md) - 1, b = sin(md), c = l - md;
			if (sqrt(a * a + b * b) < c) st = md;
			else en = md;
		}
		cout << st / v << endl;
	}
}