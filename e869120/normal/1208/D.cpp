#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<long long> bit;
	int size_;

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
			pos -= (pos&-pos);
		}
		return s;
	}
};

long long N, A[1 << 18], B[1 << 18];
BIT Z;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	Z.init(N + 1);
	for (int i = 1; i <= N; i++) Z.add(i, i);
	for (int i = N; i >= 1; i--) {
		long long cl = 0, cr = N + 1, cm = 0, minx = (1 << 30);
		for (int j = 0; j < 20; j++) {
			cm = (cl + cr) / 2;
			long long V = Z.sum(cm);
			if (V > A[i]) { minx = min(minx, cm); cr = cm; }
			else { cl = cm; }
		}
		B[i] = minx;
		Z.add(minx, -minx);
	}
	for (int i = 1; i <= N; i++) { 
		if (i >= 2) printf(" ");
		printf("%lld", B[i]);
	}
	printf("\n");
	return 0;
}