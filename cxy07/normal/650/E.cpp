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

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
int dep[2][MAXN], fa[2][MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int p[MAXN], dsu[MAXN];
vec<int> G[2][MAXN];
map<int, int> ap[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int d, int x, int f) {
	fa[d][x] = f, dep[d][x] = dep[d][f] + 1;
	for(int i = 0; i < G[d][x].size(); ++i)
		if(G[d][x][i] != f) DFS(d, G[d][x][i], x);
}

bool cmp(int x, int y) {return dep[0][x] > dep[0][y];}

bool ok(int x, int y) {return ap[x][y];}

int find(int x) {
	if(dsu[x] != x) return dsu[x] = find(dsu[x]);
	return x;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		G[0][x].pb(y), G[0][y].pb(x);
	}
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		ap[x][y] = ap[y][x] = true;
		G[1][x].pb(y), G[1][y].pb(x);
	}
	DFS(0, 1, 0), DFS(1, 1, 0);
	for(int i = 1; i <= n; ++i) {
		p[i] = i;
		if((i ^ 1) && (fa[0][i] == fa[1][i] || fa[0][fa[1][i]] == i)) dsu[i] = fa[1][i];
		else dsu[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n; ++i) {
		if(p[i] == 1 || ok(p[i], fa[0][p[i]])) continue;
		Ans++;
		a[Ans] = p[i], b[Ans] = fa[0][p[i]], c[Ans] = find(p[i]), d[Ans] = fa[1][find(p[i])];
	}
	printf("%d\n", Ans);
	for(int i = 1; i <= Ans; ++i)
		printf("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
	return 0;
}