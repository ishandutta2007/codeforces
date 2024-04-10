#include <bits/stdc++.h>
using namespace std;

const int MAXM = 110;
const int MAXT = 32768;

int a[MAXM], b[MAXM], c[MAXM], dis[55][55];
long double x[1<<16], y[1<<16], z[1<<16];
double p[MAXM][MAXT];
long double dp[MAXM][MAXT];
double psum[MAXM][MAXT];
long double ans[55][MAXT];

int M;

namespace FFT {

	const int MAXN = 1<<15;
	typedef long double DB;

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

	void conv(DB *A, DB *B, DB *C, int N) {
		for (int i = 0; i < N; i++) f[i] = CP(A[i], 0);
		for (int i = 0; i < N; i++) g[i] = CP(B[i], 0);
		FFT(f, N);
		FFT(g, N);
		for (int i = 0; i < N; i++) h[i] = f[i] * g[i];
		FFT(h, N, -1);
		for (int i = 0; i < N; i++) C[i] = h[i].x;
	}
};

void mul(long double *A, long double *B, long double *C, int N) {
	FFT::conv(A, B, C, N);
}

int N;

void solve(int L, int R) {
	if (L == R) {
		for (int i = 0; i < M; i++) ans[a[i]][L] = min(ans[a[i]][L], dp[i][L] + c[i]);
		return;
	}
	int mid = L + R >> 1;
	solve(mid + 1, R);
	for (int i = 0; i < M; i++) {
		int n = 1 << (32 - __builtin_clz(R - L - 1 + R - mid - 1));
		memset(x, 0, sizeof(x[0]) * n);
		memset(y, 0, sizeof(y[0]) * n);
		for (int j = 0; j < R - mid; j++) x[j] = ans[b[i]][mid + 1 + j];
		for (int j = 0; j < R - L; j++) y[j] = p[i][R - L - j];
		mul(x, y, z, n);
		assert(n <= 32768);
		for (int j = R - mid - 1; j <= R - L - 1; j++) dp[i][j + mid + 1 - (R - L)] += z[j];
	}
	solve(L, mid);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FFT::init();
	int T, X; cin >> N >> M >> T >> X;
	const int inf = 1e9;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dis[i][j] = i == j ? 0 : inf;
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		dis[a[i]][b[i]] = c[i];
		for (int j = 1; j <= T; j++) {
			int x; cin >> x; p[i][j] = x * 1e-5;
		}
	}
	for (int u = 1; u <= N; u++) {
		for (int v = 1; v <= N; v++) {
			for (int w = 1; w <= N; w++) {
				dis[v][w] = min(dis[v][w], dis[v][u] + dis[u][w]);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = T; j > 0; j--) psum[i][j] = psum[i][j + 1] + p[i][j];
		for (int j = 1; j <= T; j++) {
			dp[i][j] += psum[i][T + 1 - j] * (dis[b[i]][N] + X);
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= T; j++) ans[i][j] = inf;
	}
	solve(0, T);
	printf("%.10lf\n", (double)ans[1][0]);
	return 0;
}