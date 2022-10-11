#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
template<typename Type>
class RMQ {
private:
	int size_; std::vector<Type> dat;
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
long long d, n, m, x[200009], p[200009], ret = 0; vector<pair<long long, long long>>G, H;
int main() {
	cin >> d >> n >> m;
	for (int i = 1; i <= m; i++) { cin >> x[i] >> p[i]; H.push_back(make_pair(x[i], p[i])); }
	sort(H.begin(), H.end()); p[0] = 100000000;
	for (int i = 1; i <= m; i++) { x[i] = H[i - 1].first; p[i] = H[i - 1].second; }x[m + 1] = d;

	RMQ<long long>X(m + 4); p[m + 1] = 100000000; p[m + 2] = 100000000; p[m + 3] = 100000000;
	for (int i = 0; i <= m + 3; i++)X.update(i, p[i]);

	vector<long long>I;
	for (int i = 0; i <= m + 1; i++) {
		I.push_back(x[i]);
		for (int j = -10; j <= 10; j++) {
			I.push_back(min(d, max(0LL, x[i] + 1LL * j*n)));
		}
	}
	sort(I.begin(), I.end());
	for (int i = 0; i <= m; i++) {
		if (x[i + 1] - x[i] > n) { cout << "-1" << endl; return 0; }
	}
	for (int i = 0; i < I.size() - 1; i++) {
		int pos1 = lower_bound(x, x + m + 2, I[i + 1] - n) - x;
		int pos2 = upper_bound(x, x + m + 2, I[i + 1] - 1) - x;
		long long V = (max(0LL, I[i + 1] - n) - max(0LL, I[i] - n));
		ret += X.query(pos1, pos2) * V;
	}
	cout << ret << endl;
	return 0;
}