#include <iostream>
#include <vector>
#include <set>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	int l, r; long long val;
};

class BIT {
public:
	vector<Node> vec; int size_ = 131072;

	void init() {
		vec.push_back(Node{ -1, -1, 0 });
	}
	void add(int pos, long long x) {
		int cl = 0, cr = size_, cx = 0;
		for (int i = 16; i >= 0; i--) {
			vec[cx].val += x;
			int cm = (cl + cr) >> 1;
			if (pos < cm) {
				if (vec[cx].l == -1) { vec[cx].l = vec.size(); vec.push_back(Node{ -1,-1,0 }); }
				cx = vec[cx].l;
				cr = cm;
			}
			else {
				if (vec[cx].r == -1) { vec[cx].r = vec.size(); vec.push_back(Node{ -1,-1,0 }); }
				cx = vec[cx].r;
				cl = cm;
			}
		}
		vec[cx].val += x;
	}
	long long sum(int pos) {
		// x 
		int cl = 0, cr = size_, cx = 0; long long s = 0;
		for (int i = 16; i >= 0; i--) {
			int cm = (cl + cr) >> 1;
			if (pos < cm) {
				cx = vec[cx].l; cr = cm;
			}
			else {
				if (vec[cx].l >= 0) s += vec[vec[cx].l].val;
				cx = vec[cx].r; cl = cm;
			}
			if (cx == -1) break;
		}
		if (cx != -1) s += vec[cx].val;
		return s;
	}
};

BIT Z[100009];

void adds(int px, int py, long long t) {
	while (px <= 100005) {
		Z[px].add(py, t);
		px += (px & -px);
	}
}

long long getsum(int px, int py) {
	long long v = 0;
	while (px >= 1) {
		v += Z[px].sum(py);
		px -= (px&-px);
	}
	return v;
}

// ---

int N, M, A[1 << 17];
set<int> Set[1 << 17];

void add_v(int pos, int col) {
	int cl = -1, cr = -1;

	auto itr1 = Set[col].lower_bound(pos);
	if (itr1 != Set[col].begin()) {
		itr1--; cl = (*itr1);
	}

	auto itr2 = Set[col].lower_bound(pos);
	if (itr2 != Set[col].end()) {
		cr = (*itr2);
	}

	if (cl != -1 && cr != -1) {
		adds((N + 1) - cl, cr, (cl - cr));
	}
	if (cl >= 0) adds((N + 1) - cl, pos, (pos - cl));
	if (cr >= 0) adds((N + 1) - pos, cr, (cr - pos));
	Set[col].insert(pos);
}

void lose_v(int pos, int col) {
	Set[col].erase(pos);

	int cl = -1, cr = -1;

	auto itr1 = Set[col].lower_bound(pos);
	if (itr1 != Set[col].begin()) {
		itr1--; cl = (*itr1);
	}

	auto itr2 = Set[col].lower_bound(pos);
	if (itr2 != Set[col].end()) {
		cr = (*itr2);
	}

	if (cl >= 0) adds((N + 1) - cl, pos, -(pos - cl));
	if (cr >= 0) adds((N + 1) - pos, cr, -(cr - pos));

	if (cl != -1 && cr != -1) {
		adds((N + 1) - cl, cr, -(cl - cr));
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= 100005; i++) Z[i].init();
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		add_v(i, A[i]);
	}
	for (int i = 1; i <= M; i++) {
		int ty, p, x; scanf("%d%d%d", &ty, &p, &x);
		if (ty == 1) {
			lose_v(p, A[p]);
			A[p] = x;
			add_v(p, A[p]);
		}
		if (ty == 2) {
			long long S = getsum((N + 1) - p, x);
			printf("%lld\n", S);
		}
	}
	return 0;
}