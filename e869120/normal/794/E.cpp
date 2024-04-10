#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
#pragma warning (disable: 4996)

template<typename Type> class RangeMin {
private:
	int size_;
	std::vector<Type> dat;
public:
	RangeMin() : size_(0), dat(std::vector<Type>()) {};
	RangeMin(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::max() / 2);
	}
	template<class T>
	RangeMin(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max() / 2);
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
		Type ret = std::numeric_limits<Type>::max() / 2;
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};

int N, A[1 << 19], maxn;
RangeMin<int> X1, X2;

int main() {
	scanf("%d", &N);
	X1 = RangeMin<int>(N + 2);
	X2 = RangeMin<int>(N + 2);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); maxn = max(maxn, A[i]); }
	for (int i = 1; i <= N - 1; i++) X1.update(i, -max(A[i], A[i + 1]));
	for (int i = 2; i <= N - 1; i++) X2.update(i, -max(min(A[i - 1], A[i]), min(A[i], A[i + 1])));

	for (int i = 0; i < N; i++) {
		if (i >= 1) cout << " ";
		int ans = 0;

		if ((N - i) % 2 == 0) {
			int cl = (N - i) / 2, cr = (N + i) / 2;
			ans = -X1.query(cl, cr + 1);
		}
		else {
			if (i == N - 1) { ans = maxn; }
			else {
				int cl = (N - i + 1) / 2, cr = (N + i + 1) / 2;
				ans = -X2.query(cl, cr + 1);
			}
		}
		printf("%d", ans);
	}
	printf("\n");
	return 0;
}