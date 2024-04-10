#include <iostream>
#include <vector>
#include <set>
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

int N, A[1 << 19], B[1 << 19];
vector<int> E[1 << 19]; RangeMin<int> X;

bool hantei(int cl, int cr) {
	if (B[cl] <= cr) return false;
	if (X.query(cl, cr + 1) != -(cr - cl + 1)) return false;
	return true;
}

int main() {
	scanf("%d", &N); X = RangeMin<int>(N + 2);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]); X.update(i, -A[i]);
		E[A[i]].push_back(i);
	}
	for (int i = 1; i <= N + 1; i++) B[i] = N + 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)E[i].size() - 1; j++) { B[E[i][j]] = min(B[E[i][j]], E[i][j + 1]); }
	}
	for (int i = N; i >= 1; i--) B[i] = min(B[i], B[i + 1]);

	set<int>Set; int cnt = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < E[i].size(); j++) Set.insert(E[i][j]);
		for (int j = 0; j < E[i].size(); j++) {
			auto itr = Set.lower_bound(E[i][j]); int cl = 1, cr = N;
			if (itr != Set.begin()) { itr--; cl = (*itr) + 1; itr++; }
			itr++; if (itr != Set.end()) { cr = (*itr) - 1; }

			for (int k = cl; k <= cr - (i - 1); k++) {
				bool I = hantei(k, k + i - 1);
				if (I == true) cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}