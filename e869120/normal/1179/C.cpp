#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

template<typename Type> class RangeAddMinSegmentTree {
private:
	unsigned size_; std::vector<Type> dat1, dat2;
	inline void update_(unsigned a, unsigned b, Type x, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			dat2[k] += x; return;
		}
		update_(a, b, x, (k << 1), l, (l + r) >> 1);
		update_(a, b, x, (k << 1) + 1, (l + r) >> 1, r);
		dat1[k] = std::min(dat1[k << 1] + dat2[k << 1], dat1[(k << 1) + 1] + dat2[(k << 1) + 1]);
	}
	inline Type query_(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::max();
		if (a <= l && r <= b) return dat1[k] + dat2[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc) + dat2[k];
	}
public:
	RangeAddMinSegmentTree() : size_(0), dat1(std::vector<Type>()), dat2(std::vector<Type>()) {};
	RangeAddMinSegmentTree(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat1.resize(size_ << 1, 0);
		dat2.resize(size_ << 1, 0);
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

const int MAX_N = (1 << 20) - 1;
int N, M, Q, A[1 << 20], B[1 << 20];
RangeAddMinSegmentTree<int>E;

int solve() {
	int cl = 0, cr = MAX_N - 2, cm, maxn = -(1 << 30);
	for (int i = 0; i < 22; i++) {
		cm = (cl + cr) / 2;
		int Z = E.query(cm, MAX_N);
		if (Z < 0) { maxn = max(maxn, cm); cl = cm; }
		else { cr = cm; }
	}
	if (maxn == -(1 << 30)) return -1;
	return maxn;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= M; i++) scanf("%d", &B[i]);

	E = RangeAddMinSegmentTree<int>(MAX_N);
	for (int i = 1; i <= N; i++) E.add(0, A[i] + 1, -1);
	for (int i = 1; i <= M; i++) E.add(0, B[i] + 1, 1);

	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int A1, A2, A3; scanf("%d%d%d", &A1, &A2, &A3);
		if (A1 == 1) {
			E.add(0, A[A2] + 1, 1);
			A[A2] = A3;
			E.add(0, A[A2] + 1, -1);
		}
		if (A1 == 2) {
			E.add(0, B[A2] + 1, -1);
			B[A2] = A3;
			E.add(0, B[A2] + 1, 1);
		}
		printf("%d\n", solve());
	}
	return 0;
}