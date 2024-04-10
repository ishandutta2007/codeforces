#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#pragma warning(disable:4996)

// ------ RMQ Class ------ //
template<typename Type> class RMQ {
private:
	unsigned size_; std::vector<Type> dat;
	inline Type query_(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::max();
		if (a <= l && r <= b) return dat[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc);
	}
public:
	RMQ() : size_(0), dat(std::vector<Type>()) {};
	RMQ(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, std::numeric_limits<Type>::max());
	}
	template<class T>
	RMQ(T begin_, T end_) {
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
			dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
		}
	}
	inline Type query(int l, int r) {
		return query_(l, r, 1, 0, size_);
	}
};
//--------------------------------MAIN-------------------------------------
int n, a[210000], b[210000];

int main() {
	cin >> n; for (int i = 0; i < n; i++) scanf("%d", &a[i]); for (int i = 0; i < n; i++)scanf("%d", &b[i]);
	RMQ<int>P1(n + 3), P2(n + 3); for (int i = 0; i < n; i++) { P1.update(i, -a[i]); P2.update(i, b[i]); }
	long long ret = 0;

	int M1 = 0, M2 = 0;
	for (int i = 0; i < n; i++) {
		//max>min
		while (true) {
			int F1 = P1.query(i, M1), F2 = P2.query(i, M1); F1 *= -1;
			if ((F1 > F2 && i != M1) || M1 == n + 1)break; M1++;
		}
		while (true) {
			int F1 = P1.query(i, M2), F2 = P2.query(i, M2); F1 *= -1;
			if ((F1 >= F2 && i != M2) || M2 == n + 1)break; M2++;
		}
		ret += (M1 - M2);
	}
	cout << ret << endl;
	return 0;
}