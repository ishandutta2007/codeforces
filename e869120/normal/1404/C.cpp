#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
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
	int size_ = 1;
	vector<int> bit;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos & -pos);
		}
	}
	int sum(int pos) {
		pos++; int s = 0;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
};

// 
int N, Q, A[1 << 19], S[1 << 19];
int L[1 << 19], R[1 << 19];
int T[1 << 19];

// 
int Answer[1 << 19];

// 
long long MOD = 1000000;
BIT Z;
RangeAddMinSegmentTree<long long> Z2;
vector<pair<long long, int>> X[1 << 19];

void solve(int pos) {
	while (true) {
		long long T = Z2.query(pos, N + 1); T += MOD * MOD * MOD;
		long long U1 = T / MOD; U1 -= MOD * MOD;
		long long U2 = T % MOD;
		if (U1 > 0) break;
		Z.add(U2, 1);
		Z2.add(U2, MOD * MOD);
		Z2.add(U2, N + 1, -MOD);
	}
}

int main() {
	// 
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= Q; i++) {
		int px, py; scanf("%d%d", &px, &py);
		L[i] = px + 1;
		R[i] = N - py;
	}

	// 
	for (int i = 1; i <= Q; i++) X[L[i]].push_back(make_pair(R[i], i));
	for (int i = 0; i <= N; i++) T[i] = N + 1;
	Z.init(N + 2);
	Z2 = RangeAddMinSegmentTree<long long>(N + 2);
	for (int i = 1; i <= N; i++) {
		if (i < A[i]) Z2.add(i, MOD * MOD + 1LL * i);
		else Z2.add(i, 1LL * (i - A[i]) * MOD + 1LL * i);
	}

	// 
	for (int i = N; i >= 1; i--) {
		solve(i);
		for (pair<int, int> j : X[i]) {
			Answer[j.second] = Z.sum(j.first);
		}
	}

	// 
	for (int i = 1; i <= Q; i++) printf("%d\n", Answer[i]);
	return 0;
}