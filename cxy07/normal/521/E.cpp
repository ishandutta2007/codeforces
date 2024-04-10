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
#define y1 _y1

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int dep[MAXN], stx[MAXN], sty[MAXN], fa[MAXN];
bool vis[MAXN], instk[MAXN];
vec<int> G[MAXN], Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int LCA(int x, int y) {
	while(x ^ y) {
		if(dep[x] < dep[y]) swap(x, y);
		x = fa[x];
	}
	return x;
}

void add(int x, int y) {
	while(x ^ y) Ans.pb(x), x = fa[x];
	Ans.pb(x);
}

void print() {
	printf("%ld ", Ans.size());
	for(auto v : Ans) printf("%d ", v);
	putchar('\n'); Ans.clear();
}

void solve(int x1, int y1, int x2, int y2) {
	puts("YES");
	if(dep[y1] > dep[y2]) swap(x1, x2), swap(y1, y2);
	int lca = LCA(x1, x2);
	add(lca, y2); reverse(Ans.begin(), Ans.end()); print();
	add(y2, y1); add(x1, lca); print();
	add(y2, y2); add(x2, lca); print();
	exit(0);
}

void DFS(int x, int f) {
	vis[x] = instk[x] = true;
	fa[x] = f, dep[x] = dep[f] + 1;
	for(auto to : G[x]) {
		if(to == f) continue;
		if(!vis[to]) DFS(to, x);
		else if(instk[to]) {
			for(int now = x; now != to; now = fa[now]) {
				if(stx[now] && sty[now]) solve(stx[now], sty[now], x, to);
				else stx[now] = x, sty[now] = to;
			}
		}
	}
	instk[x] = false;
}

signed main () {
#ifdef FILE
	freopen("CF521E.in", "r", stdin);
	freopen("CF521E.out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1, x, y; i <= m; ++i) {
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) DFS(i, 0);
	puts("NO");
	return 0;
}