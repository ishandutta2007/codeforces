#include <bits/stdc++.h>
using namespace std;

const int P = 1009;

int C[P][P];

int choose(int n, int k) {
	if (k < 0 || k > n) return 0;
	return C[n % P][k % P] * C[n / P][k / P] % P;
}

const int MAXN = 1<<19;

namespace FFT {

	const int MAXN = 1<<19;
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
		for (int i = 0; i < N; i++) f[i] = CP(A[i], 0);
		FFT(f, N);
		for (int i = 0; i < N; i++) g[i] = CP(B[i], 0);
		FFT(g, N);
		for (int i = 0; i < N; i++) h[i] = f[i] * g[i];
		FFT(h, N, -1);
		for (int i = 0; i < N; i++) C[i] = LL(h[i].x + 0.5) % MOD;
	}
};

int a[MAXN], b[MAXN], c[MAXN];

int solve(int st, int en, int *a) {
	int deg = 0;
	for (int i = st; i <= en; i++) deg += c[i] * i;
	int sum = 0;
	int flg = 0;
	for (int i = st; i <= en; i++) if (c[i]) flg++;
	if (flg == 0) {
		a[0] = 1;
		return 0;
	}
	if (flg == 1) {
		for (int i = st; i <= en; i++) {
			if (c[i]) {
				for (int j = 0; j <= i * c[i]; j++) a[j] = 0;
				for (int j = 0; j <= c[i]; j++) {
					if (j & 1) a[j * i] = P - choose(c[i], j);
					else a[j * i] = choose(c[i], j);
				}
				return deg;
			}
		}
	}
	int n = 1 << (32 - __builtin_clz(deg));
	int mid = st;
	sum = c[st] * st;
	for (int i = st + 1; i <= en; i++) {
		if (sum + c[i] * i > deg / 2) {
			mid = i - 1;
			break;
		}
		sum += c[i] * i;
	}
	int l = solve(st, mid, a);
	int *b = new int[n];
	int r = solve(mid+1, en, b);
	for (int i = l+1; i < n; i++) a[i] = 0;
	for (int i = r+1; i < n; i++) b[i] = 0;
	FFT::conv(a, b, a, n, P);
	delete b;
	return deg;
	assert(0);
}

int main() {
	FFT::init();
	for (int i = 0; i < P; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
	}
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]]++;
	for (int i = 1; i <= m; i++) c[b[i] + 1]++;
	int deg = solve(1, n + 1, a);
	for (int i = 0; i <= deg; i++) b[i] = choose(m + i - 1, i);
	int ans = 0;
	for (int i = 0; i <= deg && i <= k; i++) ans = (ans + b[i] * a[k - i]) % P;
	cout << ans << endl;
	return 0;
}