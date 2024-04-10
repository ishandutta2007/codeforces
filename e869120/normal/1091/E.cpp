#include <iostream>
#include <vector>
#include <limits>
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

long long N, A[1 << 19], anti_A[1 << 19], rem[1 << 19], D; vector<long long>G, G2;
RangeAddMinSegmentTree<long long>X;

void upgrade(int u) {
	X.add(u, N + 1, -1); A[u]++;
	if (A[u] < (u + 1)) X.add(A[u], u + 1, 1);
}

int main() {
	scanf("%d", &N); X = RangeAddMinSegmentTree<long long>(N + 2);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); D += A[i]; }
	sort(A + 1, A + N + 1, greater<int>());
	for (int i = 1; i <= N + 1; i++) anti_A[i] = -A[i];

	// 
	for (int i = 1; i <= N + 1; i++) rem[i] = rem[i - 1] - A[i];
	
	// 
	for (int i = 1; i <= N + 1; i++) rem[i] += 1LL * i * (i - 1);
	G2.push_back(0);
	for (int i = N; i >= 1; i--) {
		G.push_back(A[i + 1]); G2.push_back(G2[G2.size() - 1] + A[i + 1]);

		int pos1 = lower_bound(G.begin(), G.end(), i) - G.begin();
		long long V1 = G2[pos1] + 1LL * i * (G.size() - pos1);
		rem[i] += V1;
	}

	// 
	for (int i = 1; i <= N; i++) X.add(i, rem[i]);

	// 
	vector<long long>ans;
	for (int i = 0; i <= N; i++) {
		long long E = X.query(1, N + 2);
		if (E >= 0 && D % 2 == 0) ans.push_back(i);

		int pos1 = lower_bound(anti_A + 1, anti_A + N + 2, -1LL * i) - anti_A;
		anti_A[pos1]--; upgrade(pos1); D++;
	}

	// 
	if (ans.size() >= 1) {
		for (int i = 0; i < ans.size(); i++) { if (i) printf(" "); printf("%lld", ans[i]); }
		printf("\n");
	}
	else {
		printf("-1\n");
	}
	return 0;
}