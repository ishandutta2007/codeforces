#include <bits/stdc++.h>
using namespace std;

const int N = 2200;

using db = double;
const db eps = 1e-8;
const db pi = acos(-1);

struct pt {
	db x, y;
	pt (db x = 0, db y = 0) : x(x), y(y) {}
	bool operator < (const pt &p) const {
		if (fabs(x - p.x) > eps) return x < p.x;
		return y < p.y - eps;
	}
};

db x[N], y[N], cx[N], cy[N];
bool ban[N];

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

db vect(pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

db vect(pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void convex(vector<pt> &vec) {
	if (vec.size() <= 1) return;
	sort(vec.begin(), vec.end());
	int n = vec.size(), k = 0;
	vector<pt> ch(n + n);
	for (int i = 0; i < n; ch[k++] = vec[i++])
		while (k >= 2 && vect(ch[k-2], ch[k-1], vec[i]) < eps) --k;
	for (int i = n - 2, t = k+1; i >= 0; ch[k++] = vec[i--]) 
		while (k >= t && vect(ch[k-2], ch[k-1], vec[i]) < eps) --k;
	ch.resize(k - 1);
	vec = ch;
} 

int main() {
	int n; cin >> n;
	db sx = 0, sy = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		sx += x[i], sy += y[i];
	}
	sx /= n, sy /= n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (ban[i] || ban[j]) continue;
			db mx = (x[i] + x[j]) / 2, my = (y[i] + y[j]) / 2;
			if (fabs(mx - sx) < eps && fabs(my - sy) < eps) {
				ban[i] = ban[j] = 1;
			}
		}
	}
	vector<pt> vec;
	for (int i = 0; i < n; i++) if (!ban[i]) vec.emplace_back(x[i], y[i]);
	if (vec.size() <= 2) return puts("-1"), 0;
	convex(vec);
	int vn = vec.size();
	for (int i = 0; i < vn; i++) cx[i] = vec[i].x, cy[i] = vec[i].y;
	auto nxt = [&](int x) { return (x == vn-1) ? 0 : x+1; };
	vector<db> ans;
	for (int i = 0, j = 1; i < j; i++) {
		for (; ; j = nxt(j)) {
			db mx = (cx[i] + cx[j]) / 2, my = (cy[i] + cy[j]) / 2;
			db dx = mx - sx, dy = my - sy;
			db alpha = atan2(dy, dx);
			if (alpha < 1e-13) alpha += pi;
			vector<db> values;
			for (int k = 0; k < n; k++) {
				values.push_back(x[k] * sin(-alpha) + y[k] * cos(alpha));
			}
			db vx = sx * sin(-alpha) + sy * cos(alpha);
			sort(values.begin(), values.end());
			int flg = 0;
			for (int k = 0; k < n; k++) {
				if (fabs(values[k] + values[n - k - 1] - 2 * vx) > eps) {
					flg = 1;
					break;
				} 
			}
			if (!flg) ans.push_back(alpha);
			if (vect(vec[i+1] - vec[i], vec[nxt(j)] - vec[j]) < eps) break;
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end(), [](db x, db y) { return fabs(x - y) < 1e-13; }), ans.end());
	cout << ans.size() << endl;
}