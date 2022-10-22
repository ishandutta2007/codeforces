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
#define y1 _y1

const int MAXN = 2010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, mod, Ans[MAXN];
int dp[MAXN][MAXN], son[MAXN], C[MAXN][MAXN];
int pre[MAXN], suf[MAXN], sum[MAXN], coef[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x, int fa) {
	for(auto to : G[x]) if(to ^ fa) DFS(to, x);
	m = 0; 
	for(auto to : G[x]) if(to ^ fa) son[++m] = to;
	dp[x][1] = pre[0] = suf[m + 1] = 1;
	for(int i = 1; i <= m; ++i) sum[son[i]] = dp[son[i]][1];
	for(int t = 2, pd, tot; t < n; ++t) {
		pd = 1, tot = 0;
		for(int i = 1; i <= m; ++i) pre[i] = pre[i - 1] * sum[son[i]] % mod;
		for(int i = m; i >= 1; --i) suf[i] = suf[i + 1] * sum[son[i]] % mod;
		for(int i = 1; i <= m; ++i) {
			(coef[son[i]] += pre[i - 1] * suf[i + 1]) %= mod;
			(tot += dp[son[i]][t] * coef[son[i]]) %= mod;
		}
		for(int i = 1; i <= m; ++i) {
			(sum[son[i]] += dp[son[i]][t]) %= mod;
			pd = pd * sum[son[i]] % mod;
		}
		dp[x][t] = pd;
		if(x != 1) (dp[x][t] += tot) %= mod;
	}
}

signed main () {
#ifdef FILE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	read(n), read(mod);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	DFS(1, 0);
	for(int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	for(int i = 1; i < n; ++i)
		for(int j = i, o = 1; j >= 1; --j) {
			(Ans[i] += dp[1][j] * o % mod * C[i][j]) %= mod;
			o = (mod - o) % mod;
		}
	for(int i = 1; i < n; ++i) printf("%lld ", Ans[i]);
	return 0;
}