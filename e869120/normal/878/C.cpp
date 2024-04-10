#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int> bit; int size_ = 1;
	
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
		int s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos&-pos);
		}
		return s;
	}
};

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

int N, K, A[50009][12], id[50009], minx = (1 << 30);
set<pair<int, int>> Set[12];
BIT Y; RangeAddMinSegmentTree<int> Z;

void adds(int pos) {
	minx = min(minx, id[pos]);
	Y.add(id[pos], 1);
	
	for (int i = 1; i <= K; i++) {
		int upvote = -1, downvote = -1;
		auto itr = Set[i].lower_bound(make_pair(A[pos][i], pos));
		if (itr != Set[i].end()) { upvote = (*itr).second; }
		if (itr != Set[i].begin()) { itr--; downvote = (*itr).second; }

		if (upvote >= 0 && id[upvote] > id[pos]) {
			Z.add(id[pos], id[upvote], 1);
		}
		if (downvote >= 0 && id[downvote] < id[pos]) {
			Z.add(id[downvote], id[pos], 1);
		}
		Set[i].insert(make_pair(A[pos][i], pos));
	}
}

int getval() {
	int cl = minx, cr = N + 1, cm, ret = (1 << 30);
	for (int i = 0; i < 30; i++) {
		cm = (cl + cr) >> 1;
		int G = Z.query(minx, cm + 1);
		if (G == 0) { ret = min(ret, cm); cr = cm; }
		else { cl = cm; }
	}
	int YY = Y.sum(ret);
	return YY;
}

int main() {
	scanf("%d%d", &N, &K);
	vector<pair<int, int>> I;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) cin >> A[i][j];
		I.push_back(make_pair(A[i][1], i));
	}
	sort(I.begin(), I.end());
	reverse(I.begin(), I.end());
	for (int i = 0; i < I.size(); i++) id[I[i].second] = i + 1;

	Y.init(N + 2);
	Z = RangeAddMinSegmentTree<int>(N + 2);

	for (int i = 1; i <= N; i++) {
		adds(i);
		printf("%d\n", getval());
	}
	return 0;
}