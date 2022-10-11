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

long long N, Q, cl[1 << 19], cr[1 << 19], cnts, dist[1 << 19];
vector<pair<int, long long>> X[1 << 19];
RangeAddMinSegmentTree<long long> Z;

long long qv[1 << 19], ql[1 << 19], qr[1 << 19], ans[1 << 19]; vector<int>qs[1 << 19];

void dfs(int pos, long long depth) {
	dist[pos] = depth; cnts++; cl[pos] = cnts;
	for (int i = 0; i < X[pos].size(); i++) dfs(X[pos][i].first, depth + X[pos][i].second);
	cr[pos] = cnts;
}

void dfs2(int pos) {
	for (int i = 0; i < qs[pos].size(); i++) {
		int ind = qs[pos][i];
		ans[ind] = Z.query(ql[ind], qr[ind] + 1);
	}
	for (int i = 0; i < X[pos].size(); i++) {
		Z.add(1, N + 1, X[pos][i].second);
		Z.add(cl[X[pos][i].first], cr[X[pos][i].first] + 1, -2LL * X[pos][i].second);

		dfs2(X[pos][i].first);

		Z.add(1, N + 1, -X[pos][i].second);
		Z.add(cl[X[pos][i].first], cr[X[pos][i].first] + 1, 2LL * X[pos][i].second);
	}
}

int main() {
	scanf("%lld%lld", &N, &Q);
	for (int i = 2; i <= N; i++) {
		int p, w; scanf("%d%d", &p, &w);
		X[p].push_back(make_pair(i, w));
	}
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld%lld", &qv[i], &ql[i], &qr[i]);
		qs[qv[i]].push_back(i);
	}

	dfs(1, 0);

	Z = RangeAddMinSegmentTree<long long>(N + 2);
	for (int i = 1; i <= N; i++) {
		if (X[i].size() == 0) Z.add(i, i + 1, dist[i]);
		else Z.add(i, i + 1, (1LL << 60));
	}
	dfs2(1);

	for (int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
	return 0;
}