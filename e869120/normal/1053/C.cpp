#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 1000000007;

class BIT {
public:
	vector<long long>bit; int size_ = 0; long long MD;

	void init(int sz) {
		size_ = sz + 2;
		bit.resize(size_ + 2, 0);
	}

	void add(int pos, long long x) {
		pos++; x %= MD;
		while (pos <= size_) {
			bit[pos] += x; bit[pos] %= MD;
			pos += (pos&-pos);
		}
	}
	
	long long sum(int pos) {
		long long x = 0; pos++;
		while (pos >= 1) {
			x += bit[pos]; x %= MD;
			pos -= (pos&-pos);
		}
		return x % MD;
	}
};

long long N, Q, A[1 << 18], W[1 << 18];
BIT Z1, Z2;

int main() {
	scanf("%lld%lld", &N, &Q); Z1.init(N + 2); Z2.init(N + 2); Z1.MD = (1LL << 60); Z2.MD = mod;
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); A[i] -= i; }
	for (int i = 1; i <= N; i++) scanf("%lld", &W[i]);
	for (int i = 1; i <= N; i++) { Z1.add(i, W[i]); Z2.add(i, A[i] * W[i] % mod); }
	
	for (int i = 1; i <= Q; i++) {
		long long a, b; scanf("%lld%lld", &a, &b);

		//cout << "Current State:" << endl;
		//for (int i = 0; i <= N; i++) cout << Z1.sum(i) << " "; cout << endl;
		//for (int i = 0; i <= N; i++) cout << Z2.sum(i) << " "; cout << endl;
		if (a < 0) {
			a *= -1;
			Z1.add(a, 1LL * b - W[a]);
			Z2.add(a, 1LL * A[a] * (b - W[a]));
			W[a] = b;
		}
		else {
			int l = a, r = b;
			int cl = a, cr = b + 1, mid, minx = b;
			for (int t = 1; t <= 30; t++) {
				mid = (cl + cr) / 2;
				long long V1 = (Z1.sum(mid) - Z1.sum(a - 1));
				long long V2 = (Z1.sum(b) - Z1.sum(mid));
				if (V1 < V2) { cl = mid; }
				else { cr = mid; minx = min(minx, mid); }
			}
			mid = minx;

			long long wl = (Z1.sum(mid) - Z1.sum(l - 1)) % mod, wr = (Z1.sum(r) - Z1.sum(mid)) % mod;
			long long xl = (Z2.sum(mid) - Z2.sum(l - 1)) % mod, xr = (Z2.sum(r) - Z2.sum(mid)) % mod;
			long long al = 1LL * A[mid] * wl - xl, ar = xr - 1LL * A[mid] * wr;
			al += mod * mod; al %= mod;
			ar += mod * mod; ar %= mod;

			printf("%lld\n", (al + ar) % mod);
		}
	}
	return 0;
}