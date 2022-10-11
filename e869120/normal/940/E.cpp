#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
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

long long N, C, A[100009], dp[100009], sum;

int main() {
	cin >> N >> C;
	RangeMin<long long>X(N + 2);
	for (int i = 1; i <= N; i++) { cin >> A[i]; sum += A[i]; X.update(i, A[i]); }

	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		if (i >= C) dp[i] = max(dp[i], dp[i - C] + X.query(i - C + 1, i + 1));
	}
	cout << sum - dp[N] << endl;
	return 0;
}