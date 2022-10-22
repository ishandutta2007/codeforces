//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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

const int MAXN = 50;
const int SIZ = 2010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, lim;
int p[MAXN], _cnt[MAXN], cnt[MAXN];
int cir[MAXN], c, fac[MAXN], cur[MAXN], pre[MAXN];
int C[MAXN][MAXN], F[MAXN][MAXN];
int dp[SIZ];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Init() {
	static bool vis[MAXN];
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	function< int (int, int) > DFS = [&](int x, int siz) {
		if(vis[x]) return siz;
		vis[x] = true; return DFS(p[x], siz + 1);
	};
	for(int i = 1; i <= n; ++i) 
		if(!vis[i]) _cnt[DFS(i, 0)]++;
	for(int i = 1; i <= n; ++i)
		if(_cnt[i]) { cir[++c] = i; cnt[c] = _cnt[i]; }
	C[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	for(int i = 0; i < n; ++i) {
		F[i][0] = F[i][1] = 1;
		for(int j = 1; j <= n; ++j) if(j != n - i) (F[i][1] *= j) %= mod;
		for(int j = 2; j <= n; ++j) F[i][j] = (F[i][j - 1] * F[i][1]) % mod;
	}
	for(int i = 1; i <= c; ++i) lim = lim * (cnt[i] + 1) + cnt[i];
}

int encode(int *a) {
	int res = 0;
	for(int i = 1; i <= c; ++i) res = res * (cnt[i] + 1) + a[i];
	return res;
}

void decode(int a) {
	for(int i = c; i >= 1; --i) {
		cur[i] = a % (cnt[i] + 1);
		a /= (cnt[i] + 1);
	}
}

void nxt(int *a) {
	a[1]++;
	for(int i = 1; i <= c; ++i) {
		if(a[i] > cnt[i]) a[i] = 0, a[i + 1]++;
		else break;
	}
}

signed main () {
#ifdef FILE
	freopen("CF1466H.in", "r", stdin);
	freopen("CF1466H.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(p[i]);
	Init(); dp[0] = 1;
	for(int i = 0, j, sumi, sumj, cnti, cntj, coe; i <= lim; ++i) {
		decode(i); memset(pre, 0, sizeof pre);
		sumi = cnti = 0;
		for(int p = 1; p <= c; ++p) cnti += cur[p], sumi += cur[p] * cir[p];
		while(1) {
			j = encode(pre); if(i == j) break;
			sumj = cntj = 0, coe = 1;
			for(int p = 1; p <= c; ++p) cntj += pre[p], sumj += pre[p] * cir[p];
			for(int p = 1; p <= c; ++p) coe = coe * C[cur[p]][pre[p]] % mod;
			if(!((cnti - cntj) & 1)) coe = mod - coe;
			(dp[i] += dp[j] * coe % mod * F[sumj][sumi - sumj]) %= mod;
			nxt(pre);
		}
	}
	printf("%lld\n", dp[lim]);
	return 0;
}