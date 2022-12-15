#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int p = 998244353, maxN = 262144, maxK = 19, g = 3, ig = 332748118, inv2 = (p + 1) / 2;
int calc(int n) {
    int x = 1;
    while (x < n) x <<= 1;
    return x;
}
struct Z {
    int x;
    Z(int x0 = 0) : x(x0) {}
};
int inline check(int x) { return x >= p ? x - p : x; }
Z operator+(const Z a, const Z b) { return check(a.x + b.x); }
Z operator-(const Z a, const Z b) { return check(a.x - b.x + p); }
Z operator*(const Z a, const Z b) { return 1LL * a.x * b.x % p; }
Z operator-(const Z a) { return check(p - a.x); }
Z &operator+=(Z &a, const Z b) { return a = a + b; }
Z &operator-=(Z &a, const Z b) { return a = a - b; }
Z &operator*=(Z &a, const Z b) { return a = a * b; }
vector<Z> W[maxK], iW[maxK];
Z fac[maxN], ifac[maxN], inv[maxN];
Z qpow(Z a, int k) {
    Z ans = 1;
    while (k) {
        if (k & 1)
            ans *= a;
        a *= a;
        k >>= 1;
    }
    return ans;
}
void init() {
    for (int k = 0; k < maxK; k++) {
        Z w = qpow(g, (p - 1) >> k), iw = qpow(ig, (p - 1) >> k);
        W[k].resize(1 << k);
        iW[k].resize(1 << k);
        W[k][0] = iW[k][0] = 1;
        for (int i = 1; i < (1 << k); i++) W[k][i] = W[k][i - 1] * w, iW[k][i] = iW[k][i - 1] * iw;
    }
    fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++)
        fac[i] = fac[i - 1] * i, inv[i] = (p - p / i) * inv[p % i], ifac[i] = ifac[i - 1] * inv[i];
}
int R[maxN];

void NTT(Z d[], bool flg, int n0) {
    int x = 1, len = 0;
    while (x < n0) x <<= 1, len++;
    for (int i = 0; i < x; i++) {
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (len - 1));
        if (i < R[i])
            swap(d[i], d[R[i]]);
    }
    for (int i = 1, k = 1; i < x; i <<= 1, k++)
        for (int j = 0; j < x; j += (i << 1)) {
            Z *a0 = d + j, *a1 = d + j + i, *w = (flg ? iW[k].data() : W[k].data()), tmp;
            for (int k = 0; k < i; k++, a0++, a1++, w++) {
                tmp = (*a1) * (*w), *a1 = *a0 - tmp, *a0 += tmp;
            }
        }
    if (flg) {
        Z invx = qpow(x, p - 2);
        for (int i = 0; i < x; i++) d[i] = d[i] * invx;
    }
}

struct Poly : vector<Z> {
    using vector<Z>::vector;
    void DFT(int n0) {
        if (size() < n0)
            resize(n0);
        NTT(data(), 0, n0);
    }
    void iDFT(int n0) {
        if (size() < n0)
            resize(n0);
        NTT(data(), 1, n0);
    }
    Poly slice(int n) { return Poly(data(), data() + n); }
	void reverse() {
		std::reverse(begin(), end());
	}
};

void outp(Poly d, int n0) {
	if(d.size() < n0) d.resize(n0);
	for(int i = 0; i < n0; i++) printf("%d ", d[i].x); printf("\n");
}
Poly Conv(Poly d1, Poly d2, int n0) {
    if (n0 <= 32) {
        d1.resize(n0);
        d2.resize(n0);
        for (int i = n0 - 1; i >= 0; i--) {
            Z tmp = 0;
            for (int j = 0; j <= i; j++) tmp += d1[i - j] * d2[j];
            d1[i] = tmp;
        }
        return d1;
    }
    int x = 1;
    while (x < n0) x <<= 1;
    d1.DFT(x);
    d2.DFT(x);
    for (int i = 0; i < x; i++) d1[i] *= d2[i];
    d1.iDFT(x);
    d1.resize(n0);
    return d1;
}

int n; ll m;
Poly F, G;

int main() {
	init();
	scanf("%d%lld", &n, &m); n++; F.resize(n); G.resize(n);
	for(int i = 0; i < n; i++) scanf("%d", &F[i].x), F[i] *= fac[i];
	F.reverse();
	for(int i = 0; i < n; i++) G[i] = ifac[i];
	F = Conv(F, G, n << 1); F.resize(n);
	F.reverse();
	for(int i = 0; i < n; i++) F[i] *= qpow(inv[i + 1], m % (p - 1)), F[i] = i & 1 ? -F[i] : F[i];
	F.reverse();
	F = Conv(F, G, n << 1); F.resize(n);
	F.reverse();
	for(int i = 0; i < n; i++) F[i] *= ifac[i], F[i] = i & 1 ? -F[i] : F[i], printf("%d ", F[i].x);
}