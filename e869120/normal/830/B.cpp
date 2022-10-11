#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<climits>
using namespace std;

// ------ RMQ Class ------ //
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
	inline void update(unsigned i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::min(dat[i << 1], dat[i << 1 | 1]);
		}
	}
	inline Type query(unsigned l, unsigned r) {
		Type ret = std::numeric_limits<Type>::max();
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::min(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::min(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};
long long bit[200009];
void add(int pos, long long x) { while (pos <= 200000) { bit[pos] += x; pos += (pos&-pos); } }
long long sum(int pos) { long long s = 0; while (pos >= 1) { s += bit[pos]; pos -= (pos&-pos); }return s; }

long long n, a[100009]; vector<long long>E;
int main() {
	cin >> n; RMQ<long long>X(2 * n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; X.update(i, a[i]); X.update(i + n, a[i]);
		E.push_back(a[i]);
	}
	for (int i = 1; i <= 2 * n; i++)add(i, 1);
	sort(E.begin(), E.end());
	long long pos = 1, cnt = 0;
	for (int i = 0; i < n; i++) {
		long long L = pos, R = 2 * n + 1, M;
		while (true) {
			M = (L + R) / 2;
			int p1 = X.query(pos, M), p2 = X.query(pos, M + 1);
			if (pos == M)p1 = 2147483647;
			if (p1 > E[i] && p2 <= E[i]) {
				cnt += sum(M) - sum(pos - 1);
				pos = M%n; if (pos == 0)pos = n;
				X.update(pos, 2147483647);
				X.update(pos + n, 2147483647);
				add(pos, -1);
				add(pos + n, -1);
				pos++; if (pos > n)pos -= n;
				break;
			}
			if (p1 <= E[i])R = M; else L = M;
		}
	}
	cout << cnt << endl;
	return 0;
}