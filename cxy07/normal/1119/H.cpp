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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, x, y, z, lim, sum;
int F[MAXN], F1[MAXN], F2[MAXN], F3[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int s1, s2, s3, s4;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int qpow(int x, int b) { 
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void FWT(int *A, int opt) {
	if(opt == -1) opt = (mod + 1) >> 1;
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += (mid << 1))
			for(int j = 0, x, y; j < mid; ++j) {
				x = A[i + j], y = A[i + j + mid];
				A[i + j] = x + y;
				A[i + j + mid] = x - y;
				(A[i + j] *= opt) %= mod, (A[i + j + mid] *= opt) %= mod;
			}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k); lim = 1 << k;
	read(x), read(y), read(z);
	for(int i = 1; i <= n; ++i) {
		read(a[i]), read(b[i]), read(c[i]);
		b[i] ^= a[i], c[i] ^= a[i], sum ^= a[i];
		F1[b[i]]++, F2[c[i]]++, F3[b[i] ^ c[i]]++;
	}
	FWT(F1, 1), FWT(F2, 1), FWT(F3, 1);
	s1 = (x + y + z) % mod;
	s2 = (x + y - z + mod) % mod;
	s3 = (x - y + z + mod) % mod;
	s4 = (x - y - z + mod) % mod;
	for(int i = 0, c1, c2, c3, c4; i < lim; ++i) {
		c1 = (n + F1[i] + F2[i] + F3[i]) >> 2;
		c2 = (n + F1[i] - (c1 << 1)) >> 1;
		c3 = (n + F2[i] - (c1 << 1)) >> 1;
		c4 = (n + F3[i] - (c1 << 1)) >> 1;
		F[i] = qpow(s1, c1) * qpow(s2, c2) % mod * qpow(s3, c3) % mod * qpow(s4, c4) % mod;
	}
	FWT(F, -1);
	for(int i = 0; i < lim; ++i) F[i] = (F[i] + mod) % mod;
	for(int i = 0; i < lim; ++i) printf("%lld ", F[i ^ sum]);
	return 0;
}