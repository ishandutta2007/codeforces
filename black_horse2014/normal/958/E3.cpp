#include<bits/stdc++.h>
using namespace std;

typedef double DB;
const DB PI = acos(DB(-1));
const DB INF = 1e10;
const DB EPS = 1e-8;

inline DB sqr(DB x) {
	return x * x;
}

struct PT {
	DB x, y;

	PT() {}
	PT(DB x, DB y) : x(x), y(y) {}
	void in() {
		scanf("%lf%lf", &x, &y);
	}
};

bool operator<(const PT& p1, const PT& p2) {
	if (fabs(p1.x - p2.x) > EPS) return p1.x < p2.x;
	return p1.y + EPS < p2.y;
}

bool operator==(const PT& p1, const PT& p2) {
	return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

PT operator+(PT p1, PT p2) {
	return PT(p1.x + p2.x, p1.y + p2.y);
}

PT operator-(PT p1, PT p2) {
	return PT(p1.x - p2.x, p1.y - p2.y);
}

PT operator*(PT p, DB c) {
	return PT(p.x * c, p.y * c);
}

PT operator/(PT p, DB c) {
	return PT(p.x / c, p.y / c);
}

DB dis(PT p) {
	return sqrt(sqr(p.x) + sqr(p.y));
}

DB dis2(PT p) {
	return sqr(p.x) + sqr(p.y);
}

DB dis2(PT p1, PT p2) {
	return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

DB dis(PT p1, PT p2) {
	return sqrt(dis2(p1, p2));
}

DB vect(PT p1, PT p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

DB scal(PT p1, PT p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

DB getAngle(PT p) {
	return atan2(p.y, p.x);
}

DB vect(PT p, PT p1, PT p2) {
	return vect(p1 - p, p2 - p);
}

DB scal(PT p, PT p1, PT p2) {
	return scal(p1 - p, p2 - p);
}

DB getAngle(PT p, PT p1, PT p2) {
	return acos(scal(p, p1, p2) / dis(p, p1) / dis(p, p2));
}

DB disToLine(PT p, PT p1, PT p2) {
	return fabs(vect(p, p1, p2)) / dis(p1, p2);
}

DB disToSeg(PT p, PT p1, PT p2) {
	if (scal(p1, p, p2) < 0) return dis(p, p1);
	if (scal(p2, p, p1) < 0) return dis(p, p2);
	return disToLine(p, p1, p2);
}

bool onLine(PT p, PT p1, PT p2) {
	return fabs(vect(p1 - p, p2 - p)) < EPS;
}

bool onSeg(PT p, PT p1, PT p2) {
	if (!onLine(p, p1, p2)) return 0;
	return (p1.x - p.x) * (p2.x - p.x) < EPS && (p1.y - p.y) * (p2.y - p.y) < EPS;
}

PT projection(PT a, PT b, PT p) {
	return a + (a - b) * scal(p - a, a - b) / dis2(a - b);
}

const int N = 21000;
PT P[N], q[N];
int _id[N];
int n;
int id[N], rid[N];
int to[N];
vector<int> vec;

void solve(bitset<N> B) {
	vec.clear();
	for (int i = 1; i <= n + n; i++) if (B[i]) vec.push_back(id[i]);
	int K = vec.size();
	if (K == 2) {
		int x = vec[0], y = vec[1];
		if (x <= n) to[x] = y - n;
		else to[y] = x - n;
		return;
	}
	int m = 0;
	for (int i = 0; i < K; i++) {
		while (m > 1 && vect(q[m - 2], q[m - 1], P[vec[i]]) < EPS) m--;
		_id[m] = vec[i];
		q[m++] = P[vec[i]];
	}
	int k = m;
	for (int i = K - 2; i >= 0; i--) {
		while (m > k && vect(q[m - 2], q[m - 1], P[vec[i]]) < EPS) m--;
		_id[m] = vec[i];
		q[m++] = P[vec[i]];
	}
	--m;
	q[m] = q[0];
	_id[m] = _id[0];
	for (int i = 0; i < m; i++) {
		int flg = 0;
		if (_id[i] <= n && n < _id[i + 1]) flg = 1, to[_id[i]] = _id[i + 1] - n;
		if (n < _id[i] && _id[i + 1] <= n) flg = 1, to[_id[i + 1]] = _id[i] - n;
		if (!flg) continue;
		bitset<N> _B;
		for (int j = 0; j < K; j++) if (vec[j] != _id[i] && vec[j] != _id[i + 1]) _B[rid[vec[j]]] = 1;
		solve(_B);
		return;
	}
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		int cur = vec[i];
		if (cur > n) cnt++;
		else cnt--;
		if (cnt == 0) {
			bitset<N> _B1, _B2;
			for (int j = 0; j <= i; j++) _B1[rid[vec[j]]] = 1;
			for (int j = i + 1; j < K; j++) _B2[rid[vec[j]]] = 1;
			solve(_B1);
			solve(_B2);
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n + n; i++) P[i].in(), id[i] = i;
	sort(id + 1, id + n + n + 1, [](int a, int b) {return P[a].x == P[b].x ? P[a].y < P[b].y : P[a].x < P[b].x; });
	for (int i = 1; i <= n + n; i++) rid[id[i]] = i;
	bitset<N> B;
	for (int i = 1; i <= n + n; i++) B[i] = 1;
	solve(B);
	for (int i = 1; i <= n; i++) printf("%d\n", to[i]);
}