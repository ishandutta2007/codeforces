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

int n, m, p, k;
int a[MAXN], tag[MAXN << 2];
vec<pii> sum[MAXN << 2], Ans;
bool vis[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

vec<pii> merge(vec<pii> &a, vec<pii> &b) {
	static vec<pii> v, tmp; v = a; tmp.clear();
	for(auto y : b) {
		bool ok = false;
		for(auto &x : v)
			if(x.fst == y.fst) {x.scd += y.scd; ok = true; break;}
		if(!ok) tmp.pb(y);
	}
	for(auto x : tmp) v.pb(x);
	while(v.size() >= k) {
		int mn = INF; tmp.clear();
		for(int i = 0; i < k; ++i) mn = min(mn, v[i].scd);
		for(int i = 0; i < k; ++i) v[i].scd -= mn;
		for(int i = 0; i < v.size(); ++i) 
			if(v[i].scd) tmp.pb(v[i]);
		v = tmp;
	}
	return v;
}

void pushup(int x) {sum[x] = merge(sum[x << 1], sum[x << 1 | 1]);}

void build(int x, int l, int r) {
	if(l == r) return sum[x].pb(mp(a[l], 1)), void();
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	pushup(x);
}

void make(int x, int l, int r, int v) {
	sum[x].clear(); tag[x] = v;
	sum[x].pb(mp(v, r - l + 1));
}

void pushdown(int x, int l, int r) {
	if(!tag[x]) return;
	int mid = (l + r) >> 1;
	make(x << 1, l, mid, tag[x]), make(x << 1 | 1, mid + 1, r, tag[x]);
	tag[x] = 0;
}

void update(int x, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) return make(x, l, r, v), void();
	int mid = (l + r) >> 1; pushdown(x, l, r);
	if(L <= mid) update(x << 1, l, mid, L, R, v);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	pushup(x);
}

void query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return Ans = merge(Ans, sum[x]), void();
	int mid = (l + r) >> 1; pushdown(x, l, r);
	if(L <= mid) query(x << 1, l, mid, L, R);
	if(R > mid) query(x << 1 | 1, mid + 1, r, L, R);
}

void solve() {
	int opt, l, r, x; read(opt), read(l), read(r);
	if(opt == 1) read(x), update(1, 1, n, l, r, x);
	if(opt == 2) {
		Ans.clear(); query(1, 1, n, l, r);
		printf("%ld ", Ans.size());
		for(auto x : Ans) printf("%d ", x.fst);
		putchar('\n');
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(p); k = 100 / p + 1;
	for(int i = 1; i <= n; ++i) read(a[i]);
	build(1, 1, n);
	while(m--) solve();
	return 0;
}