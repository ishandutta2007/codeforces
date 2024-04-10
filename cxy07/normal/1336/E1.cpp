//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcountll(x)
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
#define y1 _y1

const int MAXN = 2e5 + 10;
const int MAXD = 60;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, tot;
int a[MAXN], d[MAXD], b[MAXD], cnt[MAXD], Ans[MAXD], s[MAXD];
int f[MAXD][MAXD], C[MAXD][MAXD];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void Insert(int x) {
	for(int i = m - 1; ~i; --i) {
		if(!((x >> i) & 1)) continue;
		if(!d[i]) return d[i] = x, ++k, void();
		x ^= d[i];
	}
}

int qpow(int x, int b) {
	int res = 1; if(b < 0) b += mod - 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void DFS(int x, int S) {
	if(x > tot) return ++cnt[popc(S)], void();
	DFS(x + 1, S);
	if(s[x]) DFS(x + 1, S ^ s[x]);
}

signed main () {
#ifdef FILE
	freopen("CF1336E2.in", "r", stdin);
	freopen("CF1336E2.out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 0; i < MAXD; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	for(int i = 1; i <= n; ++i) read(a[i]), Insert(a[i]);
	if(k <= 26) {
		for(int i = 0; i <= m; ++i) if(d[i]) s[++tot] = d[i];
		DFS(0, 0);
		for(int i = 0; i <= m; ++i) Ans[i] = cnt[i];
	} else {
		for(int i = m - 1; ~i; --i)
			for(int j = 0; j < m; ++j)
				if(i != j && (d[j] >> i) & 1) d[j] ^= d[i];
		for(int i = 0; i < m; ++i) {
			if(d[i]) continue;
			b[i] = (1ll << i); 
			for(int j = 0; j < m; ++j) if((d[j] >> i) & 1) b[i] |= (1ll << j);
		} 
		for(int i = 0; i <= m; ++i) if(b[i]) s[++tot] = b[i];
		for(int a = 0; a <= m; ++a)
			for(int c = 0; c <= m; ++c)
				for(int b = 0, opt = 1; b <= c; ++b) {
					(f[a][c] += C[m - a][c - b] * C[a][b] % mod * opt) %= mod;
					opt = (mod - opt) % mod;
				}
		DFS(0, 0);
		for(int i = 0; i <= m; ++i) {
			for(int j = 0; j <= m; ++j) (Ans[i] += cnt[j] * f[j][i]) %= mod;
			Ans[i] = Ans[i] * qpow(2, k - m) % mod;
		}
	}
	for(int i = 0; i <= m; ++i) Ans[i] = Ans[i] * qpow(2, n - k) % mod;
	for(int i = 0; i <= m; ++i) printf("%lld ", Ans[i]);
	return 0;
}