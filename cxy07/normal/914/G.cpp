//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 1e6 + 10;
const int SIZ = (1 << 17) + 10;
const int MAXS = 18;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, lim, Ans, s[MAXN], Fib[MAXN], popc[SIZ];
int A[MAXS][SIZ], B[SIZ], tmp[MAXS][SIZ];
int C[SIZ], D[SIZ];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void FWT(int *A, int opt) {
	if(opt == -1) opt = (mod + 1) >> 1;
	for(int mid = 1; mid < lim; mid <<= 1) {
		for(int i = 0; i < lim; i += (mid << 1)) {
			for(int j = 0, x, y; j < mid; ++j) {
				x = A[i + j], y = A[i + j + mid];
				A[i + j] = (x + y) * opt % mod;
				A[i + j + mid] = (x - y + mod) * opt % mod;
			}
		}
	}
}

void FMTAND(int *A, int opt) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += (mid << 1))
			for(int j = 0; j < mid; ++j)
				(A[i + j] += mod + A[i + j + mid] * opt) %= mod;
}

void FMTOR(int *A, int opt) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += (mid << 1))
			for(int j = 0; j < mid; ++j)
				(A[i + j + mid] += mod + A[i + j] * opt) %= mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); lim = 1 << 17;
	for(int i = 1; i < lim; ++i) 
		popc[i] = popc[i >> 1] + (i & 1);
	for(int i = 1; i <= n; ++i) {
		read(s[i]);
		A[popc[s[i]]][s[i]]++, C[s[i]]++, D[s[i]]++;
	}
	Fib[1] = Fib[2] = 1;
	for(int i = 3; i < lim; ++i) Fib[i] = (Fib[i - 1] + Fib[i - 2]) % mod;
	for(int i = 0; i <= 17; ++i) FMTOR(A[i], 1);
	FWT(D, 1);
	for(int i = 0, sum; i < lim; ++i) {
		for(int a = 0; a <= 17; ++a) {
			sum = 0;
			for(int b = 0; b <= a; ++b)
				(sum += A[b][i] * A[a - b][i] % mod) %= mod;
			tmp[a][i] = sum;
		}
		D[i] = D[i] * D[i] % mod;
	}
	for(int i = 0; i <= 17; ++i) FMTOR(tmp[i], -1);
	FWT(D, -1);
	for(int i = 0; i < lim; ++i) {
		B[i] = tmp[popc[i]][i];
		B[i] = B[i] * Fib[i] % mod;
		C[i] = C[i] * Fib[i] % mod;
		D[i] = D[i] * Fib[i] % mod;
	}
	FMTAND(B, 1), FMTAND(C, 1), FMTAND(D, 1);
	for(int i = 0; i < lim; ++i)
		B[i] = B[i] * C[i] % mod * D[i] % mod;
	FMTAND(B, -1);
	for(int i = 0; (1 << i) < lim; ++i) (Ans += B[1 << i]) %= mod;
	printf("%lld\n", (Ans + mod) % mod);
	return 0;
}