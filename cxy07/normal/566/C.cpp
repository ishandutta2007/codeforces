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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, ansp;
int a[MAXN], siz[MAXN], maxson[MAXN], rt, totsiz;
bool vis[MAXN];
double sum, sumd, d[MAXN], Ans;
vec<pii> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void GetRoot(int x, int fa = 0) {
	if(vis[x]) return;
	siz[x] = 1, maxson[x] = 0;
	for(auto to : G[x]) {
		if(vis[to.fst] || to.fst == fa) continue;
		GetRoot(to.fst, x);
		siz[x] += siz[to.fst];
		maxson[x] = max(maxson[x], siz[to.fst]);
	}
	maxson[x] = max(maxson[x], totsiz - siz[x]);
	if(!rt || maxson[x] < maxson[rt]) rt = x;
}

void calc(int x, int fa, int root, int dep) {
	sum += a[x] * pow(dep, 1.5);
	sumd += a[x] * pow(dep, 0.5) * 1.5;
	d[root] += a[x] * pow(dep, 0.5) * 1.5;
	for(auto to : G[x]) {
		if(to.fst == fa) continue;
		calc(to.fst, x, root, dep + to.scd);
	}
}

void solve(int x) {
	rt = 0, totsiz = siz[x]; GetRoot(x, 0);
	x = rt; GetRoot(x, 0);
	if(vis[x]) return;
	vis[x] = true;
	sum = sumd = 0;
	for(auto to : G[x]) {
		d[to.fst] = 0;
		calc(to.fst, x, to.fst, to.scd);
	}
	if(!ansp || Ans > sum) Ans = sum, ansp = x;
	for(auto to : G[x]) {
		if(vis[to.fst]) continue;
		if(sumd - 2. * d[to.fst] < 0) {
			solve(to.fst);
			break;
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1, x, y, w; i < n; ++i) {
		read(x), read(y), read(w);
		G[x].pb(mp(y, w));
		G[y].pb(mp(x, w));
	}
	rt = 0, totsiz = n; GetRoot(1); GetRoot(rt);
	solve(rt);
	printf("%d %.20lf\n", ansp, Ans);
	return 0;
}