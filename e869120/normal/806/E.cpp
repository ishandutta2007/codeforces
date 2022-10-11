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

class BIT {
public:
	vector<int>bit; int size_;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos&-pos);
		}
	}
	int sum(int pos) {
		pos++; int s = 0;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos&-pos);
		}
		return s;
	}
};

const int INF = 1000000000;
int N, A[1 << 19]; vector<pair<int, int>>S;
BIT Z1; RangeAddMinSegmentTree<int> Z2;

int downvote_border() {
	// 
	int cl = 0, cr = N, cm, maxn = N;
	for (int i = 0; i < 25; i++) {
		cm = (cl + cr) / 2;
		int B1 = -Z1.sum(cm);
		int B2 = S[cm].first;
		if (B1 < B2) { maxn = min(maxn, cm); cr = cm; }
		else { cl = cm; }
	}
	return maxn;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &A[i]); S.push_back(make_pair(A[i], i)); }
	sort(S.begin(), S.end());
	Z1.init(N + 1);
	Z2 = RangeAddMinSegmentTree<int>(N + 2);
	for (int i = 0; i < N + 2; i++) Z2.add(i, INF);
	
	for (int i = 0; i < N; i++) {
		int pos1 = lower_bound(S.begin(), S.end(), make_pair(A[i], i)) - S.begin();
		Z1.add(pos1, 1);
		Z2.add(pos1, -INF + A[i]);
		Z2.add(pos1, N + 2, -1);

		int V = downvote_border();
		int G1 = -Z1.sum(V - 1);
		int G2 = Z2.query(V, N + 2);
		printf("%d\n", min(G1 * 2, G2) + (i + 1));
	}
	return 0;
}