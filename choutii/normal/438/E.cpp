#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int M = 23, P = 998244353, G = 3;
const int MaxN = (1 << 20) + 10;
int N = 1 << 19;

inline int add(int a, int b) {
    return (a + b) % P;
}

inline int sub(int a, int b) {
    return (a - b + P) % P;
}

inline int mul(int a, int b) {
    return (LL)a * (LL)b % P;
}

inline int exp(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
    }
    return ans;
}

inline int inv(int x) {
    return exp(x, P - 2);
}

int eps[MaxN], ieps[MaxN], temp[5][MaxN];

inline void init() {
    int g = exp(G, (P - 1) / N), ig = inv(g);
    eps[0] = ieps[0] = 1;
    for (int i = 1; i < N; i++) eps[i] = mul(eps[i - 1], ig), ieps[i] = mul(ieps[i - 1], g);
}

inline void trans(int n, int x[], int w[]) {
    for (int i = 0, j = 0; i != n; i++) {
        if (i < j) std::swap(x[i], x[j]);
        for (int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
    for (int i = 2; i <= n; i <<= 1) {
        int l = i >> 1, d = N / i;
        for (int j = 0; j != n; j += i)
            for (int k = 0; k != l; k++) {
                int t = mul(x[j + k + l], w[d * k]);
                x[j + k + l] = sub(x[j + k], t);
                x[j + k] = add(x[j + k], t);
            }
    }
}

inline void dft(int n, int x[]) {
    trans(n, x, eps);
}

inline void idft(int n, int x[]) {
    trans(n, x, ieps);
    for (int i = 0, in = inv(n); i < n; i++) x[i] = mul(x[i], in);
}

inline void inv(int n, int x[], int y[]) {
    int *t = temp[0];
    std::fill(y, y + (n << 1), 0);
    y[0] = inv(x[0]);
    for (int i = 4, j = 2; j <= n; j = i, i <<= 1) {
        std::copy(x, x + j, t);
        std::fill(t + j, t + i, 0);
        dft(i, t);
        dft(i, y);
        for (int k = 0; k < i; k++) y[k] = mul(y[k], sub(2, mul(t[k], y[k])));
		idft(i, y);
        std::fill(y + j, y + i, 0);
    }
}

inline void drv(int n, int x[], int y[]) {
    for (int i = 1; i < n; i++) y[i - 1] = mul(i, x[i]);
    y[n - 1] = 0;
}

inline void itg(int n, int x[], int y[]) {
    for (int i = n - 1; i; i--) y[i] = mul(x[i - 1], inv(i));
    y[0] = 0;
}

inline void ln(int n, int x[], int y[]) {
    int *t = temp[1];
    inv(n, x, y);
    drv(n, x, t);
    std::fill(y + n, y + n + n, 0);
    std::fill(t + n, t + n + n, 0);
    dft(n << 1, y), dft(n << 1, t);
    for (int i = 0; i < (n << 1); i++) y[i] = mul(y[i], t[i]);
    idft(n << 1, y);
    std::fill(y + n, y + n + n, 0);
    itg(n, y, y);
}

inline void exp(int n, int x[], int y[]) {
    int *t = temp[2];
    std::fill(y, y + (n << 1), 0);
    y[0] = 1;
    for (int i = 4, j = 2; j <= n; j = i, i <<= 1) {
        ln(j, y, t);
        t[0] = sub(x[0] + 1, t[0]);
        for (int k = 1; k < j; k++) t[k] = sub(x[k], t[k]);
        std::fill(t + j, t + i, 0);
        dft(i, y), dft(i, t);
        for (int k = 0; k < i; k++) y[k] = mul(y[k], t[k]);
        idft(i, y);
        std::fill(y + j, y + i, 0);
    }
}

const int I2 = inv(2);

inline void sqrt(int n, int x[], int y[]) {
    int *t = temp[3];
    std::fill(y, y + (n << 1), 0);
    y[0] = 1;
    for (int i = 4, j = 2; j <= n; j = i, i <<= 1) {
        inv(j, y, t);
        dft(j, y);
        for (int k = 0; k < j; k++) y[k] = mul(y[k], y[k]);
        idft(j, y);
        for (int k = 0; k < j; k++) y[k] = add(y[k], x[k]);
        dft(i, y), dft(i, t);
        for (int k = 0; k < i; k++) y[k] = mul(y[k], t[k]);
        idft(i, y);
        for (int k = 0; k < j; k++) y[k] = mul(y[k], I2);
        std::fill(y + j, y + i, 0);
    }
}

int n, m, x[MaxN], y[MaxN], z[MaxN];
int main() {
	int i;
	init();
	x[0] = 1;
	n = read(); m = read();
	int M = 0;
	for(i = 0; i < n; i++) {
		int y = read(); if(y <= m) x[y] = sub(x[y], 4), cmax(M, y);
	}
	int N = 1;
	for(N = 1; N <= M + m; N <<= 1); 
	sqrt(N, x, y);
	y[0] = add(y[0], 1);
	inv(N, y, z);
	for(i = 0; i < N; i++) 
		z[i] = mul(z[i], 2);
	for(i = 1; i <= m; i++) printf("%d\n", z[i]);
	return 0;
}