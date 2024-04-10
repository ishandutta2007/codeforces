#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

struct Node { int val, l, r; };

class SegmentTree {
public:
	vector<Node>dat; int size_ = 0;
	void init() {
		size_ = 1; dat.push_back(Node{ 0,-1,-1 });
	}
	void add_(int l, int r, int x, int a, int b, int u) {
		if (b <= l || r <= a) return;
		dat[u].val += x;
		if (l <= a && b <= r) return;
		
		if (dat[u].l == -1) { dat[u].l = size_; dat.push_back(Node{ 0,-1,-1 }); size_++; }
		if (dat[u].r == -1) { dat[u].r = size_; dat.push_back(Node{ 0,-1,-1 }); size_++; }
		add_(l, r, x, a, (a + b) >> 1, dat[u].l);
		add_(l, r, x, (a + b) >> 1, b, dat[u].r);
	}
	void add(int l, int x) {
		add_(l, l + 1, x, 0, (1 << 30), 0);
	}
	int getmin(int v) {
		int cx = 0, J = 0;
		for (int i = 29; i >= 0; i--) {
			if ((v / (1 << i)) % 2 == 1) {
				if (dat[cx].r >= 0 && dat[dat[cx].r].val >= 1) { cx = dat[cx].r; }
				else { J += (1 << i); cx = dat[cx].l; }
			}
			else {
				if (dat[cx].l >= 0 && dat[dat[cx].l].val >= 1) {cx = dat[cx].l; }
				else { J += (1 << i); cx = dat[cx].r; }
			}
		}
		return J;
	}
};

int n, a[300009], b[300009]; vector<int>vec;

int main() {
	cin >> n; SegmentTree X; X.init();
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) { scanf("%d", &b[i]); X.add(b[i], 1); }
	for (int i = 1; i <= n; i++) {
		int F = X.getmin(a[i]);
		vec.push_back(F);
		X.add(a[i] ^ F, -1);
	}
	for (int i = 0; i < vec.size(); i++) {
		if (i) printf(" "); printf("%d", vec[i]);
	}
	cout << endl;
	return 0;
}