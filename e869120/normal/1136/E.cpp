#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<long long> bit; int size_ = 0;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}
	void add(int pos, long long x) {
		pos++;
		while (pos <= size_) {
			bit[pos] += x;
			pos += (pos&-pos);
		}
	}
	long long sum(int pos) {
		long long s = 0; pos++;
		while (pos >= 1) {
			s += bit[pos];
			pos -= (pos & -pos);
		}
		return s;
	}
};

class RangeAdd {
public:
	BIT a, b;

	void init(int sz) {
		a.init(sz + 2);
		b.init(sz + 2);
	}
	void add(int l, int r, long long x) {
		// [l, r]  add
		a.add(l, x); b.add(l, -1LL * (l - 1) * x);
		a.add(r + 1, -x); b.add(r + 1, 1LL * r * x);
	}
	long long sum(int pos) {
		long long V1 = a.sum(pos);
		long long V2 = b.sum(pos);
		return V1 * pos + V2;
	}
};

long long N, Q, A[1 << 19], K[1 << 19];
BIT Z; RangeAdd X;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N - 1; i++) scanf("%lld", &K[i]);
	Z.init(N + 2); X.init(N + 2);
	for (int i = 1; i <= N - 1; i++) Z.add(i, (A[i + 1] - A[i]) - K[i]);
	for (int i = 1; i <= N; i++) {
		//cout << "# "; for (int j = 1; j <= N; j++) cout << X.sum(j) << " "; cout << endl;
		X.add(i, N + 1, A[i] - A[i - 1]);
	}

	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		char c; int d1, d2;
		cin >> c; scanf("%d%d", &d1, &d2);
		if (c == '+') {
			X.add(d1, N + 1, d2);
			if (d1 >= 2) Z.add(d1 - 1, d2);

			long long E = d2;
			while (E > 0) {
				int cl = d1, cr = N + 1, cm, maxn = (1 << 30);
				for (int j = 0; j < 22; j++) {
					cm = (cl + cr) >> 1;
					if (Z.sum(cm) == Z.sum(d1 - 1)) { cl = cm; }
					else { cr = cm; maxn = min(maxn, cm); }
				}
				if (maxn == (1 << 30)) break;
				long long F = Z.sum(maxn) - Z.sum(maxn - 1); F = min(F, E);
				Z.add(maxn, -F); X.add(maxn + 1, N + 1, -F);
				E -= F;
			}
			//cout << "# "; for (int j = 1; j <= N; j++) cout << X.sum(j) << " "; cout << endl;
		}
		if (c == 's') {
			printf("%lld\n", X.sum(d2) - X.sum(d1 - 1));
			//cout << "# "; for (int j = 1; j <= N; j++) cout << X.sum(j) << " "; cout << endl;
		}
	}
	return 0;
}