#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#pragma warning(disable: 4996)

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
int n, q, a[500009], p[500009], ans[500009]; vector<int>Z[500009]; map<int, int>M; vector<pair<int, int>>V[500009];
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); p[M[a[i]]] = (i - M[a[i]]); if (M[a[i]] >= 1)Z[i].push_back(M[a[i]]);
		M[a[i]] = i;
	}
	for (int i = 1; i <= q; i++) { int p1, p2; scanf("%d%d", &p1, &p2); V[p2].push_back(make_pair(p1, i)); }
	RMQ<int>X(n + 2);
	for (int i = 1; i <= n; i++) {
		for (int j : Z[i])X.update(j, p[j]);
		for (int j = 0; j < V[i].size(); j++) {
			ans[V[i][j].second] = X.query(V[i][j].first, i + 1);
			if (ans[V[i][j].second] >= (1 << 30))ans[V[i][j].second] = -1;
		}
	}
	for (int i = 1; i <= q; i++)printf("%d\n", ans[i]);
	return 0;
}