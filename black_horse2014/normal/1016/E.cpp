#include <bits/stdc++.h>
using namespace std;

using db = double;

const int N = 1100000;

int p[N], s[N];
int n;

db low(db x) {
	int ix = (int)floor(x);
	int id = upper_bound(p, p + n + n, ix) - p - 1;
	if (id & 1) return s[id];
	db ret = id ? s[id - 1] : 0;
	return ret + (x - p[id]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout << setprecision(10);
	int h, a, b; cin >> h >> a >> b; h *= -1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i+i] >> p[i+i+1];
	for (int i = 0; i < n; i++) s[i+i+1] = (i ? s[i+i-1] : 0) + p[i+i+1] - p[i+i];
	int q; cin >> q;
	while (q--) {
		int x, y; cin >> x >> y;
		db lx = 1. * (a - x) * y / (y + h) + x;
		db rx = 1. * (b - x) * y / (y + h) + x;
		cout << (low(rx) - low(lx)) * (y + h) / y << endl;
	}
}