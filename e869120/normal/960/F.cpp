#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

template<typename Type> class RangeMin {
private:
	int size_;
	std::vector<Type> dat;
public:
	RangeMin() : size_(0), dat(std::vector<Type>()) {};
	RangeMin(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::max());
	}
	template<class T>
	RangeMin(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max());
		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (int i = size_ - 1; i > 0; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	inline unsigned size() { return size_; }
	inline void update(int i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::min(dat[i << 1], dat[i << 1 | 1]);
		}
	}
	inline Type query(int l, int r) {
		Type ret = std::numeric_limits<Type>::max();
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};

int N, M, A[100009], B[100009], W[100009], AX[100009], BX[100009];
vector<int>X[100009]; RangeMin<int>Z[100009];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> W[i];
		X[A[i]].push_back(W[i]);
		X[B[i]].push_back(W[i]);
	}
	for (int i = 1; i <= N; i++) sort(X[i].begin(), X[i].end());
	for (int i = 1; i <= M; i++) {
		AX[i] = lower_bound(X[A[i]].begin(), X[A[i]].end(), W[i]) - X[A[i]].begin();
		BX[i] = lower_bound(X[B[i]].begin(), X[B[i]].end(), W[i]) - X[B[i]].begin();
	}
	for (int i = 1; i <= N; i++) {
		Z[i] = RangeMin<int>(X[i].size() + 2);
		for (int j = 0; j < X[i].size() + 2; j++) Z[i].update(j, 0);
	}

	int maxn = 0;
	for (int i = 1; i <= M; i++) {
		int T = -Z[A[i]].query(0, AX[i]) + 1; if (AX[i] == 0) T = 1;
		maxn = max(maxn, T);
		Z[B[i]].update(BX[i], -T);
	}
	cout << maxn << endl;
	return 0;
}