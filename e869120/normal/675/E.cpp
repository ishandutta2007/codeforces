#include <iostream>
#include <algorithm>
#include <vector>
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

long long n, a[100009], dp[100009];

int main() {
	cin >> n;
	RangeMin<long long>X(n + 2);
	for (int i = 1; i < n; i++) cin >> a[i];

	long long s = 0;
	for (int i = n; i >= 1; i--) {
		if (i == n) dp[i] = 0;
		else {
			long long G = X.query(i + 1, a[i] + 1);
			dp[i] = dp[G % 1000000] + (n - i) - (a[i] - G % 1000000);
		}
		s += dp[i];
		X.update(i, (dp[i] + i) * 1000000 + i);
	}
	cout << s << endl;
	return 0;
}