//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 60;
const int MAXM = 110;
const int MAXT = 4e4 + 10;
const double INF = 2e16;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct cp {
	double x, y;
	cp(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	cp operator + (const cp &b) const {return cp(x + b.x, y + b.y);}
	cp operator - (const cp &b) const {return cp(x - b.x, y - b.y);}
	cp operator * (const cp &b) const {
		return cp(x * b.x - y * b.y, x * b.y + y * b.x);
	}
} omega[MAXT << 2], A[MAXT << 1], B[MAXT << 1];

int n, m, t, x;
int a[MAXM], b[MAXM];
int rev[MAXT << 2], lim, l;
double c[MAXM], p[MAXM][MAXT << 1], dp[MAXN][MAXT << 1];
double v[MAXM][MAXT << 1];
double dis[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Init(int siz) {
	lim = 1, l = 0;
	while(lim < siz) lim <<= 1, ++l;
	for(int mid = 1; mid < lim; mid <<= 1)
		omega[mid] = cp(cos(PI / mid), sin(PI / mid));
}

void format(int siz) {
	lim = 1, l = 0;
	while(lim < siz) lim <<= 1, ++l;
	for(int i = 0; i < lim; ++i)
		rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (l - 1)));
}

void FFT(cp *A, int opt) {
	for(int i = 0; i < lim; ++i)
		if(rev[i] < i) swap(A[rev[i]], A[i]);
	for(int mid = 1; mid < lim; mid <<= 1) {
		cp w = omega[mid]; w.y *= opt;
		for(int i = 0; i < lim; i += (mid << 1)) {
			cp now(1, 0), x, y;
			for(int j = 0; j < mid; ++j, now = now * w) {
				x = A[i + j], y = A[i + j + mid] * now;
				A[i + j] = x + y, A[i + j + mid] = x - y;
			}
		}
	}
	if(opt == 1) return;
	for(int i = 0; i < lim; ++i) A[i].x /= lim;
}

void cdq(int L, int R) {
	if(L == t) return;
	if(L == R) {
		for(int i = 1; i < n; ++i) dp[i][L] = INF;
		for(int i = 1; i <= m; ++i) {
			if(a[i] == n) continue;
			dp[a[i]][L] = min(dp[a[i]][L], v[i][L] + c[i]);
		}
		return;
	}
	int mid = (L + R) >> 1; cdq(mid + 1, R);
	format((R - L) + (R - mid));
	for(int i = 1; i <= m; ++i) {
		if(a[i] == n) continue;
		for(int j = 0; j < R - L; ++j) A[j] = cp(p[i][j + 1], 0);
		for(int j = R - L; j < lim; ++j) A[j] = cp(0, 0);
		for(int j = 0; j < R - mid; ++j) B[j] = cp(dp[b[i]][R - j], 0);
		for(int j = R - mid; j < lim; ++j) B[j] = cp(0, 0);
		FFT(A, 1), FFT(B, 1);
		for(int j = 0; j < lim; ++j) A[j] = A[j] * B[j];
		FFT(A, -1);
		for(int j = L; j <= mid; ++j) v[i][j] += A[R - j - 1].x;
	}
	cdq(L, mid);
}

signed main () {
#ifdef FILE
	freopen("CF553E.in", "r", stdin);
	freopen("CF553E.out", "w", stdout);
#endif
	read(n), read(m), read(t), read(x);
	Init((int)8e4);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			dis[i][j] = dis[j][i] = INF;
	for(int i = 1; i <= m; ++i) {
		read(a[i]), read(b[i]); scanf("%lf", &c[i]);
		dis[a[i]][b[i]] = c[i];
		for(int j = 1; j <= t; ++j) scanf("%lf", &p[i][j]), p[i][j] /= 100000.;
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i = 0; i < (t << 1); ++i) dp[n][i] = (i <= t) ? 0 : x;
	for(int i = 1; i < n; ++i)
		for(int j = t; j < (t << 1); ++j) 
			dp[i][j] = dis[i][n] + x;
	cdq(0, (t << 1) - 1);
	printf("%.10lf\n", dp[1][0]);
	return 0;
}