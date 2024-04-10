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

const int MAXN = 410;
const int MAXM = 610;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int dis[MAXN][MAXN], cnt[MAXN][MAXN];
int Ans[MAXN][MAXN];
vec<int> G[MAXN];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void BFS(int s) {
	while(Q.size()) Q.pop();
	Q.push(s); dis[s][s] = 0, cnt[s][s] = 1;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		for(auto to : G[x]) {
			if(dis[s][to] > dis[s][x] + 1) dis[s][to] = dis[s][x] + 1, cnt[s][to] = cnt[s][x], Q.push(to);
			else if(dis[s][to] == dis[s][x] + 1) cnt[s][to] = min(cnt[s][to] + cnt[s][x], 2ll);
		}
	}
}

int calc(int x, int y) {
	if(cnt[x][y] > 1) return 0;
	int res = 1;
	for(int i = 1; i <= n; ++i) {
		if(dis[x][i] + dis[i][y] == dis[x][y]) continue;
		int c = 0;
		for(auto fa : G[i])
			if(dis[x][i] == dis[x][fa] + 1 && dis[y][i] == dis[y][fa] + 1) ++c;
		res = res * c % mod;
	} return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m); memset(dis, 0x3f, sizeof dis);
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	for(int i = 1; i <= n; ++i) BFS(i);
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j) Ans[i][j] = Ans[j][i] = calc(i, j);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) printf("%lld%c", Ans[i][j], " \n"[j == n]);
	return 0;
}