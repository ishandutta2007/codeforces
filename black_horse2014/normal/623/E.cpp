#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

namespace FFT {

	const int MAXN = 1<<18;
	typedef long double DB;
	typedef long long LL;

	struct CP {
		DB x, y;
		CP(DB x=0, DB y=0) : x(x), y(y) {}
		CP operator+(const CP &rhs) const {
			return CP(x+rhs.x, y+rhs.y);
		}
		void operator+=(const CP &rhs) {
			x += rhs.x, y += rhs.y;
		}
		CP operator-(const CP &rhs) const {
			return CP(x-rhs.x, y-rhs.y);
		}
		CP operator*(const CP &rhs) const {
			return CP(x*rhs.x-y*rhs.y, x*rhs.y+y*rhs.x);
		}
		CP operator!() const {
			return (CP) {
				x, -y
			};
		}
		void operator*=(const CP &rhs) {
			DB tx = x*rhs.x-y*rhs.y, ty = x*rhs.y+y*rhs.x;
			x = tx, y = ty;
		}
	} f[MAXN], g[MAXN], h[MAXN], p_w[MAXN+1];

	int bit_inv[MAXN];

	void init() {
		DB alpha = acos(-1)/MAXN*2;
		for (int i = 0; i <= MAXN; i++) p_w[i] = CP(cos(alpha*i), sin(alpha*i));
		for (int i = 0, j = 1; j < MAXN; j++) {
			for (int k = MAXN >> 1; (i ^= k) < k; k >>= 1);
			bit_inv[j] = i;
		}
	}

	void FFT(CP *A, int N, int D = 1) {
		for (int j = 1, i, d = __builtin_ctz(MAXN/N); j < N-1; j++) if ((i = (bit_inv[j] >> d)) < j) swap(A[i], A[j]);
		for (int n = 1, m = MAXN/2*D; n < N; m /= 2, n <<= 1) {
			for (int i = 0; i < N; i += n<<1) {
				CP *w = (D == 1 ? p_w : p_w + MAXN), *a = A+i, *b = A+i+n;
				for (int j = 0; j < n; j++, a++, b++, w += m) {
					CP x = *w **b;
					*b = *a - x;
					*a += x;
				}
			}
		}
		if (D != 1) for (int i = 0; i < N; i++) A[i].x /= N, A[i].y /= N;
	}

	void conv(int *A, int *B, int *C, int N, int MOD) {
		if (N <= 64) {
			static int temp[64];
			memset(temp, 0, sizeof(int)*N);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N-i; j++) temp[i+j] = (temp[i+j] + 1LL * A[i] * B[j]) % MOD;
				for (int j = N-i; j < N; j++) temp[i+j-N] = (temp[i+j-N] + 1LL * A[i] * B[j]) % MOD;
			}
			memcpy(C, temp, sizeof(int)*N);
			return;
		}
		for (int i = 0; i < N; i++) f[i] = CP(A[i]>>15, A[i]&32767);
		FFT(f, N);
		for (int i = 0; i < N; i++) g[i] = CP(B[i]>>15, B[i]&32767);
		FFT(g, N);
		for (int i = 0; i < N; i++) {
			int j=i?N-i:0;
			h[i]=((f[i]+!f[j])*(!g[j]-g[i])+(!f[j]-f[i])*(g[i]+!g[j]))*CP(0,0.25);
		}
		FFT(h, N, -1);
		for (int i = 0; i < N; i++) C[i] = (LL(h[i].x+0.5)%MOD<<15)%MOD;
		for (int i = 0; i < N; i++) {
			int j=i?N-i:0;
			h[i]=(!f[j]-f[i])*(!g[j]-g[i])*CP(-0.25, 0)+CP(0, 0.25)*(f[i]+!f[j])*(g[i]+!g[j]);
		}
		FFT(h, N, -1);
		for (int i = 0; i < N; i++) C[i] = (C[i] + LL(h[i].x+0.5)+((LL(h[i].y+0.5)%MOD)<<30)) % MOD;
	}

	void conv(int *A, int *B, int N, int MOD) {
		if (N <= 64) {
			static int temp[64];
			memset(temp, 0, sizeof(int)*N);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N-i; j++) temp[i+j] = (temp[i+j] + 1LL * A[i] * A[j]) % MOD;
				for (int j = N-i; j < N; j++) temp[i+j-N] = (temp[i+j-N] + 1LL * A[i] * A[j]) % MOD;
			}
			memcpy(B, temp, sizeof(int)*N);
			return;
		}
		for (int i = 0; i < N; i++) f[i] = CP(A[i]>>15, A[i]&32767);
		FFT(f, N);
		for (int i = 0; i < N; i++) {
			int j=i?N-i:0;
			g[i]=((!(f[j]*f[j]))-f[i]*f[i])*CP(0,0.5);
		}
		FFT(g, N, -1);
		for (int i = 0; i < N; i++) B[i] = (LL(g[i].x+0.5)%MOD<<15)%MOD;
		for (int i = 0; i < N; i++) {
			int j=i?N-i:0;
			g[i]=(!f[j]-f[i])*(!f[j]-f[i])*CP(-0.25,0)+CP(0,0.25)*(f[i]+!f[j])*(f[i]+!f[j]);
		}
		FFT(g, N, -1);
		for (int i = 0; i < N; i++) B[i] = (B[i] + LL(g[i].x+0.5)+((LL(g[i].y+0.5)%MOD)<<30)) % MOD;
	}
};

const int M = 1<<16;

int r[M], a[M], b[M], c[M], pw[M], g[M];

int main() {
	ios::sync_with_stdio(0);
	long long n; int k; cin >> n >> k;
	if (n > k) return puts("0"), 0;
	for (int i = 0; i <= k; i++) {
		r[i] = i<2 ? i : r[P%i] * 1LL * (P-P/i) % P;
		g[i] = i==0 ? 1 : g[i-1] * 1LL * r[i] % P;
	}
	for (int i = 0; i <= k; i++) pw[i] = i == 0 ? 1 : pw[i - 1] * 2 % P;
	int N = 1<<(32-__builtin_clz(k+k));
	a[0] = 1;
	FFT::init();
	for (int i = 14; i >= 0; i--) {
		if (n < 1<<i) continue;
		int m = n>>i+1;
		if (m) {
			memset(b, 0, sizeof(b[0]) * N);
			for (int cur = 1, j = 0; j <= k; j++) {
				b[j] = a[j] * 1LL * cur % P;
				cur = cur * 1LL * pw[m] % P;
			}
			FFT::conv(a, b, a, N, P);
			for (int j = k+1; j < N; j++) a[j] = 0;
		}
		if (n>>i&1) {
			memset(b, 0, sizeof(b[0]) * N);
			for (int cur = 1, j = 0; j <= k; j++) {
				b[j] = j == 0 ? 0 : cur * 1LL * g[j] % P;
				cur = cur * 1LL * pw[(n>>i)-1] % P;
			}
			FFT::conv(a, b, a, N, P);
			for (int j = k+1; j < N; j++) a[j] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) ans = (ans + a[i] * 1LL * g[k-i]) % P;
	for (int i = 1; i <= k; i++) ans = ans * 1LL * i % P;
	cout << ans << endl;
	return 0;
}