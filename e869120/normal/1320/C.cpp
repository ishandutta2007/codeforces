#include <iostream>
#include <limits>
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

long long N, A[1 << 18], CA[1 << 18];
long long M, B[1 << 18], CB[1 << 18];
long long Q, X[1 << 18], Y[1 << 18], Z[1 << 18];

long long SA[1 << 20], SB[1 << 20];
vector<long long> FX, FY;
vector<long long> M1[1 << 20];

RangeAddMinSegmentTree<long long> G;

int main() {
	scanf("%lld%lld%lld", &N, &M, &Q);
	for (int i = 1; i <= N; i++) scanf("%lld%lld", &A[i], &CA[i]);
	for (int i = 1; i <= M; i++) scanf("%lld%lld", &B[i], &CB[i]);
	for (int i = 1; i <= Q; i++) scanf("%lld%lld%lld", &X[i], &Y[i], &Z[i]);

	// 
	for (int i = 1; i <= N; i++) FX.push_back(A[i] - 1);
	for (int i = 1; i <= M; i++) FY.push_back(B[i] - 1);
	for (int i = 1; i <= Q; i++) { FX.push_back(X[i]); FY.push_back(Y[i]); }
	sort(FX.begin(), FX.end()); FX.erase(unique(FX.begin(), FX.end()), FX.end());
	sort(FY.begin(), FY.end()); FY.erase(unique(FY.begin(), FY.end()), FY.end());
	for (int i = 1; i <= N; i++) A[i] = lower_bound(FX.begin(), FX.end(), A[i] - 1) - FX.begin();
	for (int i = 1; i <= M; i++) B[i] = lower_bound(FY.begin(), FY.end(), B[i] - 1) - FY.begin();
	for (int i = 1; i <= Q; i++) X[i] = lower_bound(FX.begin(), FX.end(), X[i]) - FX.begin();
	for (int i = 1; i <= Q; i++) Y[i] = lower_bound(FY.begin(), FY.end(), Y[i]) - FY.begin();
	
	// 
	for (int i = 0; i < FX.size(); i++) SA[i] = (1LL << 60);
	for (int i = 0; i < FY.size(); i++) SB[i] = (1LL << 60);
	for (int i = 1; i <= N; i++) SA[A[i]] = min(SA[A[i]], CA[i]);
	for (int i = 1; i <= M; i++) SB[B[i]] = min(SB[B[i]], CB[i]);
	for (int i = (int)FX.size() - 2; i >= 0; i--) SA[i] = min(SA[i], SA[i + 1]);
	for (int i = (int)FY.size() - 2; i >= 0; i--) SB[i] = min(SB[i], SB[i + 1]);
	for (int i = 1; i <= Q; i++) M1[Y[i]].push_back(i);

	// 
	G = RangeAddMinSegmentTree<long long>(FX.size() + 2);
	for (int i = 0; i < FX.size(); i++) G.add(i, SA[i]);

	long long ans = -(1LL << 60);
	for (int i = 0; i < FY.size(); i++) {
		for (int j : M1[i]) G.add(X[j], FX.size() + 1, -Z[j]);
		long long H = G.query(0, FX.size());
		ans = max(ans, -H - SB[i]);
	}

	printf("%lld\n", ans);
	return 0;
}