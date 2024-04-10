//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int X[MAXN], Y[MAXN], c[MAXN], dsu[MAXN];
int dp[MAXN][2];
char _s[10];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int find(int x) { return x == dsu[x] ? x : dsu[x] = find(dsu[x]); }

void unity(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	dsu[x] = y;
}

void DFS(int x, int fa) {
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS(to, x);
		if(dp[to][0] + 1 > dp[x][0]) swap(dp[x][0], dp[x][1]), dp[x][0] = dp[to][0] + 1;
		else if(dp[to][0] + 1 > dp[x][1]) dp[x][1] = dp[to][0] + 1;
	} Ans = max(Ans, dp[x][0] + dp[x][1]);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i)  {
		dsu[i] = i;
		read(c[i]);
	}
	for(int i = 1; i < n; ++i) {
		read(X[i]), read(Y[i]);
		if(c[X[i]] == c[Y[i]]) unity(X[i], Y[i]);
	}
	for(int i = 1; i < n; ++i) {
		X[i] = find(X[i]), Y[i] = find(Y[i]);
		if(X[i] == Y[i]) continue;
		G[X[i]].pb(Y[i]), G[Y[i]].pb(X[i]);
	} DFS(find(1), 0);
	printf("%d\n", (Ans + 1) >> 1);
	return 0;
}