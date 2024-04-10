#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<functional>
#include<limits>
using namespace std;

template<typename Type> class RMQ {
private:
	std::size_t size_; Type *dat;
	Type query_(std::size_t a, std::size_t b, std::size_t k, std::size_t l, std::size_t r) {
		if (r <= a || b <= l) return RMQ<Type>::inf;
		if (a <= l && r <= b) return dat[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1U, (l + r) >> 1, r);
		return min(lc, rc);
	}
public:
	static const Type inf = std::numeric_limits<Type>::max();
	RMQ() {};
	RMQ(int size__) {
		for (size_ = 1U; size_ < size__; ) size_ <<= 1;
		dat = (Type *)malloc(sizeof(Type) * (size_ << 1));
		for (std::size_t i = 0U; i < (size_ << 1); i++) dat[i] = RMQ<Type>::inf;
	}
	template<class T>
	RMQ(T l, T r) {
		std::size_t n = (r - l);
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, RMQ<Type>::inf);
		dat = (Type *)malloc(sizeof(Type) * (size_ << 1));
		for (std::size_t i = 0U; i < n; i++) dat[i + size_] = *(l + i);
		for (std::size_t i = size_ - 1U; i > 0U; i--) dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	std::size_t size() { return size_; }
	void update(size_t i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1U) i >>= 1, dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
	}
	Type query(size_t l, size_t r) {
		return query_(l, r, 1U, 0U, size_);
	}
};

vector<tuple<int, int, int>>vec; vector<int>p1;
int n, a[100020], b[100020], c[100020];
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> b[i] >> a[i] >> c[i]; p1.push_back(a[i]); p1.push_back(b[i]); }
	sort(p1.begin(), p1.end());
	for (int i = 0; i < n; i++) {
		int pos1 = lower_bound(p1.begin(), p1.end(), a[i]) - p1.begin();
		int pos2 = lower_bound(p1.begin(), p1.end(), b[i]) - p1.begin();
		a[i] = pos1 + 1; b[i] = pos2 + 1;
	}
	for (int i = 0; i < n; i++)vec.push_back(make_tuple(a[i], b[i], c[i]));
	sort(vec.begin(), vec.end());
	long long maxn = 0;
	RMQ<long long> X(2 * n + 3);
	for (int i = vec.size() - 1; i >= 0; i--) {
		int G1 = get<0>(vec[i]), G2 = get<1>(vec[i]), G3 = get<2>(vec[i]);
		long long O = -min(0LL, X.query(0, G1)) + G3;//outer>inner
		X.update(G2, -O); maxn = max(maxn, O);
	}
	cout << maxn << endl;
	return 0;
}