#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
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
long long n, r[100004], h[100004], s[100004], dp[100004]; vector<long long>B;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> r[i] >> h[i]; s[i] = r[i] * r[i] * h[i]; B.push_back(s[i]); }
	sort(B.begin(), B.end());
	for (int i = 0; i < n; i++) { s[i] = lower_bound(B.begin(), B.end(), s[i]) - B.begin(); s[i]++; }
	RMQ<long long>X(n + 2); X.update(0, 0);
	for (int i = 0; i < n; i++) {
		dp[i] = -1LL * X.query(0, s[i]) + (r[i] * r[i] * h[i]);
		X.update(s[i], -1LL * dp[i]);
	}
	long long maxn = 0; for (int i = 0; i <= n; i++) { maxn = max(maxn, dp[i]); }
	printf("%.12Lf\n", 3.14159265358979323846264L*maxn);
	return 0;
}