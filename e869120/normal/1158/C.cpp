#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	int v1, v2;
};

bool operator<(const Node &a1, const Node &a2) {
	if (a1.v1 < a2.v1) return true;
	return false;
}

Node operator+(const Node &a1, const Node &a2) {
	return { a1.v1 + a2.v1, a1.v2 + a2.v2 };
}

template<typename Type> class RangeAddMinSegmentTree {
private:
	unsigned size_; std::vector<Type> dat1, dat2;
	inline void update_(unsigned a, unsigned b, Type x, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			dat2[k] = dat2[k] + x;
			return;
		}
		update_(a, b, x, (k << 1), l, (l + r) >> 1);
		update_(a, b, x, (k << 1) + 1, (l + r) >> 1, r);
		dat1[k] = std::min(dat1[k << 1] + dat2[k << 1], dat1[(k << 1) + 1] + dat2[(k << 1) + 1]);
	}
	inline Type query_(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return Node{ (1 << 30), (1 << 30) };
		if (a <= l && r <= b) return dat1[k] + dat2[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc) + dat2[k];
	}
public:
	RangeAddMinSegmentTree() : size_(0), dat1(std::vector<Type>()), dat2(std::vector<Type>()) {};
	RangeAddMinSegmentTree(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat1.resize(size_ << 1, Node{ 0, 0 });
		dat2.resize(size_ << 1, Node{ 0, 0 });
	}
	/*
	template<class T>
	RangeAddMinSegmentTree(T begin_, T end_) {
		// !!! UNDER CONSTRUCTION !!! //
		unsigned n = (end_ - begin_);
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max());
		for (unsigned i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (unsigned i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	*/
	inline unsigned size() { return size_; }
	inline void add(unsigned i, Type x) {
		update_(i, i + 1, x, 1, 0, size_);
	}
	inline void add(unsigned l, unsigned r, Type x) {
		update_(l, r, x, 1, 0, size_);
	}
	inline Type query(unsigned l, unsigned r) {
		return query_(l, r, 1, 0, size_);
	}
};

int N, A[1 << 19], P[1 << 19], Q[1 << 19];
vector<pair<int, int>> ranged[1 << 19];

void solve() {
	for (int i = 1; i <= N + 1; i++) { ranged[i].clear(); Q[i] = 0; }

	RangeAddMinSegmentTree<Node> Z(N + 2);
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) continue;
		if (i + 1 < A[i]) ranged[i].push_back(make_pair(i + 1, A[i]));
		if (A[i] <= N) ranged[A[i]].push_back(make_pair(i, i + 1));

		int pl = i, pr = A[i]; if (A[i] == N + 1) pl = i + 1;
		if (pl < pr) { Q[pl]++; Q[pr]--; }
	}
	for (int i = 2; i <= N + 1; i++) Q[i] += Q[i - 1];
	for (int i = 1; i <= N; i++) { Z.add(i, Node{ Q[i], i }); }

	int cnts = 0;

	while (true) {
		Node id = Z.query(1, N + 1);
		if (id.v1 != 0) break;
		int pos = id.v2;

		P[pos] = cnts + 1;

		cnts++;
		for (int i = 0; i < ranged[pos].size(); i++) {
			Z.add(ranged[pos][i].first, ranged[pos][i].second, Node{ -1,0 });
		}
		Z.add(pos, pos + 1, Node{ (1 << 30), 0 });
	}

	if (cnts < N) {
		printf("-1\n");
	}
	else {
		for (int i = 1; i <= N; i++) { if (i >= 2) printf(" "); printf("%d", (N + 1) - P[i]); }
		printf("\n");
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) scanf("%d", &A[j]);
		solve();
	}
	return 0;
}