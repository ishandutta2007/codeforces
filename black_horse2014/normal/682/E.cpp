#include <bits/stdc++.h>
using namespace std;

struct pt{
	int x, y;
	pt (int x = 0, int y = 0) : x(x), y(y) {}
	void print() {
		cout << x << ' ' << y << endl;
	}
	bool operator < (const pt &p) const {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
};

using ll = long long;

pt operator + (const pt &p1, const pt &p2) {
	return pt(p1.x + p2.x, p1.y + p2.y);
}

pt operator - (const pt &p1, const pt &p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

ll vect(pt p1, pt p2) {
	return 1ll * p1.x * p2.y - 1ll * p1.y * p2.x;
}

ll vect(pt p, pt p1, pt p2) {
	return vect(p1 - p, p2 - p);
}

vector<pt> convex(vector<pt> &ps) {
	sort(ps.begin(), ps.end());
	if (ps.size() <= 1) return ps;
	int k = 0, n = ps.size();
	vector<pt> ch(n + n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && vect(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) 
		while (k >= t && vect(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	ch.resize(k-1);
	return ch;
}

int main() {
	int n; ll s; cin >> n >> s;
	vector<pt> ps;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		ps.emplace_back(x, y);
	}
	vector<pt> p = convex(ps);
	int cn = p.size();
	ll ms = 0; int I, J, K;
	for (int i = 0; i < cn-1; i++) {
		for (int j = i+1, k = (i+2) % cn; i < j && j < k; j = (j+1)%cn) {
			for (; ; k = (k+1) % cn) {
				ll ss = vect(p[i], p[j], p[k]);
				if (ms < ss) ms = ss, I = i, J = j, K = k;
				if (vect(p[j] - p[i], p[(k+1)%cn] - p[k]) <= 0) break;
			}
		}
	}
	(p[I] + p[J] - p[K]).print();
	(p[I] + p[K] - p[J]).print();
	(p[K] + p[J] - p[I]).print();
}