#include <iostream>
#include <algorithm>
#include <vector>
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
		dat.resize(size_ << 1, std::numeric_limits<Type>::max() / 4);
	}
	template<class T>
	RangeMin(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, std::numeric_limits<Type>::max() / 4);
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
		if (l >= r) return (1 << 29);
		Type ret = std::numeric_limits<Type>::max() / 4;
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};

int N, K, A[1 << 18];
int min0 = (1 << 29), max0 = -(1 << 29), min1 = (1 << 29), max1 = -(1 << 29);
RangeMin<int> L[2], R[2];

int main() {
	scanf("%d%d", &N, &K);
	L[0] = RangeMin<int>(N + 2);
	L[1] = RangeMin<int>(N + 2);
	R[0] = RangeMin<int>(N + 2);
	R[1] = RangeMin<int>(N + 2);

	for (int i = 1; i <= N; i++) {
		char c; cin >> c;
		if (c == '0') A[i] = 0;
		else A[i] = 1;
		if (A[i] == 0) { min0 = min(min0, i); max0 = max(max0, i); L[0].update(i, i); R[0].update(i, -i); }
		if (A[i] == 1) { min1 = min(min1, i); max1 = max(max1, i); L[1].update(i, i); R[1].update(i, -i); }
	}

	if (max0 == -(1 << 29) || max1 == -(1 << 29)) { cout << "tokitsukaze" << endl; }
	else if (max0 - min0 + 1 <= K) { cout << "tokitsukaze" << endl; }
	else if (max1 - min1 + 1 <= K) { cout << "tokitsukaze" << endl; }
	else {
		bool flag = true;

		// 0 
		for (int i = 1; i <= N - K + 1; i++) {
			int cl0 = min(L[0].query(1, i), L[0].query(i + K, N + 1));
			int cr0 = -min(R[0].query(1, i), R[0].query(i + K, N + 1));
			int cl1 = min(L[1].query(1, i), L[1].query(i + K, N + 1));
			int cr1 = -min(R[1].query(1, i), R[1].query(i + K, N + 1));
			
			int el0 = min(cl0, i);
			int er0 = max(cr0, i + (K - 1));
			if (er0 - el0 >= K && cr1 - cl1 >= K) flag = false;

			int el1 = min(cl1, i);
			int er1 = max(cr1, i + (K - 1));
			if (cr0 - cl0 >= K && er1 - el1 >= K) flag = false;
		}
		if (flag == true) cout << "quailty" << endl;
		else cout << "once again" << endl;
	}
	return 0;
}