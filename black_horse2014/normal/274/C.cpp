#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-8;
const db pi = acos(-1);
const db inf = 1e20;

struct pt{
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

db getAngle(pt p) { return atan2(p.y, p.x); }

db dis(pt p) { return sqrt(p.x * p.x + p.y * p.y); }

db dis2(pt p) { return p.x * p.x + p.y * p.y; }

pt Bary(pt A, pt B, pt C, db a, db b, db c) {
	if (fabs(a + b + c) < eps) return pt(inf, inf);
    return (A * a + B * b + C * c) / (a + b + c);
}

pt outer(pt A, pt B, pt C) { 
    db a = dis2(B - C), b = dis2(C - A), c = dis2(A - B);
	return Bary(A, B, C, a * (b+c-a), b * (c+a-b), c * (a+b-c));
}

const int N = 110;

pt p[N];
int chk[N*N*N];

int main() {
	cout.setf(ios::fixed), cout << setprecision(10);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	db ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				int state = i*N*N + j*N + k;
				if (chk[state]) continue;
				pt o = outer(p[i], p[j], p[k]);
				if (o.x == inf) continue;
				db r = dis(o - p[i]);
				if (r > max(dis(p[j] - p[k]), max(dis(p[i] - p[j]), dis(p[i] - p[k])))) continue;
				vector<int> vec;
				int flg = 0;
				for (int l = 0; l < n; l++) {
					if (dis(o - p[l]) < r - eps) {
						flg = 1;
					}
					if (fabs(dis(o - p[l]) - r) < eps) {
						vec.push_back(l);
					}
				}
				assert(vec.size() >= 3);
				for (int ii = 0; ii < vec.size(); ii++) {
					for (int jj = ii+1; jj < vec.size(); jj++) {
						for (int kk = jj+1; kk < vec.size(); kk++) {
							int a = vec[ii], b = vec[jj], c = vec[kk];
							int state = a*N*N+b*N+c;
							chk[state] = 1;
						}
					}
				}
				if (flg) continue;
				vector<db> ang;
				for (int l = 0; l < vec.size(); l++) {
					ang.push_back(getAngle(p[vec[l]] - o));
				}
				sort(ang.begin(), ang.end());
				flg = 0;
				for (int i = 0; i + 1 < ang.size(); i++) {
					if (ang[i+1] - ang[i] > pi - 1e-12) {
						flg = 1;
						break;
					}
				}
				if (ang[0] + pi + pi - ang.back() > pi - 1e-12) flg = 1;
				if (!flg) ans = max(ans, r);
			}
		}
	}
	if (ans == -1) cout << -1 << endl;
	else cout << ans << endl;
}