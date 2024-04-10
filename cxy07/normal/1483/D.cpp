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

const int MAXN = 610;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, Ans = 0;
int dis[MAXN][MAXN], lim[MAXN][MAXN];
int X[MAXN * MAXN], Y[MAXN * MAXN], W[MAXN * MAXN];
bool con[MAXN][MAXN], ok[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m);
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1, x, y, w; i <= m; ++i) {
		read(x), read(y), read(w);
		dis[x][y] = dis[y][x] = min(dis[x][y], w);
		X[i] = x, Y[i] = y, W[i] = w;
	}
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	read(q);
	while(q--) {
		int x, y, l;
		read(x), read(y), read(l);
		for(int i = 1; i <= n; ++i) {
			lim[x][i] = max(lim[x][i], l - dis[i][y]);
			lim[y][i] = max(lim[y][i], l - dis[i][x]);
			lim[i][x] = lim[x][i], lim[i][y] = lim[y][i];
		}
	}
	for(int ii = 1, i, j; ii <= m; ++ii) {
		i = X[ii], j = Y[ii];
		for(int k = 1; k <= n; ++k) {
			if(lim[i][k] >= W[ii] + dis[j][k]) {Ans++; break;}
			if(lim[j][k] >= W[ii] + dis[i][k]) {Ans++; break;}
		}
	}
	printf("%lld\n", Ans);
	return 0;
}