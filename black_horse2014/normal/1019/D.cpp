#include<bits/stdc++.h>
using namespace std;

const int N = 4400;
using ll = long long;

struct pt{
	int x, y;
	pt () {}
	pt (int x, int y) : x(x), y(y) {}
	bool operator < (const pt &p) const {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
} P[N];

pt operator - (const pt &p1, const pt &p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

ll vect(pt p1, pt p2) {
	return 1ll * p1.x * p2.y - 1ll * p2.x * p1.y;
}

void print(pt p) {
	cout << p.x << ' ' << p.y << endl;
}

int id[N], pid[N];
using dat = tuple<pt, int, int>;

void find(pt p1, pt p2, int n, ll v) {
	int st = 0, en = n - 1;
	while (st < en) {
		int md = st + en >> 1;
		if (vect(p2 - p1, P[id[md]] - p1) < v) st = md + 1;
		else en = md;
	}
	if (vect(p2 - p1, P[id[st]] - p1) == v) {
		puts("Yes");
		print(p1), print(p2);
		print(P[id[st]]);
		exit(0);
	}
}

int main() {
	int n; ll s; cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;
	vector<dat> vec;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			pt p1 = P[i], p2 = P[j];
			int i1 = i, i2 = j;
			if (p2 < p1) swap(p1, p2), swap(i1, i2);
			vec.emplace_back(p2 - p1, i1, i2);
		}
	}
	sort(vec.begin(), vec.end(), [](dat a, dat b) {
		pt p1, p2; int ia, ja, ib, jb;
		tie(p1, ia, ja) = a, tie(p2, ib, jb) = b;
		ll v = vect(p1, p2);
		if (v != 0) return v > 0;
		return p1 < p2;
	});
	for (int i = 0; i < n; i++) id[i] = i;
	sort(id, id + n, [](int a, int b) {
		return P[a] < P[b];
	});
	for (int i = 0; i < n; i++) pid[id[i]] = i;
	for (auto t : vec) {
		pt p; int i, j;
		tie(p, i, j) = t;
		find(P[i], P[j], n, -s*2);
		find(P[i], P[j], n, s*2);
		swap(id[pid[i]], id[pid[j]]);
		swap(pid[i], pid[j]);
	}
	puts("No");
}