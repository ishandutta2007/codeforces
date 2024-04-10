#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
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

int N, A[200009], id[200009]; long long sum = 0;
RangeMin<int>X;

void dfs(int cl, int cr) {
	if (cr - cl <= 0) return;

	int t = -X.query(cl, cr + 1);
	int u = id[t];

	if ((u - cl) < (cr - u)) {
		for (int i = cl; i < u; i++) {
			if (u < id[t - A[i]] && id[t - A[i]] <= cr) {
				sum++;
			}
		}
	}
	else {
		for (int i = cr; i > u; i--) {
			if (cl <= id[t - A[i]] && id[t - A[i]] < u) {
				sum++;
			}
		}
	}
	dfs(cl, u - 1);
	dfs(u + 1, cr);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); id[A[i]] = i; }
	X = RangeMin<int>(N + 2);
	for (int i = 1; i <= N; i++) X.update(i, -A[i]);

	dfs(1, N);
	printf("%lld\n", sum);
	return 0;
}