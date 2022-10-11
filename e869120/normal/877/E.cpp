#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

class SegmentTree {
public:
	vector<int>dat, lazy; int size_ = 1;
	void init(int sz) {
		while (sz >= size_) size_ *= 2;
		dat.resize(size_ * 2, 0);
		lazy.resize(size_ * 2, 0);
	}
	int sum(int pos, int val, int r) {
		if (r == 0) return val;
		int G = 1;
		while (pos < size_) { pos *= 2; G *= 2; }
		return G - val;
	}
	void plus(int l, int x) {
		l += size_;
		while (l >= 1) { dat[l] += x; l /= 2; }
	}
	void flip_(int l, int r, int a, int b, int u) {
		if (b <= l || r <= a) return;
		if (l <= a && b <= r) { lazy[u] ^= 1; return; }

		flip_(l, r, a, (a + b) >> 1, u * 2);
		flip_(l, r, (a + b) >> 1, b, u * 2 + 1);
		dat[u] = (sum(u * 2, dat[u * 2], lazy[u * 2]) + sum(u * 2 + 1, dat[u * 2 + 1], lazy[u * 2 + 1]));
	}
	void flip(int l, int r) {
		flip_(l, r, 0, size_, 1);
	}
	int getsum_(int l, int r, int a, int b, int laz, int u) {
		if (b <= l || r <= a) return 0;
		if (l <= a && b <= r) {
			return sum(u, dat[u], laz);
		}

		int s = 0;
		s += getsum_(l, r, a, (a + b) >> 1, laz^lazy[u * 2], u * 2);
		s += getsum_(l, r, (a + b) >> 1, b, laz^lazy[u * 2 + 1], u * 2 + 1);
		return s;
	}
	int getsum(int l, int r) {
		return getsum_(l, r, 0, size_, lazy[1], 1);
	}
};

int n, q, p[200009], r[200009], cl[200009], cr[200009], cnts; vector<int>x[200009];
SegmentTree X;

void dfs(int pos) {
	cnts++; cl[pos] = cnts;
	for (int i = 0; i < x[pos].size(); i++) dfs(x[pos][i]);
	cr[pos] = cnts;
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) { scanf("%d", &p[i]); x[p[i]].push_back(i); }
	for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
	dfs(1);

	X.init(n + 2);
	for (int i = 1; i <= n; i++) X.plus(cl[i], r[i]);

	cin >> q;
	for (int i = 1; i <= q; i++) {
		//for (int j = 1; j <= n; j++) cout << X.getsum(j, j + 1) << " "; cout << endl;
		string ss; int pos;
		cin >> ss >> pos;
		if (ss == "pow") {
			X.flip(cl[pos], cr[pos] + 1);
		}
		if (ss == "get") {
			printf("%d\n", X.getsum(cl[pos], cr[pos] + 1));
		}
	}
	return 0;
}