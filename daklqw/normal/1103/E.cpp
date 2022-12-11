#include <bits/stdc++.h>

const int MAXN = 100000;
typedef unsigned long long LL;
const LL inv5 = 0x5d4e8fb00bcbe61d;
const LL mask = (1ll << 58) - 1;
const int MA = 1e5, DI = 5;
int n;
struct Comp {
	// (mod x^4 - x^3 + x^2 - x + 1)
	// x^4 = x^3 - x^2 + x - 1
	// x^5 = x^4 - x^3 + x^2 - x
	//     = -1
	// x^6 = -x
	LL a0, a1, a2, a3;
	Comp() { a0 = a1 = a2 = a3 = 0; }
	Comp(LL $, LL E, LL A, LL K) {
		a0 = $, a1 = E, a2 = A, a3 = K;
	}
	friend Comp operator + (Comp x, Comp y) {
		Comp r;
		r.a0 = x.a0 + y.a0;
		r.a1 = x.a1 + y.a1;
		r.a2 = x.a2 + y.a2;
		r.a3 = x.a3 + y.a3;
		return r;
	}
	friend Comp operator * (Comp x, Comp y) {
		Comp r;
		LL t = x.a1 * y.a3 + x.a2 * y.a2 + x.a3 * y.a1;
		r.a0 = x.a0 * y.a0 - x.a2 * y.a3 - x.a3 * y.a2 - t;
		r.a1 = x.a0 * y.a1 + x.a1 * y.a0 - x.a3 * y.a3 + t;
		r.a2 = x.a0 * y.a2 + x.a1 * y.a1 + x.a2 * y.a0 - t;
		r.a3 = x.a0 * y.a3 + x.a1 * y.a2 + x.a2 * y.a1 + x.a3 * y.a0 + t;
		return r;
	}
} A[MA], W[10];

Comp pow(Comp a, int b) {
	Comp r(1, 0, 0, 0);
	for (; b; b >>= 1, a = a * a) if (b & 1) r = r * a;
	return r;
}
void _FFT(Comp * A) {
	static Comp tmp[10];
	for (int i = 0; i != 10; ++i) tmp[i] = Comp();
	for (int i = 0; i != 10; ++i)
		for (int j = 0, k = 0; j != 10; ++j) {
			tmp[i] = tmp[i] + A[j] * W[k];
			k += i - 10, k += k >> 31 & 10;
		}
	memcpy(A, tmp, 10 * sizeof (Comp));
}
void FFT(int typ) {
	W[0] = Comp(1, 0, 0, 0);
	for (int i = 1; i != 10; ++i)
		W[i] = W[i - 1] * Comp(0, 1, 0, 0);
	if (typ == -1) std::reverse(W + 1, W + 10);
	for (int i = 0, bse = 1; i != DI; ++i, bse *= 10) {
		for (int j = 0; j != MA; ++j) if (j / bse % 10 == 0) {
			static Comp li[10];
			for (int k = 0, t = j; k < 10; ++k, t += bse)
				li[k] = A[t];
			_FFT(li);
			for (int k = 0, t = j; k < 10; ++k, t += bse)
				A[t] = li[k];
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, ++A[t].a0;
	FFT(1);
	for (int i = 0; i != MA; ++i) A[i] = pow(A[i], n);
	FFT(-1);
	for (int i = 0; i < n; ++i)
		std::cout << ((A[i].a0 * inv5) >> DI & mask) << '\n';
	return 0;
}