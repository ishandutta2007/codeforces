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

int n, l[400009], r[400009], p[400009]; vector<int>v;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]); r[i]++;
		v.push_back(l[i]); v.push_back(r[i]);
	}
	sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 1; i <= n; i++) {
		l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
		r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
		p[l[i]]++; p[r[i]]--;
	}
	for (int i = 1; i <= v.size(); i++) p[i] += p[i - 1];
	RangeMin<int>X(v.size() + 2);
	for (int i = 0; i <= v.size(); i++) X.update(i, p[i]);

	for (int i = 1; i <= n; i++) {
		if (X.query(l[i], r[i]) != 1) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}