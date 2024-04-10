//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

int n, m, t, T;
int c1 = -INF, c2 = INF, l[MAXN], r[MAXN];
int col[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool pd(int x, int i) {return l[i] <= x && x <= r[i];}

bool DFS(int x) {
	for(auto to : G[x]) {
		if(!col[to]) {
			col[to] = 3 - col[x];
			if(!DFS(to)) return false;
		} else if(col[to] == col[x]) return false;
	}
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(t), read(T), read(n), read(m);
	for(int i = 1; i <= n; ++i) {
		read(l[i]), read(r[i]);
		c1 = max(c1, l[i]), c2 = min(c2, r[i]);
	}
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	if(c1 + c2 < t) c1 = t - c2;
	if(c1 + c2 > T) c2 = T - c1;
	if(c1 < 0 || c2 < 0) return puts("IMPOSSIBLE"), 0;
	for(int i = 1; i <= n; ++i) {
		if(!pd(c1, i) && !pd(c2, i)) return puts("IMPOSSIBLE"), 0;
		if(pd(c1, i) && !pd(c2, i)) col[i] = 1;
		if(!pd(c1, i) && pd(c2, i)) col[i] = 2;
	}
	for(int i = 1; i <= n; ++i)
		if(col[i] && !DFS(i)) return puts("IMPOSSIBLE"), 0;
	for(int i = 1; i <= n; ++i) {
		if(col[i]) continue;
		col[i] = 1;
		if(!DFS(i)) return puts("IMPOSSIBLE"), 0;
	}
	puts("POSSIBLE");
	printf("%d %d\n", c1, c2);
	for(int i = 1; i <= n; ++i) printf("%d", col[i]);
	putchar('\n');
	return 0;
}