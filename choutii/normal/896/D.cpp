#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 

#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

struct comp{ 
	double r, i;
	inline comp() { }	
	inline comp(double a, double b) : r(a), i(b) { }
};

const int N = (1 << 19), MaxN = (N << 1) + 10;
const int K = 32767, L = 15;
int P;

inline comp add(comp a, comp b) { return comp(a.r + b.r, a.i + b.i); }
inline comp sub(comp a, comp b) { return comp(a.r - b.r, a.i - b.i); }
inline comp mul(comp a, comp b) { return comp(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);}
inline comp div(comp a, double b){	return comp(a.r/b, a.i/b); }
inline comp conj(comp x) { return comp(x.r, -x.i); }

inline int add(int x, int y) { return x + (LL) y >= P ? x + (LL) y - P : x + y; }
inline int sub(int x, int y) {	return x >= y ? x - y : x - (LL) y + P; }
inline int mul(int x, int y) {	return (LL)x * y % P; }

int exp(int x, LL n) {
	int res = 1;
	for(; n; n >>= 1) {
		if(n & 1) 
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

comp eps[MaxN]; 
void init() {
	double pi = acos(-1);
	for(int i = 0; i < N; i++)
		eps[i] = comp(cos(2 * pi * i /N), sin(2 * pi * i /N));
}

inline void trans(int n, comp x[], comp w[]) {
    for (int i = 0, j = 0; i != n; i++) {
        if (i < j) std::swap(x[i], x[j]);
        for (int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
    for (int i = 2; i <= n; i <<= 1) {
        int l = i >> 1, d = N / i;
        for (int j = 0; j != n; j += i)
            for (int k = 0; k != l; k++) {
                comp t = mul(x[j + k + l], w[d * k]);
                x[j + k + l] = sub(x[j + k], t);
                x[j + k] = add(x[j + k], t);
            }
    }
}

inline void dft(int n, comp x[]) {
    trans(n, x, eps);
}
inline void idft(int n, comp x[]) {
    trans(n, x, eps);
    reverse(x + 1, x + n);
    for (int i = 0; i < n; i++) x[i] = div(x[i], n);
}

int t[MaxN];
void conv(int na, int a[], int nb, int b[], int nc, int c[], int same = 0) {
    int n, i, j;
    if((LL) na * nb <= 3e4)  {
		for(i = 0; i < nc; i++) t[i] = 0;
		for(i = 0; i < na; i++)
    		for(j = 0; j < nb && j + i < nc; j++)
    			t[i + j] = add(t[i + j], mul(a[i], b[j]));
		for(i = 0; i <= nc; i++) c[i] = t[i];
		return;
	}
    static comp x[MaxN], y[MaxN], z[MaxN], w[MaxN];
    for(n = 1; n < na + nb - 1; n <<= 1);
    for(i = 0; i < n; i++){
    	x[i] = i < na ? comp(a[i] & K, a[i] >> L): comp(0, 0);
    	y[i] = i < nb ? comp(b[i] & K, b[i] >> L): comp(0, 0);    	
	}
	dft(n, x); 
	if(!same) 
		dft(n, y);
	else
		for(i = 0; i < n; i++) y[i] = x[i];
    comp r0(0.5, 0), r1(0, -0.5), r(0, 1);
	for(i = 0; i < n; i++){
		int j = (n - i) & (n - 1);
		comp x0, x1, y0, y1;
		x0 = mul(add(x[i], conj(x[j])), r0);
		x1 = mul(sub(x[i], conj(x[j])), r1);
		y0 = mul(add(y[i], conj(y[j])), r0);
		y1 = mul(sub(y[i], conj(y[j])), r1);
		z[i] = mul(x0, add(y0, mul(y1, r)));
		w[i] = mul(x1, add(y0, mul(y1, r)));
 	}
 	idft(n, z);
	idft(n, w); 
    for(i = 0; i < nc; i++) {
        int c00 = (LL)(z[i].r + 0.5) % P, c01 = (LL)(z[i].i + 0.5) % P;
        int c10 = (LL)(w[i].r + 0.5) % P, c11 = (LL)(w[i].i + 0.5) % P;
        c[i] = ((((LL)c11 << L) + c01 + c10 << L) + c00) % P;
    }
}

int nL;
int n, l, r, x[MaxN], y[MaxN];

void pow(int x[], int y[], int n) {
	y[0] = 1;
	int sN = 3; nL = 1;
	for(; n; n >>= 1) {
		if(n & 1) 
			conv(sN, x, nL, y, min(nL + sN, 2 * :: n + 3), y), nL = min(nL + sN, 2 * :: n + 3);
		conv(sN, x, sN, x, min(sN << 1, 2 * :: n + 3), x, 1); sN = min(sN << 1, 2 * :: n + 3);
	}
}


int res(int x) {
	return y[x + n];
}

int main() {
	int ans; init();
	cin >> n >> P >> l >> r;
	x[0] = x[1] = x[2] = 1;pow(x, y, n);
	ans = ((LL) res(l) + res(l + 1) - res(r + 1) - res(r + 2)) % P; 
	cout << ((LL) ans + P) % P << endl;
	return 0;
}