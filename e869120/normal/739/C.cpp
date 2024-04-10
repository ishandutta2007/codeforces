#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int>dat; int size_ = 1;

	void init(int sz) {
		size_ = sz + 2;
		dat.resize(size_ + 2, 0);
	}
	void add(int pos, int x) {
		pos++;
		while (pos <= size_) {
			dat[pos] += x;
			pos += (pos&-pos);
		}
	}
	int sum(int pos) {
		int s = 0; pos++;
		while (pos >= 1) {
			s += dat[pos]; pos -= (pos&-pos);
		}
		return s;
	}
	int left_over(int pos) {
		int L = 0, R = pos, M, maxn = -1, T = sum(pos);
		for (int i = 0; i < 22; i++) {
			M = (L + R) / 2;
			int V = T - sum(M);
			if (V != (pos - M)) { maxn = max(maxn, M); L = M; }
			else { R = M; }
		}
		return maxn + 1;
	}
	int right_over(int pos) {
		int L = pos, R = size_, M, minx = size_, T = sum(pos - 1);
		for (int i = 0; i < 22; i++) {
			M = (L + R) / 2;
			int V = sum(M) - sum(pos - 1);
			if (V != (M - (pos - 1))) { minx = min(minx, M); R = M; }
			else { L = M; }
		}
		return minx;
	}
};

template<typename Type> class RangeMin {
private:
	int size_;
	std::vector<Type> dat;
public:
	RangeMin() : size_(0), dat(std::vector<Type>()) {};
	RangeMin(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat.resize(size_ << 1, -1000000007);
	}
	template<class T>
	RangeMin(T begin_, T end_) {
		int n = end_ - begin_;
		for (size_ = 1; size_ < n; size_ <<= 1); dat.resize(size_ << 1, -1000000007);
		for (int i = 0; i < n; i++) dat[i + size_] = *(begin_ + i);
		for (int i = size_ - 1; i > 0; i--) dat[i] = std::max(dat[i << 1], dat[(i << 1) + 1]);
	}
	inline unsigned size() { return size_; }
	inline void update(int i, Type x) {
		i += size_; dat[i] = x;
		while (i > 1) {
			i >>= 1;
			dat[i] = std::max(dat[i << 1], dat[i << 1 | 1]);
		}
	}
	inline Type query(int l, int r) {
		Type ret = -1000000007;
		l += size_; r += size_;
		while (l != r) {
			if (l & 1) ret = std::max(ret, dat[l++]); l >>= 1;
			if (r & 1) ret = std::max(ret, dat[--r]); r >>= 1;
		}
		return ret;
	}
};

long long N, Q, A[300009], D[300009], ty[300009];
RangeMin<int>Z; BIT R1, R2;

void lose(int pos) {
	if (ty[pos] == 1) {
		int UR = R1.right_over(pos); UR--;
		int UL = R1.left_over(pos); UL++;

		if (UL != pos) Z.update(pos - 1, Z.query(pos - 1, pos) + (pos - UL));
		Z.update(UR, Z.query(UR, UR + 1) - (pos - UL + 1));

		R1.add(pos, -1);
		ty[pos] = 0;
	}
	if (ty[pos] == 2) {
		int UR = R2.right_over(pos); UR--;
		int UL = R2.left_over(pos); UL++;

		if (UR != pos) Z.update(pos, Z.query(pos, pos + 1) + (UR - pos));
		Z.update(UL - 1, Z.query(UL - 1, UL) - (UR - pos + 1));

		R2.add(pos, -1);
		ty[pos] = 0;
	}
}

void add(int pos, int team) {
	if (team == 1) {
		R1.add(pos, 1);
		int UR = R1.right_over(pos); UR--;
		int UL = R1.left_over(pos); UL++;

		if (UL != pos) Z.update(pos - 1, Z.query(pos - 1, pos) - (pos - UL));
		Z.update(UR, Z.query(UR, UR + 1) + (pos - UL + 1));
	}
	if (team == 2) {
		R2.add(pos, 1);
		int UR = R2.right_over(pos); UR--;
		int UL = R2.left_over(pos); UL++;

		if (UR != pos) Z.update(pos, Z.query(pos, pos + 1) - (UR - pos));
		Z.update(UL - 1, Z.query(UL - 1, UL) + (UR - pos + 1));
	}
}

int main() {
	scanf("%lld", &N); Z = RangeMin<int>(N + 2); R1.init(N + 2); R2.init(N + 2);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N - 1; i++) D[i] = A[i + 1] - A[i];
	for (int i = 1; i <= N - 1; i++) { if (D[i] > 0) ty[i] = 1; if (D[i] == 0) ty[i] = 0; if (D[i] < 0) ty[i] = 2; }
	for (int i = 0; i <= N; i++) Z.update(i, 0);
	for (int i = 1; i <= N - 1; i++) add(i, ty[i]);

	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		long long l, r, x;
		scanf("%lld%lld%lld", &l, &r, &x);
		if (l >= 2) { D[l - 1] += x; lose(l - 1); if (D[l - 1] > 0) ty[l - 1] = 1; if (D[l - 1] == 0) ty[l - 1] = 0; if (D[l - 1] < 0) ty[l - 1] = 2; add(l - 1, ty[l - 1]); }
		if (r <= N - 1) { D[r] -= x; lose(r); if (D[r] > 0) ty[r] = 1; if (D[r] == 0) ty[r] = 0; if (D[r] < 0) ty[r] = 2; add(r, ty[r]); }
		printf("%d\n", 1 + Z.query(0, N + 2));
	}
	return 0;
}