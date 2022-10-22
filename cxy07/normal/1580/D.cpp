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

const int MAXN = 4010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, rt, a[MAXN];
int p[MAXN], ls[MAXN], rs[MAXN], siz[MAXN];
int stk[MAXN], top, dp[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x) {
	siz[x] = 1, dp[x][0] = 0, dp[x][1] = m * a[x] - a[x];
	if(ls[x]) {
		DFS(ls[x]);
		for(int i = siz[x]; i >= 0; --i) {
			for(int j = 1; j <= siz[ls[x]]; ++j)
				dp[x][i + j] = max(dp[x][i + j], dp[x][i] + dp[ls[x]][j] - 2 * i * j * a[x]);
		} siz[x] += siz[ls[x]];
	}
	if(rs[x]) {
		DFS(rs[x]);
		for(int i = siz[x]; i >= 0; --i) {
			for(int j = 1; j <= siz[rs[x]]; ++j)
				dp[x][i + j] = max(dp[x][i + j], dp[x][i] + dp[rs[x]][j] - 2 * i * j * a[x]);
		} siz[x] += siz[rs[x]];
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) {
		while(top && a[stk[top]] > a[i]) ls[i] = stk[top--];
		if(top) rs[stk[top]] = i;
		stk[++top] = i;
	} rt = stk[1];
	DFS(rt); printf("%lld\n", dp[rt][m]);
	return 0;
}