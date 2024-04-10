#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

//=======================================================================
//===                                                                 ===
//===                                                                 ===
//===                       LIBRARY OF SEGMENTTREE                    ===
//===                                                                 ===
//===                                                                 ===
//=======================================================================
int seg[1048588], lazy[1048588], inf = 2147483647;
void push(int k) {
	if (lazy[k] != -inf) {
		seg[k * 2] = lazy[k * 2] = lazy[k];
		seg[k * 2 + 1] = lazy[k * 2 + 1] = lazy[k];
		lazy[k] = -inf;
	}
}
void update(int a, int b, int x, int k, int l, int r) {
	if (a <= l && r <= b) {
		seg[k] = lazy[k] = x;
		return;
	}
	if (r <= a || b <= l) return;
	push(k);
	update(a, b, x, k * 2, l, (l + r) >> 1);
	update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
	seg[k] = min(seg[k * 2], seg[k * 2 + 1]);
}
int query(int a, int b, int k, int l, int r) {
	if (a <= l && r <= b) return seg[k];
	if (r <= a || b <= l) return inf;
	push(k);
	int lc = query(a, b, k * 2, l, (l + r) >> 1);
	int rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
	return min(lc, rc);
}

//=======================================================================
//===                                                                 ===
//===                                                                 ===
//===                 LIBRARY OF RANGEMINIMUMQUERY                    ===
//===                                                                 ===
//===                                                                 ===
//=======================================================================
#include <limits>
#include <algorithm>

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

//=======================================================================
//===                                                                 ===
//===                                                                 ===
//===                                  MAIN                           ===
//===                                                                 ===
//===                                                                 ===
//=======================================================================
#include<vector>
int n, k, q, a[100005], v1[100005], v2[100005], v3[100005], v4[100005]; vector<int>E;

int main() {
	fill(seg, seg + 1048588, inf);
	fill(lazy, lazy + 1048588, inf);

	//====================PHASE 1: CIN===========================-

	cin >> n >> k; for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	cin >> q;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &v1[i], &v2[i], &v3[i]); v2[i]--; v3[i]--; if (v1[i] == 1)scanf("%d", &v4[i]);
		E.push_back(v2[i] - 1); E.push_back(v2[i]); E.push_back(v3[i]); E.push_back(v3[i] + 1);
	}
	E.push_back(-1); E.push_back(0); E.push_back(n*k - 1); E.push_back(n*k);
	sort(E.begin(), E.end()); E.erase(unique(E.begin(), E.end()), E.end());
	
	//===================PHASE 2:QUERY SAKIYOMI==================
	RMQ<int> X(3 * n);
	for (int i = 0; i < 3 * n; i++)X.update(i, a[i%n]);

	for (int i = 0; i < E.size() - 1; i++) {
		if (E[i + 1] - E[i] >= n) { update(i, i + 1, X.query(0, 3 * n - 1), 1, 0, 524288); }
		else {
			int P1 = E[i] % n, P2 = E[i + 1] % n; if (P1 > P2)P2 += n;
			update(i, i + 1, X.query(P1, P2), 1, 0, 524288);
		}
	}

	for (int i = 0; i < q; i++) {
		int pos1 = lower_bound(E.begin(), E.end(), v2[i]) - E.begin();
		int pos2 = lower_bound(E.begin(), E.end(), v3[i] + 1) - E.begin();
		if (v1[i] == 1) {
			update(pos1, pos2, v4[i], 1, 0, 524288);
		}
		if (v1[i] == 2) {
			printf("%d\n", query(pos1, pos2, 1, 0, 524288));
		}
	}
	return 0;
}