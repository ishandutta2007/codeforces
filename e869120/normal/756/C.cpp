#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
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

int Q, p[1 << 17], t[1 << 17], m[1 << 17], id[1 << 17];
RangeAddMinSegmentTree<int> X;

int main() {
	scanf("%d", &Q); X = RangeAddMinSegmentTree<int>(Q + 2);
	for (int i = 1; i <= Q; i++) {
		scanf("%d%d", &p[i], &t[i]);
		if (t[i] == 1) scanf("%d", &m[i]);
	}
	for (int i = 1; i <= Q; i++) {
		if (t[i] == 0) X.add(0, p[i], 1);
		if (t[i] == 1) { X.add(0, p[i], -1); id[p[i]] = m[i]; }

		int cl = 0, cr = Q + 1, cm, maxn = -(1 << 30);
		for (int j = 0; j < 22; j++) {
			cm = (cl + cr) / 2;
			int Z = X.query(cm, Q + 2);
			if (Z == 0) { cr = cm; }
			else { cl = cm; maxn = max(maxn, cm); }
		}
		if (maxn == -(1 << 30)) printf("-1\n");
		else printf("%d\n", id[maxn + 1]);
	}
	return 0;
}