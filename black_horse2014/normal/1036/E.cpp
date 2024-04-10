#include<bits/stdc++.h>
using namespace std;

using ll = long long;
unordered_set<ll> S;

int sgn(ll x) { return (x > 0) - (x < 0); }

struct pt{
	int x, y;
	pt (int x = 0, int y = 0): x(x), y(y) {}
	void in() { cin >> x >> y; }
	ll hash() {
		return 1ll * x * 1e7 + y;
	}
};

pt operator - (const pt &p1, const pt &p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

pt operator + (const pt &p1, const pt &p2) {
	return pt(p1.x + p2.x, p1.y + p2.y);
}

ll vect(pt p, pt p1, pt p2) {
	return 1ll * (p1.x - p.x) * (p2.y - p.y) - 1ll * (p1.y - p.y) * (p2.x - p.x);
}

bool cross(pt p1, pt p2, pt p3, pt p4) {
	return sgn(vect(p1, p3, p4)) * sgn(vect(p2, p3, p4)) <= 0 && sgn(vect(p3, p1, p2)) * sgn(vect(p4, p1, p2)) <= 0;
}

int inter(pt p1, pt p2, pt p3, pt p4, pt &ret) {
	ll s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
	pt d = p4 - p3;
	ll x = d.x * s1, y = d.y * s1;
	ll div = s1 - s2;
	if (x % div || y % div) return 0;
	x /= div, y /= div;
	ret = p3 + pt(x, y);
	return 1;
}

const int N = 1100;

pt A[N], B[N];

int main() {
	int n; cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		A[i].in(), B[i].in();
		ans += abs(__gcd(B[i].x - A[i].x, B[i].y - A[i].y)) + 1;
		S.clear();
		for (int j = 0; j < i; j++) {
			if (cross(A[i], B[i], A[j], B[j])) {
				pt tmp;
				if (inter(A[i], B[i], A[j], B[j], tmp)) {
					S.insert(tmp.hash());
				}
			}
		}
		ans -= S.size();
	}
	cout << ans << endl;
}