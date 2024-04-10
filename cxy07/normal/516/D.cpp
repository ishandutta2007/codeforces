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
const int INF = 2e17;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q, lim, Ans;
int dep1[MAXN], dep2[MAXN], d[MAXN], A, B, root;
int tag[MAXN];
vec<pii> G[MAXN], now;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS(int x, int fa, int *dep) {
	for(auto to : G[x]) {
		if(to.fst == fa) continue;
		dep[to.fst] = dep[x] + to.scd; 
		DFS(to.fst, x, dep);
	}
}

void solve(int x, int fa) {
	now.pb(mp(d[x], x));
	tag[x] = 1;
	int pos = (*(--lower_bound(now.begin(), now.end(), mp(d[x] - lim, 0ll)))).scd;
	tag[pos]--;
	for(auto to : G[x]) {
		if(to.fst == fa) continue;
		solve(to.fst, x);
		tag[x] += tag[to.fst];
	}
	Ans = max(Ans, tag[x]);
	now.pop_back();
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1, x, y, w; i < n; ++i) {
		read(x), read(y), read(w);
		G[x].pb(mp(y, w)), G[y].pb(mp(x, w));
	}
	dep1[1] = 0; DFS(1, 0, dep1); A = max_element(dep1 + 1, dep1 + n + 1) - dep1;
	dep1[A] = 0; DFS(A, 0, dep1); B = max_element(dep1 + 1, dep1 + n + 1) - dep1;
	dep2[B] = 0; DFS(B, 0, dep2);
	for(int i = 1; i <= n; ++i) d[i] = max(dep1[i], dep2[i]);
	root = min_element(d + 1, d + n + 1) - d;
	read(q);
	while(q--) {
		read(lim); Ans = 0;
		now.clear(); now.pb(mp(-INF, 0));
		solve(root, 0);
		printf("%lld\n", Ans);
	}
	return 0;
}