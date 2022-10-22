//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, ans, cnt, a[MAXN];
int seg[MAXN * 50], ls[MAXN * 50], rs[MAXN * 50];
int root[MAXN], dfn[MAXN], dfncnt, buk[MAXN];
int bit[MAXN], siz[MAXN];
vec<int> G[MAXN], v;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void update(int &x, int l, int r, int p) {
	if(!x) x = ++cnt;
	seg[x]++;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) update(ls[x], l, mid, p);
	else update(rs[x], mid + 1, r, p);
}

int query(int x, int l, int r, int p) {
	if(l == r) return seg[x];
	int mid = (l + r) >> 1;
	if(p <= mid) return query(ls[x], l, mid, p);
	else return query(rs[x], mid + 1, r, p);
}

int merge(int a, int b, int l, int r) {
	if(!a || !b) return (a | b);
	seg[a] += seg[b];
	if(l == r) return a;
	int mid = (l + r) >> 1;
	ls[a] = merge(ls[a], ls[b], l, mid);
	rs[a] = merge(rs[a], rs[b], mid + 1, r);
	return a;
}

void add(int x, int v) {
	for(; x <= n; x += lowbit(x))
		bit[x] += v;
}

int ask(int x) { 
	int res = 0;
	for(; x; x -= lowbit(x)) res += bit[x];
	return res;
}

void tag(int l, int r) {
	if(l > r) return;
	add(l, 1); add(r + 1, -1);
}

void son(int x) {
	tag(dfn[x], dfn[x] + siz[x] - 1);
}

int qq(int x) { 
	return (ask(dfn[x]) == 0);
}

void DFS(int x, int f) {
	dfn[x] = ++dfncnt;
	siz[x] = 1;
	for(auto to : G[x]) {
		if(to == f) continue;
		DFS(to, x);
		siz[x] += siz[to];
	}
}

void solve(int x, int f) {
	update(root[x], 1, n, a[x]);
	int c;
	for(auto to : G[x]) {
		if(to == f) continue;
		solve(to, x);
		c = query(root[to], 1, n, a[x]);
		if(c) {
			tag(1, dfn[to] - 1);
			tag(dfn[to] + siz[to], n);
		}
		root[x] = merge(root[x], root[to], 1, n);
	}
	c = query(root[x], 1, n, a[x]);
	if(buk[a[x]] > c) son(x);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	for(int i = 1; i <= n; ++i)
		buk[a[i]]++;
	for(int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		G[x].pb(y); G[y].pb(x);
	}
	DFS(1, 0);
	solve(1, 0);
	for(int i = 1; i <= n; ++i) {
		ans += qq(i);
		//if(qq(i)) cerr << i << endl;
	}
	cout << ans << endl;
	return 0;
}