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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int l[MAXN], r[MAXN];
int dp[MAXN][2];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x, int fa) {
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS(to, x);
		dp[x][0] += max(dp[to][0] + abs(l[to] - l[x]), dp[to][1] + abs(r[to] - l[x]));
		dp[x][1] += max(dp[to][0] + abs(l[to] - r[x]), dp[to][1] + abs(r[to] - r[x]));
	}
}

void solve() {
	read(n);
	for(int i = 1; i <= n; ++i) read(l[i]), read(r[i]);
	for(int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = 0, G[i].clear();
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	DFS(1, 0);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}